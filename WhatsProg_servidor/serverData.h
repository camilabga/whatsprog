#ifndef SERVER_DATA_H
#define SERVER_DATA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdint.h>
#include "whatsprogData.h"
#include "winsocket.h"

using namespace std;

#define MAX_TIME 1000
#define TIME_SEND_LOGIN 1000

class User{
    private:
        string login;
        string password;
        tcp_winsocket s;
        list <Message> conversations; // organizar por remetente

    public:
        inline User(): login(""),password(""), s() {}
        bool isLoginValid();
        bool isPasswordValid();

        inline void setLogin(const string &l){login = l;}
        inline void setPassword(const string s){password = s;}
        inline string getLogin(){return login;}
        inline string getPassword(){return password;}

        inline tcp_winsocket getSocket(){return s;}
        inline void setSocket(tcp_winsocket s){this->s = s;}


};

class Server{
private:
    list<User> users;
    list<User> clients;

    list<Message> buffer;

    tcp_winsocket_server server_socket;
    winsocket_queue connected_sockets;

    WINSOCKET_STATUS iResult;

public:
    void openConnection(WINSOCKET_STATUS iR);

    void statusThread(HANDLE tHandle);

    bool newUser(string login, string password, tcp_winsocket socket);
    bool isUserRepeated(User u);
    bool loginUser(string login, string password, tcp_winsocket socket);

    void checkConnectedClients();
    bool acceptSocket();
    void waitingActivity();
    void checkBuffer(User user);

    void sendCmd(CommandWhatsProg cmd, tcp_winsocket socket);
    void sendCmd(CommandWhatsProg cmd, int32_t param1, tcp_winsocket socket);
    bool sendCmd(CommandWhatsProg cmd, int32_t param1, string param2, string param3, tcp_winsocket socket);

    void cmd_new_msg(User user);
    void cmd_msg_read1(User user);
};

#endif // SERVER_DATA_H
