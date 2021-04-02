#include <stdio.h>
#include <fstab.h>

void print_fstab(struct fstab *ent)
{
    if (ent != NULL)
    {
        puts("------------------");
        printf("%s\n", ent->fs_spec);
        printf("%s\n", ent->fs_file);
        printf("%s\n", ent->fs_vfstype);
        printf("%s\n", ent->fs_mntops);
        printf("%s\n", ent->fs_type);
        printf("%d\n", ent->fs_freq);
        printf("%d\n", ent->fs_passno);
    }
}

int main(int argc, char *argv[])
{
    setfsent();

    struct fstab *ent = getfsent();
    print_fstab(ent);
    ent = getfsspec("UUID=c81997af-4bd4-4e6e-8d2f-8194e604c69e");
    print_fstab(ent);
    ent = getfsfile("/");
    print_fstab(ent);

    endfsent();
    return 0;
}