#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int x, n;
    printf("Forneça o valor de x: ");
    scanf("%d", &x);

    printf("Forneça o valor de n: ");
    scanf("%d", &n);
    
    printf("x * 2^n: %d\n", x << n);
    return 0;
}
