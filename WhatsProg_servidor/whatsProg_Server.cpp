#include "serverData.h"

using namespace std;

Server server;
tcp_winsocket_server server_socket;

DWORD WINAPI server_brain(LPVOID lpParameter){
    cout << "Server Online" << endl;
    while (1) {
        server.checkConnectedClients();
        server.waitingActivity();
        server.acceptSocket();
    }
}

int main () {
    WSADATA wsaData;

    WINSOCKET_STATUS iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    int stop;

    server.openConnection(iResult);

    HANDLE tHandle = CreateThread(NULL, 0, server_brain, NULL , 0, NULL);

    server.statusThread(tHandle);

    server.inicialize();

    while (1) {
        cin >> stop;
    }

    TerminateThread(tHandle,0);
    CloseHandle(tHandle);
    server_socket.close();
    WSACleanup();

    return 0;
}
