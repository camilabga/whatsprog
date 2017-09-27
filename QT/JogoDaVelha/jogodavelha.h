#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#include <QMainWindow>

namespace Ui {
class JogoDaVelha;
}

class JogoDaVelha : public QMainWindow
{
    Q_OBJECT

public:
    explicit JogoDaVelha(QWidget *parent = 0);
    ~JogoDaVelha();

private slots:
    void on_tabuleiro_clicked(const QModelIndex &index);

    void on_actionNovo_Jogo_triggered();

private:
    Ui::JogoDaVelha *ui;


    void exibe_tabuleiro();
    void exibe_jogadores();
};

#endif // JOGODAVELHA_H
