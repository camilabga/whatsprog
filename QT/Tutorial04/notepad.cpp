#include "notepad.h"
#include "ui_notepad.h"
#include "QFile"
#include "QFileDialog"
#include "QMessageBox"
#include "QTextStream"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_quitButton_clicked()
{
    QCoreApplication::quit();
}

void Notepad::on_actionSair_triggered()
{
    QCoreApplication::quit();
}

void Notepad::on_actionLer_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }

        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void Notepad::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!fileName.isEmpty()) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
    // error message
    } else {
    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();
    stream.flush();
    file.close();

    }
    }

}
