#ifndef WHATSPROGMAIN_H
#define WHATSPROGMAIN_H

#include <QMainWindow>
#include <QLabel>
#include "modelconversas.h"
#include "modelmensagens.h"
#include "logindialog.h"

namespace Ui {
class WhatsProgMain;
}

class WhatsProgMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit WhatsProgMain(QWidget *parent = 0);
    ~WhatsProgMain();
    void warning2(const QString janela, const QString msg);
private slots:
    void slotAtualizaBarraStatus();
    void slotAceitaUsuario(const string &IP, const string &login, const string &senha, bool novoUsuario );
    void on_actionNovo_triggered();
    void on_actionConectar_triggered();
    void on_actionDesconectar_triggered();
    void on_actionSair_triggered();
    void on_tableViewConversas_activated(const QModelIndex &index);
    void on_tableViewConversas_clicked(const QModelIndex &index);
    void on_lineEditMensagem_returnPressed();

    void on_actionNova_conversa_triggered();

signals:
    void conversasModificada();
    void numMsgConversaModificado(unsigned I);
    void mensagensModificada();
    void statusModificada();

private:
    Ui::WhatsProgMain *ui;

    ModelConversas *modelConversas;
    ModelMensagens *modelMensagens;

    QLabel *ipServidor;
    QLabel *nomeUsuario;
    QLabel *nomeConversa;

    LoginDialog *loginDialog;
};

//extern WhatsProgMain w;

#endif // WHATSPROGMAIN_H
