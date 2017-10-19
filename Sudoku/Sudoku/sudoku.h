#ifndef SUDOKU_H
#define SUDOKU_H
#include <stack>

#include <QMainWindow>
#include "sudoku2.h"

using namespace std;
namespace Ui {
class MainSudoku;
}

class MainSudoku : public QMainWindow{
    Q_OBJECT
public:
    explicit MainSudoku(QWidget *parent = 0);

    void desenha_tab(Sudoku s, int I=-1, int J=-1);

    ~MainSudoku();
private slots:
    void on_tabuleiro_cellClicked(int row, int column);

    void on_resolverbutton_clicked();

    void on_limparbutton_clicked();

    void on_actionSair_triggered();

    void on_actionNovo_Jogo_triggered();

private:
    Ui::MainSudoku *ui;
};

#endif // _SUDOKU_H_
