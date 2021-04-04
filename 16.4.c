#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>

void print_hostent(struct hostent *ent)
{
    puts("----------");
    printf("host name is %s\n", ent->h_name);
    char **aliases = ent->h_aliases;
    while (*aliases != NULL)
    {
        printf("aliase is %s\n", *aliases);
        aliases++;
    }
    printf("addrtype is %d\n", ent->h_addrtype);
    char **addrs = ent->h_addr_list;
    while (*addrs != NULL)
    {
        char buf[64];
        const char *bufp = inet_ntop(AF_INET, *addrs, buf, 64);
        printf("addr is %s\n", bufp);
        addrs++;
    }
}

struct hostent *gethostname(char *host)
{
    struct hostent *hostbuf, *hp;
    size_t hstbuflen;
    char *tmphstbuf;
    int res;
    int herr;

    hostbuf = malloc(sizeof(struct hostent));
    hstbuflen = 1024;
    tmphstbuf = malloc(hstbuflen);
    while ((res = gethostbyname_r(host, hostbuf, tmphstbuf, hstbuflen, &hp, &herr)) == ERANGE)
    {
        hstbuflen *= 2;
        tmphstbuf = realloc(tmphstbuf, hstbuflen);
    }
    free(tmphstbuf);
    if (res || hp == NULL)
        return NULL;
    return hp;
}

int main(int argc, char *argv[])
{
    struct hostent *entp;
    entp = gethostbyname("localhost");
    print_hostent(entp);

    entp = gethostname("localhost");
    print_hostent(entp);

    struct in_addr addr;
    inet_pton(AF_INET, "127.0.0.1", &addr);
    entp = gethostbyaddr(&addr, sizeof(addr), AF_INET);
    print_hostent(entp);

    sethostent(1);
    while ((entp = gethostent()))
        print_hostent(entp);
    endhostent();

    return 0;
}