#include "serverData.h"

// Server Functions
void Server::openConnection(WINSOCKET_STATUS iR){
    if (iR != 0) {
        cerr << "WSAStartup failed: " << iR << endl;
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
    connected_sockets.clean();
    if (server_socket.accepting()){
        connected_sockets.include(server_socket);
        //cout << "prestou" << endl;
        for (list<User>::iterator it=users.begin(); it != users.end(); ++it){
            if ((*it).getSocket().connected()){
               // cout << (*it).getLogin() << " connected" << endl;
                connected_sockets.include((*it).getSocket());
            } else {
                (*it).getSocket().close();
            }
        }
    }

    WINSOCKET_STATUS iResult = connected_sockets.wait_read(MAX_TIME*1000);
    if (iResult==SOCKET_ERROR){
        cerr << "Erro na espera por alguma atividade\n";
        exit(1);
    }
}

bool Server::acceptSocket(){
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
              cerr << "Erro na leitura do codigo.\n";
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
                    //checar se tem msg no buffer
                } else {
                    cout << "nera p ta aq n migo" << endl;
                }
            }
        }
    }
}

void Server::waitingActivity(){
    int32_t cmd;
    for (list<User>::iterator it=users.begin(); it != users.end(); ++it){
        if ((*it).getSocket().connected() && connected_sockets.had_activity((*it).getSocket())){

            iResult = (*it).getSocket().read_int(cmd, TIME_SEND_LOGIN*1000);

            if (iResult == SOCKET_ERROR){
                cerr << "Erro na comunicacao \n";
                (*it).getSocket().shutdown();
            } else {
                switch (cmd) {
                    case CMD_NOVA_MSG:
                        cmd_new_msg((*it));                    
                    break;

                    case CMD_MSG_LIDA1:
                        cmd_msg_read1((*it));
                    break;

                    default:

                    break;
                }
            }
        }
    }
}

void Server::sendCmd(CommandWhatsProg cmd, tcp_winsocket socket){
    iResult = socket.write_int(cmd);
    if ( iResult == SOCKET_ERROR ) {
        cerr << "Problema ao enviar mensagem para o cliente " << endl;
        socket.shutdown();
    }
}

void Server::sendCmd(CommandWhatsProg cmd, int32_t param1, tcp_winsocket socket){
    iResult = socket.write_int(cmd);
    if ( iResult == SOCKET_ERROR ) {
        cerr << "Problema ao enviar mensagem para o cliente " << endl;
        socket.shutdown();
    } else {
        iResult = socket.write_int(param1);

        if ( iResult == SOCKET_ERROR ) {
            cerr << "Problema ao enviar mensagem para o cliente " << endl;
            socket.shutdown();
        }
    }
}

bool Server::sendCmd(CommandWhatsProg cmd, int32_t param1, string param2, string param3, tcp_winsocket socket){
    iResult = socket.write_int(cmd);
    if ( iResult == SOCKET_ERROR ) {
        cerr << "Problema ao enviar mensagem para o cliente " << endl;
        socket.shutdown();
    } else {
        iResult = socket.write_int(param1);

        if ( iResult == SOCKET_ERROR ) {
            cerr << "Problema ao enviar mensagem para o cliente " << endl;
            socket.shutdown();
        } else {
            iResult = socket.write_string(param2);

            if ( iResult == SOCKET_ERROR ) {
                cerr << "Problema ao enviar mensagem para o cliente " << endl;
                socket.shutdown();
            } else {
                iResult = socket.write_string(param3);

                if ( iResult == SOCKET_ERROR ) {
                    cerr << "Problema ao enviar mensagem para o cliente " << endl;
                    socket.shutdown();
                } else {
                    return true;
                }
            }
        }
    }

    return false;
}

void Server::cmd_new_msg(User user) {
    int32_t param1;
    string param2, param3;
    Message message;
    iResult = user.getSocket().read_int(param1, TIME_SEND_LOGIN*1000);

    if (iResult == SOCKET_ERROR){
        cerr << "Erro na comunicacao \n";
        user.getSocket().shutdown();
    } else{
        iResult = user.getSocket().read_string(param2, TIME_SEND_LOGIN*1000);
        
        if (iResult == SOCKET_ERROR){
            cerr << "Erro na comunicacao \n";
            user.getSocket().shutdown();
        } else {
            iResult = user.getSocket().read_string(param3, TIME_SEND_LOGIN*1000);
            if (iResult == SOCKET_ERROR){
                cerr << "Erro na comunicacao \n";
                user.getSocket().shutdown();
            } else {
                if (message.setSender(user.getLogin())) {
                    if (message.setId(param1)) {
                        for (list<Message>::iterator it=buffer.begin(); it != buffer.end(); ++it) {
                            if ((*it).getSender().compare(user.getLogin()) == 0) {
                                if ((*it).getId() == param1) {
                                    sendCmd(CMD_ID_INVALIDA, param1, user.getSocket());
                                    return ;
                                }
                            }
                        }

                        if (message.setReceiver(param2)) {
                            for (list<User>::iterator a=users.begin(); a != users.end(); ++a) {
                                if ((*a).getLogin().compare(param2) == 0) {
                                    if (message.setText(param3)) {
                                        message.setStatus(MSG_RECEBIDA);

                                        sendCmd(CMD_MSG_RECEBIDA, param1, user.getSocket());

                                        buffer.push_back(message);

                                        if((*a).getSocket().connected()){
                                            if (sendCmd(CMD_NOVA_MSG, param1, param2, param3, (*a).getSocket())) {
                                                message.setStatus(MSG_ENTREGUE);
                                                sendCmd(CMD_MSG_ENTREGUE, param1, user.getSocket());
                                            } else {
                                                return ;
                                            }
                                        }

                                    } else {
                                        sendCmd(CMD_MSG_INVALIDA, param1, user.getSocket());
                                        return ;
                                    }
                                }
                            }

                            sendCmd(CMD_USER_INVALIDO, param1, user.getSocket());

                        } else {
                            sendCmd(CMD_USER_INVALIDO, param1, user.getSocket());
                        }
                        
                    } else {
                        sendCmd(CMD_ID_INVALIDA, param1, user.getSocket());
                    }
                } else {
                    user.getSocket().shutdown();
                }
            }
        }
    }
}

void Server::cmd_msg_read1(User user){
    int32_t param1;
    string param2;
    
    iResult = user.getSocket().read_int(param1, TIME_SEND_LOGIN*1000);

    if (iResult == SOCKET_ERROR){
        cerr << "Erro na comunicacao \n";
        user.getSocket().shutdown();
    } else {
        iResult = user.getSocket().read_string(param2, TIME_SEND_LOGIN*1000);
        
        if (iResult == SOCKET_ERROR){
            cerr << "Erro na comunicacao \n";
            user.getSocket().shutdown();
        } else {
            for (list<Message>::iterator it=buffer.begin(); it != buffer.end(); ++it) {
                if((*it).getSender().compare(param2) == 0){
                    if ((*it).getId() == param1){
                        (*it).setStatus(MSG_LIDA);

                        for (list<User>::iterator a=users.begin(); a != users.end(); ++a) {
                            if ((*a).getLogin().compare(param2) == 0){
                                if((*a).getSocket().connected()){
                                    sendCmd(CMD_MSG_LIDA2, param1, (*a).getSocket());
                                    buffer.erase(it);
                                    return ;
                                }
                            }
                        }
                    }
                }
            }

            user.getSocket().shutdown();

        }
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
