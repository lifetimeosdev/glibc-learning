#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    struct in_addr addr;
    inet_aton("127.0.0.1", &addr);
    printf("inet_aton addr is %d\n", addr.s_addr);

    in_addr_t network = inet_network("127.0.0.1");
    printf("inet_network network is %d\n", network);

    char *str = inet_ntoa(addr);
    printf("inet_ntoa addr is %s\n", str);

    addr = inet_makeaddr(network, 5);
    printf("inet_makeaddr is %d\n", addr.s_addr);

    inet_pton(AF_INET, "127.0.0.1", &addr);
    printf("inet_pton is %d\n", addr.s_addr);

    char buf[64];
    inet_ntop(AF_INET, &addr, buf, 64);
    printf("inet_ntop addr is %s\n", buf);

    return 0;
}