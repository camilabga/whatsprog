#include "serverData.h"

// Server Functions
void Server::openConnection(WINSOCKET_STATUS iResult, tcp_winsocket_server server_socket){
    if (iResult != 0) {
        cerr << "WSAStartup failed: " << iResult << endl;
        exit(1);
    }

    if (server_socket.listen(DOOR) != SOCKET_OK) {
        cerr << "Nao foi possivel abrir o socket de controle\n";
        exit(1);
    }
}

void Server::statusThread(HANDLE tHandle){
    if (tHandle == NULL){
        cerr << "Problema na criacao da thread: " << GetLastError() << endl;
        exit(1);
    }
}

bool Server::isUserRepeated(User u){
    for (list<User>::iterator it=users.begin(); it != users.end(); ++it)
        if ((*it).getLogin().compare(u.getLogin()) == 0) return true;
    return false;
}

bool Server::newUser(string login, string password){
    User u;

    u.setLogin(login);
    u.setPassword(password);

    if (isUserRepeated(u) || !u.isLoginValid() || !u.isPasswordValid()){
        //envia mensagem erro
        return false;
    }

    // envia mensagem de ok
    users.push_back(u);
    return true;
}


// User Functions
bool User::isLoginValid(){
    if (login.size() < SIZE_MIN_LOGIN_USER || login.size() > SIZE_MAX_LOGIN_USER){
        return false;
    }

    return true;
}

bool User::isPasswordValid(){
    if (password.size() < SIZE_MIN_PASSWORD || password.size() > SIZE_MAX_PASSWORD)
        return false;

    return true;
}
