#include <sys/socket.h>
#include <stdio.h>
#include "connection.h"
#include <netinet/in.h>
#include <arpa/inet.h>

/*
 * Returns the socket file descriptor. Negative
 * if error.
 */
int prepare_socket(char* ip_address){
    int socket_fd;

    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Socket cannot be created");
        return -1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(5000);

    if(inet_pton(AF_INET, ip_address, &address.sin_addr) <= 0){
        printf("Could not assign socket to ip address \n");
        return -1;
    }

    if(connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        printf("Could not connect to server \n");
        return -1;
    }

    return socket_fd;
}