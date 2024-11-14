#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, start, finish;
    printf("Digite A: ");
    scanf("%d", &a);
    printf("Digite B: ");
    scanf("%d", &b);
    (a < b) ? (start = a, finish = b) : (start = b, finish = a);

    int count = 0;
    for (int i = start; i <= finish; i++) {
        if (!(i%3)) count++;
    }

    printf("(#(N) | N ∈ [%d, %d], N%%3=0) = %d\n", start, finish, count);
    printf("Com N%%3=0 em [%d, %d], temos: #(N) = %d\n", start, finish, count);

    return 0;
}
