#include <iostream>
#include <fstream>
#include <string>
#include <curses.h>
#include "sudoku.h"

using namespace std;

// Imprime msg e espera que o usuario digite uma tecla
void espera_tecla(){
  initscr();
  cout << "Qualquer tecla para continuar: ";
  getch();
  cout << endl;
  endwin();
}

// Desenha as linhas dos tabuleiros direito e esquerdo
void desenha_moldura(bool inicial){

  int J = (inicial ? 29 : 1);

  // Muda para o modo de desenho de linhas

  for (unsigned i=7; i<=17; i++)
  {
    cout << "x       x       x       x";  // |   |   |   |
  }
  for (unsigned i=0; i<4; i++){
    cout << "lqqqqqqqwqqqqqqqwqqqqqqqk";  // -------------
    cout << "tqqqqqqqnqqqqqqqnqqqqqqqu";  // -------------
    cout << "tqqqqqqqnqqqqqqqnqqqqqqqu";  // -------------
    cout << "mqqqqqqqvqqqqqqqvqqqqqqqj";  // -------------
  }

  // Retorna para o modo normal

  // Imprime as etiquetas
  for (unsigned i=0; i<9; i++){
    cout << char('A'+i);
    cout << i+1;
  }
}

// Construtor (por default, cria Jogada que termina o jogo)
Jogada::Jogada(int I, int J, int V){
  if (I<0 || I>8) I=-1;
  if (J<0 || J>8) J=-1;
  if (V<0 || V>9) V=-1;
  i = I;
  j = J;
  v = V;
}

// Leh uma jogada do teclado
void Jogada::ler(){
  char tecla;

  
  cout << "Linha [A-I; R=Resolver; S=Sair]? ";
  do{
    tecla = toupper(getch());
  } while ((tecla<'A' || tecla>'I') && tecla!='R' && tecla!='S');
  cout << tecla << endl;
  if (tecla=='R'){
    // Resolver o problema
    i = j = v = 10;
    return;
  }
  if (tecla=='S'){
    // Sair do programa
    i = j = v = -1;
    return;
  }
  i = tecla-'A';  // De 0 a 8
  

  cout << "Coluna [1-9]? ";
  do{
    tecla = toupper(getch());
  } while (tecla<'1' || tecla>'9');
  cout << tecla << endl;
  j = tecla-'1';  // De 0 a 8
  

  
  cout << "Valor [1-9; 0=apagar]? ";
  do{
    tecla = toupper(getch());
    //aceitar_valor_zero_para_apagar();
  } while (tecla<'0' || tecla>'9');
  cout << tecla << endl;
  v = tecla-'0';  // De 0 a 9

  // Restaura as etiquetas normais
  
  cout << char('A'+i);
  cout << j+1;
  
}

// Testa se a jogada indica que o uruario quer resolver o jogo automaticamente
bool Jogada::resolver_jogo() const{
  return (i>8 || j>8 || v>9);
}

// Testa se a jogada indica que o uruario quer encerrar o jogo
bool Jogada::fim_de_jogo() const{
  return (i<0 || j<0 || v<0);
}

// Cria um tabuleiro com o conteudo do arquivo nome_arq
// Caso nao consiga ler do arquivo, cria tabuleiro vazip
Sudoku::Sudoku(const char *nome_arq){
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    x[i][j] = 0;
  }
  // Le o tabuleiro inicial de arquivo
  ifstream arq(nome_arq);
  if (!arq.is_open()) return;

  string prov;
  int valor;

  arq >> prov;
  if (prov != "SUDOKU") return;
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    arq >> valor;
    if (valor != 0)
    {
      Jogada J(i,j,valor);
      if (jogada_valida(J)) x[i][j] = valor;
    }
  }
  arq.close();
}

// Imprime o conteudo do tabuleiro na tela
// O parametro booleano de entrada "inicial" indica a posicao da impressao:
// true: lado direito da tela (tabuleiro inicial)
// false: lado esquerdo da tela (tabuleiro atual)
void Sudoku::imprimir(bool inicial) const{
  int J = (inicial ? 32 : 4);
  cout << (inicial ? "     TABULEIRO INICIAL" : "      TABULEIRO ATUAL") << endl;
  cout << "   1 2 3   4 5 6   7 8 9\n";
  cout << " +-------+-------+-------+\n";
  
  for (unsigned i=0; i<9; i++){
    cout << char('A'+i) << "| ";
    for (unsigned j=0; j<9; j++){
      if (x[i][j]>=1 && x[i][j]<=9) cout << int(x[i][j]);
      else cout << '-';
      cout << ' ';
      if (j%3 == 2) cout << "| ";
    }
    cout << endl;
  }
  cout << " +-------+-------+-------+\n";
}

// Testa se a jogada J eh possivel para o tabuleiro
bool Sudoku::jogada_valida(Jogada J) const{
  unsigned i,j;
  // Testar a jogada
  if (J.i<0 || J.i>8) return false;
  if (J.j<0 || J.j>8) return false;
  if (J.v<0 || J.v>9) return false;

  // Testar se a casa nao estah vazia
  if (x[J.i][J.j] != 0){
    // Soh pode apagar
    return (J.v == 0);
  }

  // Se chegou aqui, eh pq a casa estah vazia.
  // Portanto, nao pode apagar
  if (J.v == 0) return false;

  // Testar a linha
  for (i=0; i<9; i++){
    if (x[i][J.j] == J.v) return false;
  }
  // Testar a coluna
  for (j=0; j<9; j++){
    if (x[J.i][j] == J.v) return false;
  }
  // Testar o bloco
  unsigned iIni = 3*(J.i/3);
  unsigned jIni = 3*(J.j/3);
  for (i=0; i<3; i++) for (j=0; j<3; j++){
    if (x[iIni+i][jIni+j] == J.v) return false;
  }
  return true;
}

// Testa se o tabuleiro estah completo (fim de jogo)
bool Sudoku::fim_de_jogo() const{
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++){
    if (x[i][j] == 0) return false;
  }
  return true;
}

// Retorna o numero de casas vazias no tabuleiro
unsigned Sudoku::num_casas_vazias() const{
  unsigned N(0);
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++){
    if (x[i][j] == 0) N++;
  }
  return N;
}

// Determina automaticamente a solucao do tabuleiro (preenche as casas vazias)
void Sudoku::resolver(void){
  
  cout << "O resolvedor automatico ainda nao estah pronto!";
  espera_tecla();
}