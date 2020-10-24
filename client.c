#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc , char *argv[])
{

    int sockfd, n;
    struct sockaddr_in addr;
    char date_str[80];

    if (argc != 3) {
        printf("Usage: %s <ip-address> <port> \n", argv[0]);
        return -1;
    }

    /* Create socket */
    sockfd = socket(AF_INET , SOCK_STREAM , 0);
    if (sockfd == -1) {
       perror("Could not create socket");
       return -1;
    }

    printf("Socket created fd: %d \n", sockfd);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    // Connect to remote server
    if (connect(sockfd, (struct sockaddr *)&addr , sizeof(addr)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    printf("Connected to server: %d \n", argv[1]);

    //Receive the date from the server
    if (read(sockfd, date_str, 80) < 0) {
        printf("Recv failed \n");
        close(sockfd);
        return -1;
    }

    printf("Date: %s \n", date_str);

    close(sockfd);

    return 0;

}
