#ifndef Sudoku_H
#define Sudoku_H
class Jogada{
private:
  int i,j,v;
public:
  // Construtor (por default, cria Jogada que termina o jogo)
  Jogada(int I=-1, int J=-1, int V=-1);
  // Leh uma jogada do teclado
  void ler();
  // Testa se a jogada indica que o uruario quer resolver o jogo automaticamente
  bool resolver_jogo() const;
  // Testa se a jogada indica que o uruario quer encerrar o jogo
  bool fim_de_jogo() const;

  friend class Sudoku;
};
class Sudoku{
public:
    // Cria um tabuleiro com o conteudo do arquivo nome_arq
    // Caso nao consiga ler do arquivo, cria tabuleiro vazio
    Sudoku(const char *nome_arq="facil.txt");
    // Imprime o conteudo do tabuleiro na tela
    // O parametro booleano de entrada "inicial" indica a posicao da impressao:
    // true: lado direito da tela (tabuleiro inicial)
    // false: lado esquerdo da tela (tabuleiro atual)
    void imprimir(bool inicial=false) const;
    // Testa se a jogada J eh possivel para o tabuleiro
    bool jogada_valida(Jogada J) const;
    // Executa uma jogada (altera o tabuleiro)
    inline void fazer_jogada(Jogada J) {if (jogada_valida(J)) x[J.i][J.j] = J.v;}
    // Testa se o tabuleiro estah completo (fim de jogo)
    bool fim_de_jogo() const;
    // Retorna o numero de casas vazias no tabuleiro
    unsigned num_casas_vazias() const;
    // Determina automaticamente a solucao do tabuleiro (preenche as casas vazias)
    int resolver(void);
    inline int get_x(int i, int j){return x[i][j];}
    inline void set_x(int i, int j, int v){x[i][j] = v;}
    // Matriz que contem os valores das casas do tabuleiro
    void reiniciar();

    void chagesourceFile(const char *nome_arq);


private:
    int x[9][9];

};

extern Sudoku S;
extern Sudoku Origem;
#endif // Sudoku_H
