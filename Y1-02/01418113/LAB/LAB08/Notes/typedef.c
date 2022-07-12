#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int cm;

typedef struct
{
    char name[100];
    double score;
} Student;

int
swap(void *var0, void *var1);

int
main(void)
{
    // int length = 10;

    /*     
    cm length = 10;
    printf("%d\n", length);
    */

    Student *foo;
    Student *bar;

    char *name = "zoo";

    foo = (Student *)malloc(sizeof(Student));
    strcpy(foo->name, name);
    foo->score = 101;

    swap(foo, bar);

    printf("\
foo: %s\n\
bar: %s\n\
", foo->name, bar->name);

    free(foo);

    return 0;
}

int
swap(void *var0, void *var1)
{
    int ok = 0;
    void *temp;

    temp = ()malloc(sizeof(var0));

    if (temp == NULL)
        ok = 0;
    else
    {
        temp = var0;
        var0 = var1;
        var1 = temp;
        ok = 1;
    }

    free(temp);

    return ok;
}