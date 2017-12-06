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

istream& Server::getUsers(istream &I){
    int n;
    string head, login, passw;
    getline(I, head, ' ');
    I >> n;
    User U;
    for(int i=0; i<n;i++){
        I.ignore(255,'\n');
        getline(I,login,',');
        U.setLogin(login);
        getline(I,passw,';');
        U.setPassword(passw);
        users.push_back(U);
    }
}

ostream& Server::storeUsers(){
    string file = "usuarios.txt";
    ofstream O(file.c_str());

    O << "USUARIOS " << users.size()<<"\n";
    for(list<User>::iterator i = users.begin(); i!=users.end(); i++){
        O << i->getLogin() << "," << i->getPassword() << ";\n";
    }
}

/*ostream& Server::storeBuffer(ostream &O){

}*/

void Server::inicialize(){
    string nome = "usuarios.txt";
    ifstream arq(nome.c_str());
    if (arq.is_open()){
        getUsers(arq);
    }
}

void Server::checkConnectedClients(){
    connected_sockets.clean();
    if (server_socket.accepting()){
        connected_sockets.include(server_socket);
        for (list<User>::iterator it=users.begin(); it != users.end(); ++it){
            if ((*it).getSocket().connected()){
               cout << (*it).getLogin() << " connected" << endl;
                connected_sockets.include((*it).getSocket());
            } else {
                (*it).getSocket().close();
            }
        }
    }

    iResult = connected_sockets.wait_read(MAX_TIME*1000);
    if (iResult==SOCKET_ERROR){
        cerr << "Erro na espera por alguma atividade\n";
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
            iResult = (*it).getSocket().read_int(cmd, MAX_TIME*1000);

            if (iResult != SOCKET_ERROR){
                switch (cmd) {
                    case CMD_NOVA_MSG:
                        cmd_new_msg((*it));
                    break;

                    case CMD_MSG_LIDA1:
                        cout << "recebeu cmd lida" << endl;
                        cmd_msg_read1((*it));
                    break;

                    case CMD_LOGOUT_USER:
                        (*it).getSocket().close();
                        cout << (*it).getLogin() << " logout" << endl;
                    break;

                    default:
                        (*it).getSocket().close();
                    break;
                }
            }
        }
    }
}

void Server::sendCmd(CommandWhatsProg cmd, tcp_winsocket &socket){
    iResult = socket.write_int(cmd);
    if ( iResult == SOCKET_ERROR ) {
        cerr << "Problema ao enviar mensagem para o cliente " << endl;
        socket.close();
    }
}

void Server::sendCmd(CommandWhatsProg cmd, int32_t param1, tcp_winsocket &socket){
    iResult = socket.write_int(cmd);
    if ( iResult == SOCKET_ERROR ) {
        cerr << "Problema ao enviar mensagem para o cliente " << endl;
        socket.close();
    } else {
        iResult = socket.write_int(param1);

        if ( iResult == SOCKET_ERROR ) {
            cerr << "Problema ao enviar mensagem para o cliente " << endl;
            socket.close();
        }
    }
}

bool Server::sendCmd(CommandWhatsProg cmd, int32_t param1, string param2, string param3, tcp_winsocket &socket){
    iResult = socket.write_int(cmd);
    if ( iResult == SOCKET_ERROR ) {
        cerr << "Problema ao enviar mensagem para o cliente " << endl;
        socket.close();
    } else {
        iResult = socket.write_int(param1);

        if ( iResult == SOCKET_ERROR ) {
            cerr << "Problema ao enviar mensagem para o cliente " << endl;
            socket.close();
        } else {
            iResult = socket.write_string(param2);

            if ( iResult == SOCKET_ERROR ) {
                cerr << "Problema ao enviar mensagem para o cliente " << endl;
                socket.close();
            } else {
                iResult = socket.write_string(param3);

                if ( iResult == SOCKET_ERROR ) {
                    cerr << "Problema ao enviar mensagem para o cliente " << endl;
                    socket.close();
                } else {
                    return true;
                }
            }
        }
    }

    return false;
}

void Server::checkBuffer(User &user){
    for (list<Message>::iterator it=buffer.begin(); it != buffer.end(); ++it) {
        if ((*it).getReceiver().compare(user.getLogin()) == 0){
            if ((*it).getStatus() == MSG_RECEBIDA) {
                if (sendCmd(CMD_NOVA_MSG, (*it).getId(), (*it).getSender(), (*it).getText(), user.getSocket())) {
                    it->setStatus(MSG_ENTREGUE);
                    sendCmd(CMD_MSG_ENTREGUE, it->getId(), (*it).getSender().getSocket());
                }
            }
        }
    }
}

