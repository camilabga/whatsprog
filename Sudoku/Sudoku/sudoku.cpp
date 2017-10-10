#include "sudoku.h"
#include "ui_sudoku.h"

#include <QTableWidgetItem>
#include <QTableWidget>
#include <QString>
#include <QFileDialog>
#include <QByteArray>

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "sudoku2.h"

using namespace std;

int cellx=-1, celly=-1;

MainSudoku::MainSudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSudoku)
{
    ui->setupUi(this);
    for(int i = 0;i<9;i++)for(int j = 0;j<9;j++){
        if(S.get_x(i, j)!=0)
            ui->tabuleiro->setItem(i,j,new QTableWidgetItem(QString::number(S.get_x(i, j))));
    }
    // ->setBackground(Qt::COR));

}

MainSudoku::~MainSudoku()
{
    delete ui;
}

Jogada::Jogada(int I, int J, int V){
    // Construtor (por default, cria Jogada que termina o jogo)
  if (I<0 || I>8) I=-1;
  if (J<0 || J>8) J=-1;
  if (V<0 || V>9) V=-1;
  i = I;
  j = J;
  v = V;
}

bool Jogada::resolver_jogo() const
{
    // Testa se a jogada indica que o uruario quer resolver o jogo automaticamente
  return (i>8 || j>8 || v>9);
}

bool Jogada::fim_de_jogo() const{
    // Testa se a jogada indica que o uruario quer encerrar o jogo
  return (i<0 || j<0 || v<0);
}

// Cria um tabuleiro com o conteudo do arquivo nome_arq
// Caso nao consiga ler do arquivo, cria tabuleiro vazip
Sudoku::Sudoku(const char *nome_arq)
{
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
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)  {
    arq >> valor;
    if (valor != 0)
    {
      Jogada J(i,j,valor);
      if (jogada_valida(J)) x[i][j] = valor;
    }
  }
  arq.close();
}

// Testa se a jogada J eh possivel para o tabuleiro
bool Sudoku::jogada_valida(Jogada J) const{
  unsigned i,j;
  // Testar a jogada
  if (J.i<0 || J.i>8) return false;
  if (J.j<0 || J.j>8) return false;
  if (J.v<0 || J.v>9) return false;

  // Testar se a casa nao estah vazia
  if (x[J.i][J.j] != 0)
  {
    return (J.v == 0);
  }

  // Se chegou aqui, eh pq a casa estah vazia.
  // Portanto, nao pode apagar
  if (J.v == 0) return false;

  // Testar a linha
  for (i=0; i<9; i++)
  {
    if (x[i][J.j] == J.v) return false;
  }
  // Testar a coluna
  for (j=0; j<9; j++)
  {
    if (x[J.i][j] == J.v) return false;
  }
  // Testar o bloco
  unsigned iIni = 3*(J.i/3);
  unsigned jIni = 3*(J.j/3);
  for (i=0; i<3; i++) for (j=0; j<3; j++)
  {
    if (x[iIni+i][jIni+j] == J.v) return false;
  }
  return true;
}

// Testa se o tabuleiro estah completo (fim de jogo)
bool Sudoku::fim_de_jogo() const{
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    if (x[i][j] == 0) return false;
  }
  return true;
}

// Retorna o numero de casas vazias no tabuleiro
unsigned Sudoku::num_casas_vazias() const{
  unsigned N(0);
  for (unsigned i=0; i<9; i++)
      for (unsigned j=0; j<9; j++)
          if (x[i][j] == 0) N++;

  return N;
}

// Determina automaticamente a solucao do tabuleiro (preenche as casas vazias)
int Sudoku::resolver(void){
  Sudoku S;
  stack<Sudoku> F;
  F.push(*this);//o primeiro da pilha recebe a origem
  int cont = 0;
  int i = 0, j = 0;
  do{
        S = F.top();
        F.pop();
        if(S.fim_de_jogo())
            return -1;
        while(S.x[i][j] != 0){//procura a proxima casa vazia no sudoku
            j++;
            if(j == 9){
                j = 0;
                i++;
            }
            if(i == 9)
                i = 0;
        }
        for(int v =1; v<10;v++){//faz os "filhos" do primeiro da pilha
            Jogada J(i,j,v);
            if(S.jogada_valida(J)){
                S.fazer_jogada(J);
                F.push(S);
                S.x[i][j] = 0;
                cont++;
            }
        }
        //cout << "ainda falta analizar: " << F.size() << endl;
        //cout << "iteracoes: " << cont << endl;
    }while(!F.top().fim_de_jogo());
    *this = F.top();
    return cont;
}

void Sudoku::reiniciar(){
for(int i = 0;i<9;i++)
    for(int j = 0;j<9;j++)
        S.set_x(i,j,Origem.get_x(i,j));
}

void MainSudoku::on_tabuleiro_cellClicked(int row, int column){
    celly = column;
    cellx = row;
    QString texto;
    texto.append("X: ");
    texto.append(QString::number(celly+1));
    texto.append(" Y: ");
    texto.append(QString::number(cellx+1));

    ui->coords->setText(texto);

}

void MainSudoku::on_resolverbutton_clicked()
{
    QString it;
    it.append("Iteracoes: ");
    it.append(QString::number(S.resolver()));
    ui->Iteracoes->setText(it);
    for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++)
            if(S.get_x(i,j)!=0)
                ui->tabuleiro->setItem(i,j,new QTableWidgetItem(QString::number(S.get_x(i, j))));
}

void MainSudoku::on_limparbutton_clicked()
{
    QString it;
    it.append("Iteracoes: 0");
    ui->Iteracoes->setText(it);
    S.reiniciar();
    for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++){
            if(S.get_x(i,j)!=0)
                ui->tabuleiro->setItem(i,j,new QTableWidgetItem(QString::number(S.get_x(i, j))));
            else
                ui->tabuleiro->setItem(i,j,new QTableWidgetItem(QString("")));
        }
}

void MainSudoku::on_actionSair_triggered()
{
    this->close();
}

void Sudoku::chagesourceFile(const char *nome_arq){
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
    for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)  {
      arq >> valor;
      if (valor != 0)
      {
        Jogada J(i,j,valor);
        if (jogada_valida(J)) x[i][j] = valor;
      }
    }
    arq.close();
}

void MainSudoku::on_actionNovo_Jogo_triggered(){
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open MainSudoku"), "/home/barbosa", tr("*.txt"));
    char *str;
    QByteArray ba;
    ba = fileName.toLatin1();
    str = ba.data();

    Origem.chagesourceFile(str);
    S.reiniciar();

    QString it;
    it.append("Iteracoes: 0");
    ui->Iteracoes->setText(it);
    S.reiniciar();
    for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++){
            if(S.get_x(i,j)!=0)
                ui->tabuleiro->setItem(i,j,new QTableWidgetItem(QString::number(S.get_x(i, j))));
            else
                ui->tabuleiro->setItem(i,j,new QTableWidgetItem(QString("")));
        }
}
