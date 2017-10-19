#include "sudoku.h"
#include <QApplication>
#include "sudoku2.h"

Sudoku S("../Sudoku/sudoku.txt");
Sudoku Origem("../Sudoku/sudoku.txt");
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainSudoku w;
    w.show();

    return a.exec();
}
