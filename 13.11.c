#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void print_flock(struct flock *lock)
{
    printf("flock.l_pid=%d\n", lock->l_pid);
    printf("flock.l_type=%d\n", lock->l_type);
    printf("flock.l_whence=%d\n", lock->l_whence);
    printf("flock.l_start=%ld\n", lock->l_start);
    printf("flock.l_len=%ld\n", lock->l_len);
    printf("-----------------------\n");
}

int main(int argc, char *argv[])
{
    int fd = open("test.txt", O_RDWR, 0644);

    printf("fd=%d\n", fd);
    struct flock lock = {0};
    lock.l_type = F_WRLCK;
    print_flock(&lock);
    int ret = fcntl(fd, F_GETLK, &lock);
    if (ret == -1)
        perror("fcntl F_GETLK error");
    print_flock(&lock);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 3;
    lock.l_len = 2;
    print_flock(&lock);
    ret = fcntl(fd, F_SETLK, &lock);
    if (ret == -1)
        perror("fcntl F_SETLK error");
    print_flock(&lock);

    ret = fcntl(fd, F_SETLKW, &lock);
    if (ret == -1)
        perror("fcntl F_SETLKW error");
    print_flock(&lock);

    sleep(10);
    return 0;
}