#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct critter
{
    const char *name;
    const char *species;
};

struct critter muppets[] =
    {
        {"Kermint", "frog"},
        {"Piggy", "pig"},
        {"Gonzo", "whatever"},
        {"Fozzie", "bear"},
        {"Sam", "eagle"},
        {"Robin", "frog"},
        {"Animal", "animal"},
        {"Camilla", "chicken"},
        {"Sweetums", "monster"},
        {"Dr. Strangepork", "pig"},
        {"Link Hogthrob", "pig"},
        {"Zoot", "human"},
        {"Dr. Bunsen Honeydew", "human"},
        {"Beaker", "human"},
        {"Swedish Chef", "human"}};

int count = sizeof(muppets) / sizeof(struct critter);

int critter_cmp(const void *v1, const void *v2)
{
    const struct critter *c1 = v1;
    const struct critter *c2 = v2;
    return strcmp(c1->name, c2->name);
}

int print_critter(const struct critter *c)
{
    printf("%s, the %s\n", c->name, c->species);
}

void find_critter(const char *name)
{
    struct critter target, *result;
    target.name = name;
    result = bsearch(&target, muppets, count, sizeof(struct critter), critter_cmp);
    if (result)
        print_critter(result);
    else
        printf("Couldn't find %s.\n", name);
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < count; i++)
        print_critter(&muppets[i]);
    printf("\n");

    qsort(muppets, count, sizeof(struct critter), critter_cmp);

    for (int i = 0; i < count; i++)
        print_critter(&muppets[i]);
    printf("\n");

    find_critter("Kermint");
    find_critter("Gonzo");
    find_critter("Janice");

    return 0;
}