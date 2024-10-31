#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int x;

    // Coleta de Dados
    printf("Entre com um valor inteiro: ");
    scanf("%d", &x);

    // Exibição do resultado, com calculos no arg. da função 'printf'
    printf("O triplo: %d\n", x*3);
    printf("O quadrado: %d\n", x*x);
    printf("O meio: %.3f\n", (float)x/2);
    
    return 0;
}
