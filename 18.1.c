#include <syslog.h>

int main(int argc, char *argv[])
{
    openlog("my a.out", LOG_PERROR | LOG_CONS | LOG_PID, LOG_USER);

    int ret = setlogmask(LOG_MASK(LOG_DEBUG));

    syslog(LOG_MAKEPRI(LOG_USER , LOG_INFO), "hello world");
    
    closelog();

    return 0;
}