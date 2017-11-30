#include "serverData.h"

using namespace std;

Server server;
tcp_winsocket_server server_socket;

DWORD WINAPI server_brain(LPVOID lpParameter){
    while (1) {
        server.checkConnectedClients();
        server.acceptSocket();
    }
}

int main () {
    WSADATA wsaData;

    WINSOCKET_STATUS iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    server.openConnection(iResult);

    HANDLE tHandle = CreateThread(NULL, 0, server_brain, NULL , 0, NULL);

    server.statusThread(tHandle);

    while (1) {
        //if (server.newUser("barbosa", "172723")) cout << "inseriu 1" << endl;
        //if (server.newUser("vantuil", "172723")) cout << "inseriu 2" << endl;
        //if (server.newUser("barbosa", "172723")) cout << "inseriu 3" << endl;
        //if (server.newUser("mpsdantas", "123456")) cout << "inseriu 4" << endl;
    }

    TerminateThread(tHandle,0);
    CloseHandle(tHandle);
    //server_socket.close();

    return 0;
}
