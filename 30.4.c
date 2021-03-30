#include <stdio.h>
#include <utmp.h>

int main(int argc, char *argv[])
{
    struct utmp *ent;
    setutent();
    while ((ent = getutent()) != NULL)
    {
        printf("login type: %d\n", ent->ut_type);
        printf("login process ID: %d\n", ent->ut_pid);
        printf("device name: %s\n", ent->ut_line);
        printf("inittab ID: %s\n", ent->ut_id);
        printf("user login name: %s\n", ent->ut_user);
        printf("host from: %s\n", ent->ut_host);
        printf("session ID: %d\n", ent->ut_session);
        printf("time entry: %ds\n", ent->ut_tv.tv_sec);
    }
    endutent();

    int ret = utmpname("/tmp/abc.utmp");
    printf("utmpname return value is %d\n",ret);
     return 0;
}