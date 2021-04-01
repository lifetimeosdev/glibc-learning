#include <stdio.h>
#include <grp.h>

void print_grp(struct group *g)
{
    printf("--------------------------\n");
    printf("group id is %d\n", g->gr_gid);
    printf("group name is %s\n", g->gr_name);
    char **mem = g->gr_mem;
    while (*mem)
    {
        printf("mem contains %s\n", *mem);
        mem++;
    }
}

int main(int argc, char *argv[])
{
    struct group *grp;

    grp = getgrgid(27);
    print_grp(grp);
    grp = getgrnam("sudo");
    print_grp(grp);

    setgrent();
    while ((grp = getgrent()) != NULL)
    {
        print_grp(grp);
    }
    endgrent();

    return 0;
}