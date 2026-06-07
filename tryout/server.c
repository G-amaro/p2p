#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <poll.h>
#include <signal.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>


#define PORT 8080
#define MAXCLIENTS 10

int main(void) {
    signal(SIGPIPE, SIG_IGN);
    int sockfd;
    char buf[1024];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);


    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(sockfd, 5);


    int clients_fd[MAXCLIENTS] = { 0 };

    int num_fds = 0;
    struct pollfd fds[MAXCLIENTS];
    fds[0].fd = sockfd;
    fds[0].events = POLLIN;
    num_fds ++;

    while (true) {
        poll(fds, num_fds, -1);
        if (fds[0].revents & POLLIN) {
            int newClient_fd = accept(fds[0].fd, NULL, NULL);
            if (newClient_fd==-1) {
                printf("error\n");

            }else if (num_fds < MAXCLIENTS){
                fds[num_fds].fd = newClient_fd;
                fds[num_fds].events =  POLLIN;
                num_fds ++;


            }

        }

        for (int i = 1; i < num_fds; i++) {
            if (fds[i].revents & POLLIN) {
                int n = recv(fds[i].fd, buf, sizeof(buf) - 1, 0);
                if (n <= 0) {
                    // cliente desligou-se
                    printf("cliente %d desligou-se\n", fds[i].fd);
                    close(fds[i].fd);
                    fds[i] = fds[num_fds - 1]; // substitui pelo último
                    num_fds--;
                } else {
                    buf[n] = '\0';
                    printf("cliente %d disse: %s\n", fds[i].fd, buf);
                }
            }
        }

    }


}
