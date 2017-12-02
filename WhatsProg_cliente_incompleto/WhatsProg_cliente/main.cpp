#include <QApplication>

#include "whatsprogmain.h"
#include "dados_cliente.h"
#include "winsocket.h"
#include <windows.h>

// A variavel global que contem todas as msgs de todas as conversas
DadosCliente DCliente;

// O socket do cliente, a ser utilizado por todas as threas
tcp_winsocket s;

// O identificador da thread de leitura de dados do socket
HANDLE tHandle=NULL;
DWORD WINAPI le_msg(LPVOID lpParameter){
    cerr<<"asodka\n";
    while(1)
        while (s.connected()) {
            int32_t iMsg=1;
            cerr<<"okokokokokok\n";
            s.read_int(iMsg);
            cout<<iMsg<<endl;
            if(iMsg == CMD_NOVA_MSG){
                int32_t id;
                string usuario;
                string msg;
                s.read_int(id,100);
                s.read_string(usuario,100);
                s.read_string(msg,100);

                Mensagem M;
                M.setId(id);
                M.setRemetente(usuario);
                M.setTexto(msg);
                M.setDestinatario(DCliente.getMeuUsuario());

                bool tem_na_lista = 0;

                for(int i= 0;i<DCliente.size();i++){
                    if(usuario==DCliente[i].getCorrespondente()){
                        DCliente[i].insertMessage(M);
                        tem_na_lista = 1;
                        break;
                    }
                }
                if(!tem_na_lista){
                    DCliente.insertConversa(usuario);   // FALTA TRATAR ERRO
                    DCliente[DCliente.size()-1].insertMessage(M);
                }
            }
            /*if(iMsg == CMD_LOGIN_OK){
                DCliente.setServidorUsuario(IP,login);
            }*/

        }
  return 0;
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    WhatsProgMain w;
    tHandle = CreateThread(NULL, 0, le_msg, NULL , 0, NULL);// //////////////////////////////////////////////////////

    // All processes that call Winsock functions must first initialize the use of the Windows Sockets DLL (WSAStartup)
    // before making other Winsock functions calls
    // The MAKEWORD(2,2) parameter of WSAStartup makes a request for version 2.2 of Winsock on the system
    WSADATA wsaData;
    WINSOCKET_STATUS iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        cerr << "WSAStartup failed: " << iResult << endl;
        exit(1);
    }

    w.show();
    int result = a.exec();

    // Desliga o socket
    s.shutdown();

    // Espera pelo fim da thread de recepção (máximo de TIMEOUT_WHATSPROG segundos)
    if (tHandle != NULL)    {
        if (WaitForSingleObject(tHandle, 1000*TIMEOUT_WHATSPROG) == WAIT_TIMEOUT){
            // A funcao WaitForSingleObject saiu por timeout
            // Encerra na força bruta a thread de recepcao, pois ela nao terminou sozinha
            TerminateThread(tHandle,0);
        }
    }
    // Encerra o handle da thread
    CloseHandle(tHandle);

    // Enderra o socket
    s.close();

    /* call WSACleanup when done using the Winsock dll */
    WSACleanup();

    return result;
}
