#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int have_job_control(void)
{
#ifdef _POSIX_JOB_CONTROL
    return 1;
#else
    int value = sysconf(_SC_JOB_CONTROL);
    if (value < 0)
        exit(1);
    return 1;
#endif
}
char *get_default_path(void)
{
    size_t len = confstr(_CS_PATH, NULL, 0);
    char *buffer = (char *)malloc(len + 1);
    if (confstr(_CS_PATH, buffer,len+1) == 0){
        free(buffer);
        return NULL;
    }
    return buffer;
}

int main(int argc, char *argv[])
{
    int ret = have_job_control();
    printf("have job control %d\n", ret);

    long name_max = pathconf("/bin/ls", _PC_NAME_MAX);
    printf("name_max is %ld\n", name_max);
    long path_max = pathconf("/bin/ls", _PC_PATH_MAX);
    printf("path_max is %ld\n", path_max);
    long pipe_buf = pathconf("/bin/ls", _PC_PIPE_BUF);
    printf("pipe_buf is %ld\n", pipe_buf);

    char *buf = get_default_path();
    printf("buf is %s\n", buf);
    free(buf);

    return 0;
}