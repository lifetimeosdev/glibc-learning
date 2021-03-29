#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    uid_t uid = getuid();
    printf("uid is %d\n", uid);

    gid_t gid = getgid();
    printf("gid is %d\n", gid);

    uid_t euid = geteuid();
    printf("euid is %d\n", euid);

    gid_t egid = getegid();
    printf("egid is %d\n", egid);

    int ngroups = getgroups(0, NULL);
    gid_t *groups = malloc(ngroups * sizeof(gid_t));
    int val = getgroups(ngroups, groups);
    gid_t *gp = groups;
    if (val < 0)
        printf("getgroups error");
    else
        for (int i = 0; i < ngroups; i++)
            printf("group is %d\n", *groups++);
    free(gp);

    return 0;
}