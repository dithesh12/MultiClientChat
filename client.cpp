#include <iostream>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

void receiveMessages(int sock) {
    char buffer[1024];

    while (true) {
        memset(buffer, 0, sizeof(buffer));

        int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);

        if (bytesReceived <= 0)
            break;

        cout << "\n" << buffer << endl;
    }
}

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    connect(clientSocket,
            (struct sockaddr*)&serverAddr,
            sizeof(serverAddr));

    cout << "Connected to server." << endl;

    thread receiver(receiveMessages, clientSocket);

    string message;

    while (true) {
        getline(cin, message);

        send(clientSocket,
             message.c_str(),
             message.length(),
             0);
    }

    receiver.join();

    close(clientSocket);
    return 0;
}
