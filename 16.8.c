#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define PORT 5555
#define MESSAGE "Yow!!! Are we having fun yet?"
#define SERVERHOST "127.0.0.1"

void write_to_server(int filedes)
{
    int nbytes;

    nbytes = write(filedes, MESSAGE, strlen(MESSAGE) + 1);
    if (nbytes < 0)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }
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
    int sock;
    struct sockaddr_in servername;

    sock = socket(AF_INET, SOCK_STREAM,0);
    if(sock <0)
    {
        perror("socket (client)");
        exit(EXIT_FAILURE);
    }

    init_sockaddr(&servername, SERVERHOST, PORT);
    if (connect(sock, (struct sockaddr *)&servername,sizeof(servername)) < 0)
    {
        perror("connetc (client)");
        exit(EXIT_FAILURE);
    }

    write_to_server(sock);
    close(sock);
    

    return 0;
}