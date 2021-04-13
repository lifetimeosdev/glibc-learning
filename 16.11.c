#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SERVER "/tmp/serversocket"
#define MAXMSG 512

int make_named_socket(const char *filename)
{
    int sock;
    struct sockaddr_un name;
    size_t size;

    sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    name.sun_family = AF_UNIX;
    strcpy(name.sun_path, filename);
    name.sun_path[sizeof(name.sun_path) - 1] = '\0';

    size = SUN_LEN(&name);
    printf("sun_len is %d\n", size);
    if (bind(sock, (struct sockaddr *)&name, size) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    return sock;
}

int main(int argc, char *argv[])
{
    int sock;
    char message[MAXMSG];
    struct sockaddr_un name;
    socklen_t size;
    int nbytes;

    unlink(SERVER);
    sock = make_named_socket(SERVER);
    while (1)
    {
        size = sizeof(name);
        printf("sockaddr_un size is %d\n", size);
        nbytes = recvfrom(sock, message, MAXMSG, 0, (struct sockaddr *)&name, &size);

        if (nbytes < 0)
        {
            perror("recfrom(server)");
            exit(EXIT_FAILURE);
        }

        fprintf(stderr, "Server: got message: %s\n", message);
        nbytes = sendto(sock, message, nbytes, 0, (struct sockaddr *)&name, size);
        if (nbytes < 0)
        {
            perror("sendto(server)");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}