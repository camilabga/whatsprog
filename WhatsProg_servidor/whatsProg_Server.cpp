#include "serverData.h"

using namespace std;

tcp_winsocket_server server_socket;

DWORD WINAPI servidor(LPVOID lpParameter){
    cout << "entrou na thread" << endl;
}

int main () {
    WSADATA wsaData;
    Server server;
    WINSOCKET_STATUS iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    server.openConnection(iResult, server_socket);

    HANDLE tHandle = CreateThread(NULL, 0, servidor, NULL , 0, NULL);

    server.statusThread(tHandle);

    while (1) {
        if (server.newUser("barbosa", "172723")) cout << "inseriu 1" << endl;
        if (server.newUser("vantuil", "172723")) cout << "inseriu 2" << endl;
        if (server.newUser("barbosa", "172723")) cout << "inseriu 3" << endl;
    }

    TerminateThread(tHandle,0);
    CloseHandle(tHandle);
    server_socket.close();

    return 0;
}
