#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pgsize = getpagesize();
    printf("page size is %d bytes\n", pgsize);

    long pg_size = sysconf(_SC_PAGE_SIZE);
    printf("page size is %ld bytes\n", pg_size);

    long phys_pages = sysconf(_SC_PHYS_PAGES);
    printf("physical pages %ld - %ld bytes\n",
           phys_pages,
           phys_pages * pg_size);

    long avphys_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("available physical pages %ld - %ld bytes\n",
           avphys_pages,
           avphys_pages * pg_size);

    long nproc_conf = sysconf(_SC_NPROCESSORS_CONF);
    printf("%ld processors\n", nproc_conf);
    long nproc_online = sysconf(_SC_NPROCESSORS_ONLN);
    printf("%ld processors online\n", nproc_online);

    double loadavg[3];
    int ret = getloadavg(loadavg, 3);
    if (ret == -1)
    {
        perror("getloadavg error");
        return 1;
    }
    printf("1m %f \n5m %f \n15m %f\n",loadavg[0],loadavg[1],loadavg[2]);
    return 0;
}