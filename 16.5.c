#include <stdio.h>
#include <netdb.h>

void print_servent(struct servent *ent)
{
    puts("----------------------");
    printf("service name is %s\n", ent->s_name);
    char **aliases = ent->s_aliases;
    while (*aliases)
        printf("service aliase is %s\n", *aliases++);

    printf("service port is %d\n", ntohs(ent->s_port));
    printf("service protocol is %s\n", ent->s_proto);
}

int main(int argc, char *argv[])
{
    struct servent *servent;
    servent = getservbyname("ssh", "tcp");
    print_servent(servent);

    servent = getservbyport(htons(22), "tcp");
    print_servent(servent);

    setservent(1);
    while (servent = getservent())
        print_servent(servent);
    endservent();

    return 0;
}