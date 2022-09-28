#include <sys/socket.h>
#include "connection.h"
#include <netinet/in.h>
#include <string.h>

int prepare_socket(){
    int socketfd, commfd;
    struct sockaddr_in address;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1){
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(5000);
    address.sin_addr.s_addr = INADDR_ANY;

    if((bind(socketfd, (struct sockaddr *)&address, sizeof(address)) < 0)){
        return -2;
    }

    if(listen(socketfd, 5) != 0){
        return -3;
    }

    if((commfd = accept(socketfd, NULL, NULL)) < 0){
        return -4;
    }

    return commfd;
}