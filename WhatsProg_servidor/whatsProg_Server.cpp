#include "serverData.h"

using namespace std;

Server server;
tcp_winsocket_server server_socket;

DWORD WINAPI server_brain(LPVOID lpParameter){
    cout << "Server Online" << endl;
    while (1) {
        server.checkConnectedClients();
        cout << "esperando" << endl;
        server.waitingActivity();
        cout << "procura novo user"<< endl;
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

    }

    TerminateThread(tHandle,0);
    CloseHandle(tHandle);
    server_socket.close();

    return 0;
}
