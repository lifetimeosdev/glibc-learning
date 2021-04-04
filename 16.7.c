#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int make_socket(uint16_t port)
{
    int sock;
    struct sockaddr_in name;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    return sock;
}

void init_sockaddr(struct sockaddr_in *name, const char *hostname, uint16_t port)
{
    struct hostent *hostinfo;
    name->sin_family = AF_INET;
    name->sin_port = htons(port);
    hostinfo = gethostbyname(hostname);
    if (!hostname)
    {
        fprintf(stderr, "Unknown host %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    name->sin_addr.s_addr = *(in_addr_t *)hostinfo->h_addr;
}

int main(int argc, char *argv[])
{
    make_socket(7777);
    struct sockaddr_in addr;
    init_sockaddr(&addr, "localhost", 7777);
    return 0;
}