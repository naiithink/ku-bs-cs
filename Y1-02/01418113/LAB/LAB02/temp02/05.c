#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A_str[5], B_str[5], C_str[5] ; //ทำไมต้อง[5]

        printf("Enter length of side A: ");
        fgets(A_str, 5, stdin);
        printf("Enter length of side B: ");
        fgets(B_str, 5, stdin);
        printf("Enter length of side C: ");
        fgets(C_str, 5, stdin);

        int A = atoi(A_str);
        int B = atoi(B_str);
        int C = atoi(C_str);
        
        if ( A == B && B == C) //A == C && B == A && B == C && C == A && C ==B 
        {
            printf("Triangle type is equilateral.");
        }
        else if (A + B <= C || A + C <= B || B + C <= A)
        {
            printf("Triangle type is invalid.");
        }
        else if ( A == B || B == C || C == A && A + B + C )
        {
            printf("Triangle type is isosceles.");
        }
        else if (A != B && B != C)
        {
            printf("Triangle type is scalene.");
        }
}