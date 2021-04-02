#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(int argc, char *argv[])
{
    int ret;
    char hostname[1024];
    ret = gethostname(hostname, sizeof(hostname));
    printf("hostname is %s\n", hostname);

    long id = gethostid();
    printf("hostid is %ld\n", id);

    struct utsname info;
    uname(&info);
    printf("%s|%s|%s|%s|%s|%s",
           info.machine,
           info.nodename,
           info.release,
           info.sysname,
           info.version,
           info.__domainname);

    return 0;
}