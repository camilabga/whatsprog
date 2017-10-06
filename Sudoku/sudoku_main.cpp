#include <iostream>
#include <cstdlib>
#include "console.h"
#include "sudoku.h"

using namespace std;

int main(void)
{
  Sudoku Origem,S;
  Jogada J;

  if (!Term.formatado())
  {
    cout << "Este terminal nao permite saida formatada! Executanto em modo simples...\n";
    espera_tecla();
  }

  if (Term.formatado())
  {
    Term.tela_alternativa();
    Term.clrscr();

    Term.modo_linhas();
    Term.cores(CONSOLE_BRIGHT_YELLOW, CONSOLE_DEFAULT);
    cout << " lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk \n";
    cout << " x                                                   x \n";
    cout << " mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj \n";
    Term.modo_texto();
    Term.gotoYX(2,3);
    Term.cores(CONSOLE_BRIGHT_BLACK, CONSOLE_BRIGHT_YELLOW);
    cout << "                      SUDOKU                       ";
    Term.cores(CONSOLE_BRIGHT_WHITE, CONSOLE_DEFAULT);
    Term.gotoYX(4,7);
    cout << "TABULEIRO ATUAL";
    Term.gotoYX(4,34);
    cout << "TABULEIRO INICIAL";
    Term.cores(CONSOLE_DEFAULT, CONSOLE_DEFAULT);

    desenha_moldura(true);
    desenha_moldura();
  }
  else
  {
    cout << " +-----------------------+\n";
    cout << " |         SUDOKU        |\n";
    cout << " +-----------------------+\n";
  }

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
    Term.gotoYX(20,16);
    Term.limpar_linha();
    Term.cores(CONSOLE_BRIGHT_GREEN, CONSOLE_DEFAULT);
    cout << "PARABENS! JOGO CONCLUIDO!\n";
    Term.cores(CONSOLE_DEFAULT, CONSOLE_DEFAULT);
    espera_tecla();
  }
  Term.tela_normal();
}
