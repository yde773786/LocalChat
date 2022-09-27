#include <stdio.h>
#include <string.h>
#include "connection.h"

int main(int argc, char* argv[]) {

    if(argc == 4 && (strcmp(argv[2], "-j") == 0 || strcmp(argv[2], "-c") == 0)){
        if(check_ip_format(argv[1])){
            prepare_socket(argv[1]);
        }
        else{
            printf("Ip-Address format: ddd.ddd.ddd.ddd");
        }
    }
    else{
        printf("Usage: localchat [SERVER IP] [OPTION] [ID]\n");
        printf("OPTIONS: -j to join a chat with entered id\n         -c to create a chat with entered id");
    }

}
