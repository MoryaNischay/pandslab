TCP CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    // Create socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect
    connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    // Chat loop
    while (1) {
        printf("Client: ");
        fgets(buffer, 1024, stdin);
        send(client_fd, buffer, strlen(buffer), 0);
        recv(client_fd, buffer, 1024, 0);
        printf("Server: %s\n", buffer);
    }
    close(client_fd);
    return 0;
}


// Server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[1024];

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    listen(server_fd, MAX_CLIENTS);
    addr_size = sizeof(new_addr);
    new_socket = accept(server_fd, (struct sockaddr *)&new_addr, &addr_size);

    // Chat loop
    while (1) {
        recv(new_socket, buffer, 1024, 0);
        printf("Client: %s\n", buffer);
        printf("Server: ");
        fgets(buffer, 1024, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);

    return 0;
}
