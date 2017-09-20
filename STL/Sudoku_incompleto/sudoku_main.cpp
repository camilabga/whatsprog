#include <iostream>
#include <cstdlib>
#include "sudoku.h"

using namespace std;

int main(void)
{
  Sudoku Origem,S;
  Jogada J;

    
    cout << " lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk \n";
    cout << " x                                                   x \n";
    cout << " mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj \n";
    
    cout << "                      SUDOKU                       ";
    
    cout << "TABULEIRO ATUAL";
    
    cout << "TABULEIRO INICIAL";
    

    desenha_moldura(true);
    desenha_moldura();
  
  
  
    cout << " +-----------------------+\n";
    cout << " |         SUDOKU        |\n";
    cout << " +-----------------------+\n";
  

  Origem.imprimir(true);

  S = Origem;
  do
  {
    S.imprimir();
    do
    {
      J.ler();
    } while(!J.resolver_jogo() && !J.fim_de_jogo() && !S.jogada_valida(J));
    if (J.resolver_jogo())
    {
      S.imprimir(true);
      S.resolver();
      Origem.imprimir(true);
    }
    else
    {
      if (!J.fim_de_jogo()) S.fazer_jogada(J);
    }
  } while(!J.fim_de_jogo() && !S.fim_de_jogo());

  if (S.fim_de_jogo())
  {
    
    cout << "PARABENS! JOGO CONCLUIDO!\n";
    espera_tecla();
  }
}
