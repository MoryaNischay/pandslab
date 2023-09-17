#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    listen(server_socket, 5);

    socklen_t client_addr_len = sizeof(client_addr);

    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Received from client: %s", buffer);

        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
    close(server_socket);
    return 0;
}


Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        send(client_socket, buffer, strlen(buffer), 0);

        memset(buffer, 0, MAX_BUFFER_SIZE);
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Received from server: %s", buffer);
    }

    close(client_socket);
    return 0;
}
