#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdint.h>
#include "whatsprogData.h"
#include "winsocket.h"

using namespace std;

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
};

class Server{
private:
    list<User> users;
    list<Message> buffer;

public:
    void openConnection(WINSOCKET_STATUS iResult, tcp_winsocket_server server_socket);

    void statusThread(HANDLE tHandle);

    bool newUser(string login, string password);
    bool isUserRepeated(User u);
};
