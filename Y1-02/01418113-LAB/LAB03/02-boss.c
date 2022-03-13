#include <stdio.h>
#include <stdlib.h>
int main(){
char n[10],m[10];
    gets(m);
    long long int M = atoll(m);

    gets(n);
    long long int N = atoll(n);

    while (M != 0 && N != 0){
        if (M == 0){
            break;
        }N -= (N/M) * M;
        if (N == 0){
            break;
        }M -= (M/N) * N;
    }

    unsigned long int GCD;
    if (N != 0){
        printf("GCD: %lld\n",N);
        GCD = N;
    }else{
        printf("GCD: %lld\n",M);
        GCD = M;
    }
    printf("LCM: %lld",(atoll(n) * atoll(m)) / GCD);
    return 0;
}