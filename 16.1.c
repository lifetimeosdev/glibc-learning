#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <net/if.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in addr;
    int sockfd;

    addr.sin_family = AF_INET;
    addr.sin_port = htonl(9999);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind error");
        return 1;
    }

    struct sockaddr_in out;
    socklen_t len;
    ret = getsockname(sockfd, (struct sockaddr *)&out, &len);
    if (ret == -1)
    {
        perror("getsockname error");
        return 2;
    }

    unsigned int idx = if_nametoindex("ens32");
    printf("ens32 index is %d\n", idx);

    struct if_nameindex *ni;
    ni = if_nameindex();
    if (ni == NULL || ni->if_index == 0)
        return 3;
    printf("index is %d, name is %s\n", ni->if_index, ni->if_name);
    if_freenameindex(ni);

    return 0;
}