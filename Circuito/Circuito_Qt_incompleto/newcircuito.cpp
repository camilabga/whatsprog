#include "newcircuito.h"
#include "ui_newcircuito.h"
#include "maincircuito.h"
#include <QMessageBox>
#include "circuito_STL.h"

NewCircuito::NewCircuito(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCircuito)
{
    ui->setupUi(this);
}

NewCircuito::~NewCircuito()
{
    delete ui;
}

// Cria um novo circuito com as dimensoes especificadas pelo usuario
// Deve chamar a funcao apropriada da classe Circuito
void NewCircuito::on_NewCircuito_accepted()
{
    // Cria um novo circuito com os parametros digitados
    int numInputs, numOutputs, numPortas;
    numInputs = ui->spinNumIn->value();
    numOutputs = ui->spinNumOut->value();
    numPortas = ui->spinNumPortas->value();

    // O circuito deve ser criado usando a funcao apropriada da classe Circuito

    //Circuito temp(numInputs,numOutputs,numPortas);
    //C = &temp->clone();

    C.limpar();
    C.setNin(numInputs);
    C.setNout(numOutputs);
    C.setNportas(numPortas);

    // Provisoriamente, estamos apenas exibindo uma msg
/*    QMessageBox msgBox;
    msgBox.setText(QString("Cria circuito com %1 entradas, %2 saídas e %3 portas")
                   .arg(numInputs).arg(numOutputs).arg(numPortas));
    msgBox.exec();
*/
    // Depois do novo circuito criado, as tabelas devem ser redimensionadas
    ((MainCircuito*)parentWidget())->redimensiona_tabelas();
}
