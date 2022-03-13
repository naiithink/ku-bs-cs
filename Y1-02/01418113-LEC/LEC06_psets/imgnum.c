#include <stdio.h>

struct complex_number {
    float real;
    float imaginary;
};

int main(void) {
    struct complex_number n1 = { 0.8, 1.1 };
    struct complex_number n2;
    n2 = n1;

    printf("n1: %.1f, %.1f\n", n1.real, n1.imaginary);
    printf("n2: %.1f, %.1f\n", n2.real, n2.imaginary);

    n1.real = 10;
    
    printf("n1: %.1f, %.1f\n", n1.real, n1.imaginary);
    printf("n2: %.1f, %.1f\n", n2.real, n2.imaginary);

    return 0;
}