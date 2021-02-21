#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = tmpfile();

    char *tmp_name = tempnam(P_tmpdir, "aaaaa");
    printf("temp name is %s\n", tmp_name);
    free(tmp_name);

    char name[] = "/tmp/aaXXXXXX";
    tmp_name = mktemp(name);
    printf("temp name is %s\n", tmp_name);

    char name1[] = "/tmp/aaXXXXXX";
    int fd = mkstemp(name1);
    printf("mkstmp fd = %d\n", fd);

    char dir[] = "/tmp/aaXXXXXX";
    tmp_name = mkdtemp(dir);
    printf("dir name is %s\n", tmp_name);

    return 0;
}