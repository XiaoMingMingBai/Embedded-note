#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345
#define SERVER_ADDR "127.0.0.1"

int main() {
    // 创建socket对象
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("创建socket对象失败");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_addr.sin_port = htons(PORT);

    // 连接服务器
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("连接服务器失败");
        exit(EXIT_FAILURE);
    }

    // 接收服务器发送的欢迎消息
    char buffer[1024];
    int n = recv(client_socket, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("接收消息失败");
        exit(EXIT_FAILURE);
    } else {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // 发送消息给服务器
    while (1) {
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
            perror("向服务器发送消息失败");
            exit(EXIT_FAILURE);
        }
    }

    // 关闭客户端socket
    close(client_socket);

    return 0;
}
