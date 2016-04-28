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
    ret = (char *) malloc(strlen(s1) + strlen(s2) + 1)
    
