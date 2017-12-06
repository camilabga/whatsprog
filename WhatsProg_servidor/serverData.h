#ifndef SERVER_DATA_H
#define SERVER_DATA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdint.h>
#include "whatsprogData.h"
#include "winsocket.h"
#include <fstream>

using namespace std;

#define MAX_TIME 100
#define TIME_SEND_LOGIN 100

class User{
    private:
        string login;
        string password;
        tcp_winsocket s;

    public:
        inline User(): login(""),password(""), s() {}
        bool isLoginValid();
        bool isPasswordValid();

        inline void setLogin(const string &l){login = l;}
        inline void setPassword(const string s){password = s;}
        inline string getLogin(){return login;}
        inline string getPassword(){return password;}

        inline tcp_winsocket& getSocket(){return s;}
        inline void setSocket(const tcp_winsocket &s){this->s = s;}


};

class Server{
private:
    list<User> users;

    list<Message> buffer;

    tcp_winsocket_server server_socket;
    winsocket_queue connected_sockets;

    WINSOCKET_STATUS iResult;

public:
    void openConnection(WINSOCKET_STATUS iR);

    void statusThread(HANDLE tHandle);

    void inicialize();

    ostream &storeUsers();
    //ostream &storeBuffer(ostream &O);
    istream &getUsers(istream &I);

    bool newUser(string login, string password, tcp_winsocket &socket);
    bool isUserRepeated(User &u);
    bool loginUser(string login, string password, tcp_winsocket &socket);

    void checkConnectedClients();
    bool acceptSocket();
    void waitingActivity();
    void checkBuffer(User &user);

    void sendCmd(CommandWhatsProg cmd, tcp_winsocket &socket);
    void sendCmd(CommandWhatsProg cmd, int32_t param1, tcp_winsocket &socket);
    bool sendCmd(CommandWhatsProg cmd, int32_t param1, string param2, string param3, tcp_winsocket &socket);

    void cmd_new_msg(User &user);
    void cmd_msg_read1(User &user);
};

#endif // SERVER_DATA_H
