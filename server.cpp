#include <iostream>
#include <vector>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

vector<int> clients;

void broadcastMessage(string msg, int senderSocket) {
    for (int client : clients) {
        if (client != senderSocket) {
            send(client, msg.c_str(), msg.length(), 0);
        }
    }
}

void handleClient(int clientSocket) {
    char buffer[1024];

    while (true) {
        memset(buffer, 0, sizeof(buffer));

        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytesReceived <= 0) {
            cout << "Client disconnected." << endl;
            close(clientSocket);
            break;
        }

        string message(buffer);
        cout << message << endl;

        broadcastMessage(message, clientSocket);
    }
}

int main() {
    int serverSocket;
    struct sockaddr_in serverAddr;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    listen(serverSocket, 5);

    cout << "Server started on port 8080..." << endl;

    while (true) {
        int clientSocket;
        struct sockaddr_in clientAddr;
        socklen_t addrSize = sizeof(clientAddr);

        clientSocket = accept(serverSocket,
                              (struct sockaddr*)&clientAddr,
                              &addrSize);

        cout << "Client connected." << endl;

        clients.push_back(clientSocket);

        thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }

    close(serverSocket);
    return 0;
}
