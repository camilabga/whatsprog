#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdint.h>
#include "whatsprogData.h"
#include "winsocket.h"

class ServerData{
private:
    list<User> users;
    list<Message> buffer;
public:


};

class User{
    private:
        string login;
        string password;
        tcp_winsocket s;

    public:
        inline User(): login(""),password(""), s() {}
        
};