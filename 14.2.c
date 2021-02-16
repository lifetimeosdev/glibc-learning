#include <stdio.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    DIR *dirp = opendir("/tmp");
    if (dirp == NULL)
    {
        perror("opendir error");
        return 1;
    }
    int fd = dirfd(dirp);
    printf("dirfd = %d\n", fd);

    errno = 0;
    struct dirent *ent;

    while (errno == 0 && (ent = readdir(dirp)) != NULL)
    {
        printf("%s\n", ent->d_name);
    }
    int ret = closedir(dirp);
    printf("closedir return value is %d\n",ret);

    return 0;
}