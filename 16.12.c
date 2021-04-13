#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SERVER "/tmp/serversocket"
#define CLIENT "/tmp/mysocket"
#define MAXMSG 512
#define MESSAGE "Yow!!! Are we having fun yet?"

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

    sock = make_named_socket(CLIENT);

    name.sun_family = AF_UNIX;
    strcpy(name.sun_path, SERVER);

    size = SUN_LEN(&name);

    nbytes = sendto(sock, MESSAGE, sizeof(MESSAGE), 0, (struct sockaddr *)&name, size);
    if (nbytes < 0)
    {
        perror("sendto(client)");
        exit(EXIT_FAILURE);
    }
    nbytes = recvfrom(sock, message, MAXMSG, 0, NULL, NULL);

    if (nbytes < 0)
    {
        perror("recfrom(client)");
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "Client: got message: %s\n", message);

    remove(CLIENT);
    close(sock);

    return 0;
}