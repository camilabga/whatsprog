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
        //cout << "prestou" << endl;
        for (list<User>::iterator it=users.begin(); it != users.end(); ++it){
            if ((*it).getSocket().connected()){
               // cout << (*it).getLogin() << " connected" << endl;
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
    WINSOCKET_STATUS iResult;
    int32_t cmd;
    string login, password;
    tcp_winsocket temp_socket;
    if (connected_sockets.had_activity(server_socket)){
        if (server_socket.accept(temp_socket) != SOCKET_OK){
            cerr << "Nao foi possivel estabelecer uma conexao\n";
            return false;
        } else {
            iResult = temp_socket.read_int(cmd,TIME_SEND_LOGIN*1000);
            if (iResult == SOCKET_ERROR){
              cerr << "Erro na leitura do nome de login de um cliente que se conectou.\n";
              temp_socket.close();
            } else {
                iResult = temp_socket.read_string(login,TIME_SEND_LOGIN*1000);
                if (iResult == SOCKET_ERROR){
                    cerr << "Erro na leitura do login de um cliente que se conectou.\n";
                    temp_socket.close();
                }

                iResult = temp_socket.read_string(password,TIME_SEND_LOGIN*1000);
                if (iResult == SOCKET_ERROR){
                    cerr << "Erro na leitura da senha de um cliente que se conectou.\n";
                    temp_socket.close();
                }

                if (cmd == CMD_NEW_USER) {
                    cout << login << " " << password << endl;
                    newUser(login, password, temp_socket);
                } else if (cmd == CMD_LOGIN_USER) {
                    cout << login << " " << password << endl;
                    loginUser(login, password, temp_socket);
                } else {
                    cout << "nera p ta aq n migo" << endl;
                }
            }
        }
    }
}

void Server::sendCmd(CommandWhatsProg cmd, tcp_winsocket socket){
    WINSOCKET_STATUS iResult;
    iResult = socket.write_int(cmd);
    if ( iResult == SOCKET_ERROR ) {
        cerr << "Problema ao enviar mensagem para o cliente " << endl;
        socket.shutdown();
    }
}

bool Server::isUserRepeated(User u){
    for (list<User>::iterator it=users.begin(); it != users.end(); ++it)
        if ((*it).getLogin().compare(u.getLogin()) == 0) return true;
    return false;
}

bool Server::newUser(string login, string password, tcp_winsocket socket){
    User u;

    u.setLogin(login);
    u.setPassword(password);

    if (isUserRepeated(u) || !u.isLoginValid() || !u.isPasswordValid()){
        sendCmd(CMD_LOGIN_INVALIDO, socket);
        return false;
    }

    u.setSocket(socket);
    users.push_back(u);
    cout << "+1 user" << endl;
    sendCmd(CMD_LOGIN_OK, socket);
    return true;
}

bool Server::loginUser(string login, string password, tcp_winsocket socket){
    cout << "tentando logar" << endl;
    for (list<User>::iterator it=users.begin(); it != users.end(); ++it){
        if ((*it).getLogin().compare(login) + (*it).getPassword().compare(password) == 0) {
            sendCmd(CMD_LOGIN_OK, socket);
            cout << login << " logou" << endl;
            return true;
        }
    }

    sendCmd(CMD_LOGIN_INVALIDO, socket);
    return false;
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