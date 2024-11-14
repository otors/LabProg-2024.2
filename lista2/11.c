#include <stdio.h>

int main(int argc, char const *argv[])
{
    char count = 0; // Variavel de controle para o printf

    int a, b, start, finish;
    printf("Digite A: ");
    scanf("%d", &a);
    printf("Digite B: ");
    scanf("%d", &b);
    (a < b) ? (start = a, finish = b) : (start = b, finish = a);

    for (int i = start; i <= finish; i++) {
        if (!(i%4)) (!count ? printf("%d", i*i) : printf(", %d", i*i)), count++;
        if (i == finish) printf("\n");
    }
    
    return 0;
}
