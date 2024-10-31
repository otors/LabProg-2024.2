#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int x, n;

    // Coleta de Dados
    printf("Forneça o valor de x: ");
    scanf("%d", &x);

    printf("Forneça o valor de n: ");
    scanf("%d", &n);
    
    // Exibição do resultado, com a utilização de operação bit-a-bit
    printf("%d * 2^%d: %d\n", x, n, x << n);

    return 0;
}
