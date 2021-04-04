#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>

struct buffer
{
    char *buf;
    int size;
    struct buffer *next;
};

struct buffer *read_oob(int socket)
{
    struct buffer *tail = 0;
    struct buffer *list = 0;

    while (1)
    {
#define BUF_SIZE 1024
        char *buf = (char *)malloc(BUF_SIZE);
        int success;
        int atmark;

        success = recv(socket, buf, BUF_SIZE, MSG_OOB);
        if (success >= 0)
        {
            struct buffer *link = (struct buffer *)malloc(sizeof(struct buffer));
            link->buf = buf;
            link->size = success;
            link->next = list;
            return link;
        }

        success = ioctl(socket, SIOCATMARK, &atmark);
        if (success < 0)
            perror("ioctl");
        if (atmark)
        {
            sleep(1);
            continue;
        }

        success = read(socket, buf, BUF_SIZE);
        if (success < 0)
            perror("read");

        {
            struct buffer *link = (struct buffer *)malloc(sizeof(struct buffer));
            link->buf = buf;
            link->size = success;
            if (tail)
                tail->next = link;
            else
                list = link;
            tail = link;
        }
    }
}

int main(int argc, char *argv[])
{
    return 0;
}