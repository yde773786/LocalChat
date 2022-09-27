#include <sys/socket.h>
#include "connection.h"
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

/*
 * Returns the socket file descriptor. Negative
 * if error.
 */
int prepare_socket(char* ip_address){
    int socket_fd;

    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        return -1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(5000);

    if(inet_pton(AF_INET, ip_address, &address.sin_addr) <= 0){
        return -2;
    }

    if(connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        return -3;
    }

    return socket_fd;
}

/*
 * IPv4 dotted-decimal form
 */
int check_ip_format(char* ip_address){
    int is_valid = 1;

    if(strlen(ip_address) == 15){
        while(*ip_address != '\0'){
            if(*ip_address != '.' || (*ip_address - '0' < 0 || *ip_address > '9')){
                is_valid = 0;
            }
            ++*ip_address;
        }
    }
    else{
        is_valid = 0;
    }

    return is_valid;
}