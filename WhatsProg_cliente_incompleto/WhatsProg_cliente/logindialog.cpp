#include "logindialog.h"
#include "ui_logindialog.h"
#include "dadoswhatsprog.h"
#include "dados_cliente.h"
#include "winsocket.h"
#include <iostream>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    novoUsuario(false)
{
    ui->setupUi(this);

    ui->lineEditSenhaUsuario->setEchoMode( QLineEdit::Password );
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setUsuario(bool NovoUsuario){
    novoUsuario = NovoUsuario;
    setWindowTitle(novoUsuario ? "Usuário - Criar" : "Usuário - Conectar");
    ui->lineEditIpServidor->clear();
    ui->lineEditIpServidor->setText("192.168.0.23");
    ui->lineEditNomeUsuario->clear();
    ui->lineEditSenhaUsuario->clear();
    ui->lineEditNomeUsuario->setText("gabriel");
    ui->lineEditSenhaUsuario->setText("gabriel");
    show();
}

void LoginDialog::on_buttonBox_accepted()
{
    string IP = ui->lineEditIpServidor->text().toStdString();
    string login = ui->lineEditNomeUsuario->text().toStdString();
    string senha = ui->lineEditSenhaUsuario->text().toStdString();

    emit aceitaUsuario( IP, login, senha, novoUsuario );
}
void LoginDialog::aceitaUsuario(const string &IP, const string &login, const string &senha, bool novoUsuario){
    string msg;
    if(novoUsuario){
        if(!s.connected())
            s.connect(IP.c_str(), "23456");
        s.write_int(CMD_NEW_USER);
    }
    else{
        if(!s.connected())
            s.connect(IP.c_str(), "23456");
        s.write_int(CMD_LOGIN_USER);
    }
    s.write_string(login);
    s.write_string(senha);

    //DCliente.setTUDO(IP,login,senha);



    /*int32_t iMsg=1;
    if(!s.connected())
        iResult = s.read_int(iMsg);
    if(iMsg == CMD_LOGIN_OK){


    }
*/
    //slotAceitaUsuario(IP, login, senha, novoUsuario);
        //OK (mensagem?)
}
