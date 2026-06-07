//
// Created by goncalo on 04/06/26.
//


#include <signal.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    signal(SIGPIPE, SIG_IGN);
    int sockfd;
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);

    connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    char buf[1024];
    send(sockfd, "Hello, World! Its client", 24, 0);
    int n = recv(sockfd, buf, sizeof(buf),0);
    if (n>0) puts(buf);
    return 0;
}