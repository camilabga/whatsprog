#include "jogodavelha.h"
#include "jogovelha.h"
#include "ui_jogodavelha.h"
#include <QString>

JogoDaVelha::JogoDaVelha(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JogoDaVelha)
{
    ui->setupUi(this);
    JV.novo();
    exibe_jogadores();
}

JogoDaVelha::~JogoDaVelha()
{
    delete ui;
}

void JogoDaVelha::on_tabuleiro_clicked(const QModelIndex &index){
    if(ui->tabuleiro->item(index.row(), index.column()) == 0){
        ui->tabuleiro->setItem(index.row(), index.column(), new QTableWidgetItem("X"));
    }

    //ui->tabuleiro->setCellWidget(i,j, ______);
}

void JogoDaVelha::on_actionNovo_Jogo_triggered()
{
    JV.novo();
    exibe_jogadores();
}

void JogoDaVelha::exibe_jogadores(){
    ui->imagemVez->setText(QString(JV.vezDeQuem()));
}
