#include "serverData.h"

// Server Functions
void Server::openConnection(WINSOCKET_STATUS iResult){
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

void Server::checkConnectedClients(){
    WINSOCKET_STATUS iResult;

    connected_sockets.clean();
    if (server_socket.accepting()){
        connected_sockets.include(server_socket);
        cout << "prestou" << endl;
        for (list<User>::iterator it=users.begin(); it != users.end(); ++it){
            if ((*it).getSocket().connected()){
                cout << "+1 client" << endl;
                connected_sockets.include((*it).getSocket());
            }
        }
    }

    iResult = connected_sockets.wait_read(MAX_TIME*1000);
    if (iResult==SOCKET_ERROR){
        cerr << "Erro na espera por alguma atividade\n";
        exit(1);
    }
}

bool Server::acceptSocket(){
    tcp_winsocket temp_socket;
    if (connected_sockets.had_activity(server_socket)){
        if (server_socket.accept(temp_socket) != SOCKET_OK){
            cerr << "N�o foi poss�vel estabelecer uma conexao\n";
            return false;
        } else {
            cout << "alguem conectou" << endl;
        }
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


