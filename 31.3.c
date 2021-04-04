#include <stdio.h>
#include <mntent.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = setmntent("/etc/mtab", "r");
    if (!fp)
    {
        perror("setmntent error");
        exit(1);
    }

    struct mntent *ent;
    while ((ent = getmntent(fp)))
    {
        printf("%s\n",ent->mnt_fsname);
        printf("%s\n",ent->mnt_dir);
        printf("%s\n",ent->mnt_type);
        printf("%s\n",ent->mnt_opts);
        printf("%d\n",ent->mnt_freq);
        printf("%d\n",ent->mnt_passno);
        printf("has opt nosuid? %s\n", hasmntopt(ent,MNTOPT_NOSUID));
        puts("--------------------------");
    }

    endmntent(fp);

    return 0;
}