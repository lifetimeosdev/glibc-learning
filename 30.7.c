#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    uid_t me;
    struct passwd *my_passwd;
    struct group *my_group;
    char **members;

    me = getuid();
    my_passwd = getpwuid(me);
    if (!my_passwd)
    {
        printf("Couldn't find out about user %d.\n", (int)me);
        exit(EXIT_FAILURE);
    }
    printf("I'm %s.\n", my_passwd->pw_gecos);
    printf("My login name is %s.\n", my_passwd->pw_name);
    printf("My uid is %d.\n", my_passwd->pw_uid);
    printf("My home directory is %s.\n", my_passwd->pw_dir);
    printf("My default shell is %s.\n", my_passwd->pw_shell);

    my_group = getgrgid(my_passwd->pw_gid);
    if (!my_group)
    {
        printf("Couldn't find out group %d.\n", my_passwd->pw_gid);
        exit(EXIT_FAILURE);
    }
    printf("My fefault group is %s (%d).\n", my_group->gr_name, my_group->gr_gid);
    printf("The members of this group are:\n");
    members = my_group->gr_mem;
    while (*members)
    {
        printf(" %s\n",*(members));
        members++;
    }
    return EXIT_SUCCESS;    

    return 0;
}