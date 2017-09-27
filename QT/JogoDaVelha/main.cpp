#include "jogodavelha.h"
#include "jogovelha.h"
#include <QApplication>

JogoVelha JV;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JogoDaVelha w;
    w.show();

    return a.exec();
}
