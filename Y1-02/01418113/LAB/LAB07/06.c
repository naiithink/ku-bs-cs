#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *A, *B;

    A = (int *)malloc(sizeof(int) * 20);
    B = (int *)calloc(1, sizeof(int) * 20);

    for (int i = 0; i < 20; i++)
        A[i] = i + 1;

    for (int i = 0; i < 20; i++)
        printf("%d\n", A[i]);

    free(A);
    free(B);

    return 0;
}

// เขียนประโยคคำสั่งเพื่อทำการจองพื้นที่หน่วยความจำที่ทำการเก็บตัวแปรชนิดintขนาด20integersโดยหน่วยความจำดังกล่าวถูกชี้โดยpointerA
// เขียนประโยคคำสั่งเพื่อทำการจองพื้นที่หน่วยความจำที่ทำการเก็บตัวแปรชนิดintขนาด40byteโดยกำหนดให้ค่าเป็น0ของหน่วยความจำที่ชี้โดยpointerB
// ให้ทำการลดพื้นที่การจองในข้อ1เป็น10intergers
// ให้ทำการเพิ่มพื้นที่การจองในข้อ2เป็น15intergers

// ทำการเก็บตัวแปรชนิดintขนาด20integersโดยหน่วยความจำดังกล่าวถูกชี้โดยpointerA
// ทำการเก็บตัวแปรชนิดintขนาด40byteโดยกำหนดให้ค่าเป็น0ของหน่วยความจำที่ชี้โดยpointerB