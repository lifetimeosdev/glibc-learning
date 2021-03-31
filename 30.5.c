#include <stdio.h>
#include <pwd.h>

void print_passwd(struct passwd *ent)
{
    puts("-------------------------------");
    printf(" login name is %s\n", ent->pw_name);
    printf(" password is %s\n", ent->pw_passwd);
    printf(" user id is %d\n", ent->pw_uid);
    printf(" gid is %d\n", ent->pw_gid);
    printf(" gecos is %s\n", ent->pw_gecos);
    printf(" home dir %s\n", ent->pw_dir);
    printf(" default shell %s\n", ent->pw_shell);
}

int main(int argc, char *argv[])
{
    struct passwd *ent = getpwuid(1000);
    print_passwd(ent);

    struct passwd result_buf;
    char buffer[1024];
    struct passwd *result;

    int ret = getpwuid_r(1000, &result_buf, buffer, sizeof(buffer), &result);
    if (ret == 0)
        print_passwd(&result_buf);

    ent = getpwnam("lab");
    print_passwd(ent);

    ret = getpwnam_r("lab", &result_buf, buffer, sizeof(buffer), &result);
    if (ret == 0)
        print_passwd(&result_buf);


    setpwent();
    while ( (ent = getpwent())!=NULL)
        print_passwd(ent);
    endpwent();
    return 0;
}
