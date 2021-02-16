#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[256];
    char *wd = getcwd(buf, sizeof(buf));
    printf("current working directory is %s\n", wd);

    int ret = chdir("/");
    if (ret == -1){
        perror("chdir error");
        return 1;
    }

    wd = getcwd(buf, sizeof(buf));
    printf("current working directory is %s\n", wd);

    int fd = open("/tmp", O_RDONLY, 0644);
    ret = fchdir(fd);
    if(fd == -1){
        perror("fchdir error");
        return 1;
    }
    
    wd = getcwd(buf, sizeof(buf));
    printf("current working directory is %s\n", wd);

    return 0;
}