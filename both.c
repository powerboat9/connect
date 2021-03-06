#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int startsWith(char[] s1, char[] s2) {
    return (memcmp(s1, s2, sizeof(s2)) == 0);
}

char *concat(s1, s2) {
    char *ret;
    ret = (char *) malloc(strlen(s1) + strlen(s2) + 1);
    return ret;
}

int connect(char[] address, char[] port) {
    struct addrinfo *info, flags;
    memset(&flags, 0, sizeof(flags));
    flags.ai_family = AF_UNSPEC;
    flags.ai_socktype = SOCKET_STREAM;
    getaddrinfo(address, port, &flags, &info);
    int socket = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
    connect(socket, info->ai_addr, info->ai_addrlen);
}

int provide(char[] port) {
    struct addrinfo *info, flags;
    memset(&flags, 0, sizeof(flags));
    flags.ai_family = AF_UNSPEC;
    flags.ai_socktype = SOCKET_STREAM;
    flags.ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, port, &flags, &info);
    int socket = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
    bind(socket, info->ai_addr, info->ai_addrlen);
    listen(socket, 5);
    return accept(socket, NULL, NULL);
}

int sendAll(int socket, char[] *msg) {
    int left = sizeof(msg);
    int sent = 0;
    int did;
    while (left > 0) {
        did = send(socket, msg + did, left, 0);
        if (did == -1) {
            break;
        }
        left -= did;
        sent += did;
    }
    return did==-1?0:1;
}

int recvAll(int socket, char[] *buffer, int bufferlen) {
    return recv(socket, buffer, bufferlen, MSG_WAITALL);
}

void main() {
    //
}
    