void Server::cmd_new_msg(User &user) {
    int32_t param1;
    string param2, param3;
    Message message;
    iResult = user.getSocket().read_int(param1, TIME_SEND_LOGIN*1000);

    if (iResult == SOCKET_ERROR){
        cerr << "Erro na comunicacao \n";
        user.getSocket().close();
    } else{
        cout << "NOVA MSG" << endl;
        iResult = user.getSocket().read_string(param2, TIME_SEND_LOGIN*1000);

        cout << "para: " << param2 << endl;

        if (iResult == SOCKET_ERROR){
            cerr << "Erro na comunicacao \n";
            user.getSocket().close();
        } else {
            iResult = user.getSocket().read_string(param3, TIME_SEND_LOGIN*1000);
            if (iResult == SOCKET_ERROR){
                cerr << "Erro na comunicacao \n";
                user.getSocket().close();
            } else {
                cout << "mensagem: " << param3 << endl;
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
                                        cout << "enviou confirmacao recebimento msg" << endl;
                                        message.setStatus(MSG_RECEBIDA);

                                        sendCmd(CMD_MSG_RECEBIDA, param1, user.getSocket());

                                        if((*a).getSocket().connected()){
                                            if (sendCmd(CMD_NOVA_MSG, param1, message.getSender(), param3, (*a).getSocket())) {
                                                message.setStatus(MSG_ENTREGUE);
                                                buffer.push_back(message);
                                                cout << "enviando msg entregue" << endl;
                                                sendCmd(CMD_MSG_ENTREGUE, param1, user.getSocket());
                                            } else {
                                                buffer.push_back(message);
                                                return ;
                                            }
                                        } else {
                                            buffer.push_back(message);
                                        }

                                    } else {
                                        sendCmd(CMD_MSG_INVALIDA, param1, user.getSocket());
                                        return ;
                                    }
                                }
                            }

                            //sendCmd(CMD_USER_INVALIDO, param1, user.getSocket());

                        } else {
                            sendCmd(CMD_USER_INVALIDO, param1, user.getSocket());
                        }

                    } else {
                        sendCmd(CMD_ID_INVALIDA, param1, user.getSocket());
                    }
                } else {
                    user.getSocket().close();
                }
            }
        }
    }
}

void Server::cmd_msg_read1(User &user){
    int32_t param1;
    string param2;

    iResult = user.getSocket().read_int(param1, TIME_SEND_LOGIN*1000);

    if (iResult == SOCKET_ERROR){
        cerr << "Erro na comunicacao \n";
        user.getSocket().close();
    } else {
        iResult = user.getSocket().read_string(param2, TIME_SEND_LOGIN*1000);

        if (iResult == SOCKET_ERROR){
            cerr << "Erro na comunicacao \n";
            user.getSocket().close();
        } else {
            for (list<Message>::iterator it=buffer.begin(); it != buffer.end(); ++it) {
                if((*it).getSender().compare(param2) == 0){
                    if ((*it).getId() == param1){
                        (*it).setStatus(MSG_LIDA);

                        for (list<User>::iterator a=users.begin(); a != users.end(); ++a) {
                            if ((*a).getLogin().compare(param2) == 0){
                                if((*a).getSocket().connected()){
                                    cout << "enviou comando de lida" << endl;
                                    sendCmd(CMD_MSG_LIDA2, param1, (*a).getSocket());
                                    buffer.erase(it);
                                    return ;
                                }
                            }
                        }
                    }
                }
            }

            user.getSocket().close();

        }
    }

}

bool Server::isUserRepeated(User &u){
    for (list<User>::iterator it=users.begin(); it != users.end(); ++it)
        if ((*it).getLogin().compare(u.getLogin()) == 0) return true;
    return false;
}

bool Server::newUser(string login, string password, tcp_winsocket &socket){
    User u;
    u.setLogin(login);
    u.setPassword(password);

    if (isUserRepeated(u) || !u.isLoginValid() || !u.isPasswordValid()){
        sendCmd(CMD_LOGIN_INVALIDO, socket);
        return false;
    }

    u.setSocket(socket);
    users.push_back(u);
    storeUsers();
    cout << "+1 user" << endl;
    sendCmd(CMD_LOGIN_OK, socket);
    return true;
}

bool Server::loginUser(string login, string password, tcp_winsocket &socket){
    for (list<User>::iterator it=users.begin(); it != users.end(); ++it){
        if (it->getLogin().compare(login) + it->getPassword().compare(password) == 0) {
            it->setSocket(socket);

            cout << "logou" << endl;

            sendCmd(CMD_LOGIN_OK, socket);

            checkBuffer((*it));

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
