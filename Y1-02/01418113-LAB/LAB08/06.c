#include <stdio.h>

struct complex {
    float re;
    float im;
};

struct complex add_complex(struct complex C, struct complex D)
{
    struct complex res;

    res.re = C.re + D.re;
    res.im = C.im + D.im;

    return res;
}

struct complex multiply_complex(struct complex C, struct complex D)
{
    struct complex res;

    res.re = C.re * D.re - C.im * D.im;
    res.im = C.re * D.im + C.im * D.re;

    return res;
}

void print_complex(char *prompt, struct complex complex)
{
    printf("%s", prompt);

    if (!complex.re && !complex.im)
        printf("%.1f", 0.0);

    if (complex.re)
        printf("%.1f ", complex.re);
    if (complex.im)
    {
        if (complex.im < 0)
        {
            printf("- ");
            complex.im *= -1;
        }
        else if (complex.re)
            printf("+ ");
        printf("%.1fi", complex.im);
    }
    printf("\n");
}

int main()
{
    struct complex C, D, E, F;

    printf("Enter C: ");
    scanf("%f %f", &C.re, &C.im);
    printf("Enter D: ");
    scanf("%f %f", &D.re, &D.im);

    E = add_complex(C, D);
    F = multiply_complex(C, D); 

    print_complex("C + D = ", E);
    print_complex("C x D = ", F);

    return 0;
}