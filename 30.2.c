#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

static uid_t euid, ruid;

void do_setuid(void)
{
    int status;

#ifdef _POSIX_SAVED_IDS
    status = setegid(euid);
#else
    status = setreuid(ruid, euid);
#endif
    if (status < 0)
    {
        fprintf(stderr, "Could't set uid.\n");
        exit(status);
    }
}

void undo_setuid(void)
{
    int status;

#ifdef _POSIX_SAVED_IDS
    status = seteuid(ruid);
#else
    status = setregid(euid, ruid);
#endif
    if (status < 0)
    {
        fprintf(stderr, "Could't set uid.\n");
        exit(status);
    }
}

int record_score(int score)
{
    FILE *stream;
    char *myname;
    do_setuid();
    stream = fopen("score.txt", "a");
    undo_setuid();
    if (stream)
    {
        myname = "demouser";
        if (score < 0)
            fprintf(stream, "%10s: Couldn't lift the caber.\n", myname);
        else
            fprintf(stream, "%10s: %d feet.\n", myname, score);
        fclose(stream);
        return 0;
    }
    else
        return -1;
}

int main(int argc, char *argv[])
{
    ruid = getuid();
    euid = geteuid();
    printf("ruid=%d euid=%d\n", ruid, euid);
    undo_setuid();

    int ret = record_score(10);
    if (ret == -1)
    {
        fprintf(stderr, "record_score error");
    }
    return 0;
}