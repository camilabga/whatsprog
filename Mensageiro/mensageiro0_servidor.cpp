#include <iostream>
#include <string.h>
#include <cstdio>

#include "winsocket.h"
#include "mensageiro.h"

using namespace std;

#define NUM_MAX_CONEX 30
#define TEMPO_MAXIMO 60  // Tempo m�ximo de espera em segundos

// Vari�veis globais das 2 threads
// Os sockets dos clientes
tcp_winsocket_server c;
tcp_winsocket s[NUM_MAX_CONEX];
int nconex=0;
bool fim = false;

// Fun��o auxiliar para enviar mensagem para todos os clientes
void envie_msg(int orig, string msg){
  WINSOCKET_STATUS iResult;

  for (int i=0; i<nconex; i++) if (i!=orig && s[i].connected()) {
    //cout << "Enviando para cliente " << i << endl;
    iResult = s[i].write_int(orig);
    if ( iResult == SOCKET_ERROR ) {
      cerr << "Problema ao enviar remetente para o cliente " << i << endl;
      s[i].shutdown();
    }
    else {
      iResult = s[i].write_string(msg);
      if ( iResult == SOCKET_ERROR ) {
        cerr << "Problema ao enviar mensagem para o cliente " << i << endl;
        s[i].shutdown();
      }
      else
      {
        //cout << "Mensagem enviada para o cliente " << i << endl;
      }
    }
  }
}

// Thread que efetivamente desempenha as tarefas do servidor
DWORD WINAPI servidor(LPVOID lpParameter){
  tcp_winsocket t;
  winsocket_queue f;
  WINSOCKET_STATUS iResult;

  string msg;
  int i;

  while (!fim)
  {
    f.clean();
    if (!(fim = !c.accepting()))
    {
      //cout << "Sockets: ";
      f.include(c);
      //cout << c << ' ';
      for (i=0; i<nconex; i++) {
	    if (s[i].connected()) {
	      f.include(s[i]);
	      //cout << s[i] << ' ';
	    }
      }
      //cout << endl;
    }

    //cout << f << endl;
    iResult = f.wait_read();
    //cout << f << endl;
    if (iResult==SOCKET_ERROR) {
      if (!fim) cerr << "Erro na espera por alguma atividade\n";
      fim = true;
    }
    if (!fim)
    {
      if (iResult!=0)
      {
        // N�o saiu por timeout: houve atividade em algum socket da fila
        // Testa em qual socket houve atividade. Primeiro os sockets dos clientes
        for (i=0; i<nconex; i++)
        {
            if (s[i].connected() && f.had_activity(s[i]))
            {
                iResult = s[i].read_string(msg);
                if (iResult == SOCKET_ERROR)
                {
                    cout << "Mensagem vazia recebida do cliente " << i << ". Desconectando\n";
                    s[i].shutdown();
                }
                else
                {
                    cout << "Mensagem recebida do cliente " << i << ":\n";
                    cout << msg << endl;
                    if (msg == "fim") {
                        cout << "Cliente " << i << " se desconectou\n";
                        s[i].shutdown();
                    }
                    else {
                        envie_msg(i,msg);
                    }
                }
            }
        }
        // Testa se houve atividade no socket de conexao
        if (f.had_activity(c))
        {
            if (c.accept(t) == SOCKET_OK)
            {
                cout << "Recebido novo pedido de conex�o\n";
            }
            else
            {
                cerr << "N�o foi poss�vel estabelecer uma conex�o\n";
                fim = true;
            }
            if (!fim) {
                if (nconex >= NUM_MAX_CONEX) {
                    cout << "N�mero m�ximo de conex�es atingido: conex�o rejeitada\n";
                    t.close();
                }
                else {
                    // Aloca pr�ximo socket livre para o novo cliente
                    s[nconex] = t;
                    cout << "Cliente " << i << " conectado no socket "
                         << s[nconex] << endl;
                    nconex++;
                }
            }
        }
      }
      else
      {
        // Saiu poe timeout: n�o houve atividade em nenhum socket da fila
        if (nconex == 0) {
            //cout << "Servidor inativo h� muito tempo...\n";
        }
      }
      // Elimina da lista de sockets as conexoes que foram fechadas porque houve
      // falha na comunicacao ou porque se desligaram
      for (int i=nconex-1; i>=0; i--)
      {
          if (!s[i].connected())
          {
            s[i].close();
            for (int j=i; j<nconex-1; j++) {
                s[j]=s[j+1];
            }
            nconex--;
          }
      }
    }
  }
  return 0;
}

int main(void){
  WSADATA wsaData;
  string msg;

  // All processes that call Winsock functions must first initialize the use of the Windows Sockets DLL (WSAStartup)
  // before making other Winsock functions calls
  // The MAKEWORD(2,2) parameter of WSAStartup makes a request for version 2.2 of Winsock on the system
  WINSOCKET_STATUS iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
  if (iResult != 0) {
      cerr << "WSAStartup failed: " << iResult << endl;
      exit(1);
  }

  if (c.listen(PORTA_TESTE,NUM_MAX_CONEX) != SOCKET_OK) {
    cerr << "N�o foi poss�vel abrir o socket de controle\n";
    exit(1);
  }

  // Cria a thread que recebe e reenvia as mensagens
  HANDLE tHandle = CreateThread(NULL, 0, servidor, NULL , 0, NULL);
  if (tHandle == NULL)
  {
    cerr << "Problema na cria��o da thread: " << GetLastError() << endl;
    exit(1);
  }
  
  while (!fim) {
    do{
      cout << "Mensagem para todos os clientes [max " << TAM_MAX_MSG_STRING << " caracteres, FIM para terminar]: ";
      cin >> ws;
      getline(cin,msg);
    } while (msg.size()==0 || msg.size()>TAM_MAX_MSG_STRING);
    if (!fim) fim = (msg=="FIM");
    envie_msg(-1,msg);
  }

  // Desliga os sockets
  cout << "Encerrando o socket de conexoes\n";
  c.shutdown();
  for (int i=0; i<nconex; i++)
  {
    cout << "Encerrando o socket do cliente " << i << endl;
      s[i].shutdown();
  }
  // Espera pelo fim da thread do servidor (m�ximo de 5 segundos)
  cout << "Aguardando o encerramento da outra thread...\n";
  WaitForSingleObject(tHandle, 5000);
  // Encerra na "for�a bruta" a thread do servidor caso ela n�o tenha terminado sozinha
  // (ou seja, a fun��o WaitForSingleObject tenha sa�do por timeout)
  TerminateThread(tHandle,0);
  // Encerra o handle da thread
  CloseHandle(tHandle);
  // Enderra o socket
  c.close();
  for (int i=0; i<nconex; i++) s[i].close();

  /* call WSACleanup when done using the Winsock dll */
  WSACleanup();
}
