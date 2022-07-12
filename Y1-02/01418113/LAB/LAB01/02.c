#include <stdio.h>
#include <stdlib.h>

// กำหนดค่าคงที่ PI มีค่า 22.0/7
#define PI 22.0/7

void main(void)
{
    float radius = 1.5;
    float volume = (4.0 / 3.0) * PI * (radius * radius * radius);
    printf("The volume of this sphere is %.2f\n", volume);
}