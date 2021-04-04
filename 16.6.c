#include <stdio.h>
#include <netdb.h>

void print_protoent(struct protoent *ent)
{
    puts("----------------------");
    printf("protocol name is %s\n", ent->p_name);
    char **aliases = ent->p_aliases;
    while (*aliases)
        printf("protocol aliase is %s\n", *aliases++);

    printf("protocol number is %d\n", ent->p_proto);
}

int main(int argc, char *argv[])
{
    struct protoent *ent;
    ent = getprotobyname("tcp");
    print_protoent(ent);

    ent = getprotobynumber(6);
    print_protoent(ent);

    setprotoent(1);
    while (ent = getprotoent())
        print_protoent(ent);
    endprotoent();

    return 0;
}