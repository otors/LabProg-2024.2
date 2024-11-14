#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, start, finish;
    printf("Digite A: ");
    scanf("%d", &a);
    printf("Digite B: ");
    scanf("%d", &b);
    (a < b) ? (start = a, finish = b) : (start = b, finish = a);
    
    long int sum = 0;
    for (int i = start; i <= finish; i++) {
        if(!(i%2)) sum += i;
    }

    printf("Com n%%2=0, n ∈ [%d, %d], temos: Σn = %ld\n", start, finish, sum);

    return 0;
}
