#ifndef WHATSPROG_DATA_H
#define WHATSPROG_DATA_H

#include <string>
#include <stdint.h>

using namespace std;

// Numero de bytes das informacoes a serem enviadas
#define SIZE_MIN_LOGIN_USER 6
#define SIZE_MAX_LOGIN_USER 12
#define SIZE_MIN_PASSWORD 6
#define SIZE_MAX_PASSWORD 12
#define SIZE_MAX_MSG 255

// Timeout (em segundos) para esperar o envio de um dado obrigatorio pelo socket
#define TIMEOUT_WHATSPROG 30

#define DOOR "23456"

// Os possiveis estados de uma mensagem
enum MsgStatus{
    MSG_ENVIADA=1,
    MSG_RECEBIDA=2,
    MSG_ENTREGUE=3,
    MSG_LIDA=4,
    MSG_INVALIDA=-1
};

// Os campos que compoem uma mensagem armazenada no cliente ou no servidor
class Message{
    private:
        // Identificador da mensagem
        int32_t id;
        // Nomes do sender e do receiver
        string sender;
        string receiver;
        // Text da mensagem
        string text;
        // Estado (status) da mensagem
        MsgStatus status;
    public:
        inline Message(): id(0), sender(""), receiver(""),
                        text(""), status(MSG_INVALIDA) {}
        // Funcoes de consulta/alteracao de parametros
        // As funcoes de alteracao retornam false em caso de erro, true se OK
        inline uint32_t getId() const {return id;}
        bool setId(uint32_t I);
        inline const string &getSender() const {return sender;}
        bool setSender(const string &R);
        inline const string &getReceiver() const {return receiver;}
        bool setReceiver(const string &D);
        inline const string &getText() const {return text;}
        bool setText(const string &T);
        inline MsgStatus getStatus() const {return status;}
        bool setStatus(MsgStatus S);

};

enum CommandWhatsProg{
    CMD_NEW_USER=1001,
    CMD_LOGIN_USER=1002,
    CMD_LOGIN_OK=1003,
    CMD_LOGIN_INVALIDO=1004,
    CMD_NOVA_MSG=1005,
    CMD_MSG_RECEBIDA=1006,
    CMD_MSG_ENTREGUE=1007,
    CMD_MSG_LIDA1=1008,
    CMD_MSG_LIDA2=1009,
    CMD_ID_INVALIDA=1010,
    CMD_USER_INVALIDO=1011,
    CMD_MSG_INVALIDA=1012,
    CMD_LOGOUT_USER=1013
};

#endif // WHATSPROG_DATA_H