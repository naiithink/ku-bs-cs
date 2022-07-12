#include <stdio.h>

struct vector {
    float x;
    float y;
    float z;
};

int main(void)
{
    struct vector u, v, uv;
    
    printf("Enter u: ");
    scanf("%f %f %f", &u.x, &u.y, &u.z);
    printf("Enter v: ");
    scanf("%f %f %f", &v.x, &v.y, &v.z);

    uv.x = u.y * v.z - u.z * v.y;
    uv.y = u.z * v.x - u.x * v.z;
    uv.z = u.x * v.y - u.y * v.x;
    
    printf("u x v = %.1f %.1f %.1f\n", uv.x, uv.y, uv.z);

    return 0;
}