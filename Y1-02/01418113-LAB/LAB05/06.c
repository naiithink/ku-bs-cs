#include <stdio.h>

int main()
{
    int i, a[5],b[5],c[10] ;
    /* sec1 --- */
    printf("Enter array a:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Please enter an integer: ");
    /* sec1 ... */
        scanf ("%d",&a[i]);
    /* sec2 --- */
    }
    printf("Enter array b:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Please enter an integer: ");
    /* sec2 ... */
        scanf ("%d",&b[i]);
    /* sec3 --- */
    }
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            c[i] = a[i];
        else
            c[i] = b[i-5];
    }
    /* sec3 ... */
    printf ("Array c: ");
    for (i=0;i<10;i++)
        printf ("%d ",c[i]);

    printf ("\n");
    return 0;
}