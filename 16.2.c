#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int make_named_socket(const char *filename)
{
    struct sockaddr_un name;
    int sock;
    size_t size;

    sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, filename, sizeof(name.sun_path));
    name.sun_path[sizeof(name.sun_path) - 1] = '\0';
    size = (offsetof(struct sockaddr_un, sun_path) + strlen(name.sun_path));
    if (bind(sock, (struct sockaddr *)&name, size) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    return sock;
}

int main(int argc, char *argv[])
{
    make_named_socket("/tmp/aaaa.sock");
    return 0;
}