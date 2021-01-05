#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *const str = "hello, world";
    char *a = memchr(str, 'e', strlen(str));
    printf("memchr result %p is %c\n", a, *a);
    char *b = memchr(str, 'u', strlen(str));
    printf("memchr result %p\n", b);

    char *c =rawmemchr(str,'\0');
    printf("rawmemchr result %p\t%c\n", c, *c);

    char *d =memrchr(str,'e',strlen(str));
    printf("memrchr result is %p\t%c\n",d,*d);    
 
    char *e = strchr(str,'e');
    printf("strchr result is %c\n", *e);
    char *f = strchr(str, '\0');
    printf("strchr \\0 result is %p\n",f);

    char *g = strchrnul(str, 'u');
    printf("strchrnul result is %p\n",g);

    char *str_result = strstr(str, "el");
    printf("strstr result is %s\n", str_result);

    char *str_case_result = strcasestr(str, "El");
    printf("strcasestr result is %s\n", str_case_result);

    char * mem_result= memmem(str,strlen(str),"l", 1);
    printf("memmem result is %s\n", mem_result);

    size_t index = strspn(str,"abcdefh");
    printf("strspn result is %ld\n",index);

    size_t index2 =strcspn(str,",.;");
    printf("strcspn result is %ld\n",index2);


    return 0;
}