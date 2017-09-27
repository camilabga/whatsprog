#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_horizontalSlider_actionTriggered(int action)
{
    /*int x = ui->horizontalSlider->value();
    ui->progressBar->setValue(x);*/
    connect(ui->horizontalSlider, SIGNAL (valueChanged(int)), ui->progressBar, SLOT (setValue(int)));
}
