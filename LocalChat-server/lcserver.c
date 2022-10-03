#include <stdio.h>
#include "connection.h"

int main(){
    int comm_fd = prepare_socket();

    if(comm_fd == -1){
        perror("Error");
        printf("Socket could be created");
    }
    else if(comm_fd == -2){
        perror("Error");
        printf("Socket could not be bound to fd");
    }
    else if(comm_fd == -3){
        perror("Error");
        printf("Socket could not listen for connections");
    }
    else if(comm_fd == -4){
        perror("Error");
        printf("Socket could not accept connections");
    }
    return 0;
}