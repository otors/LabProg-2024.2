#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int x;

    // Coleta de Dados
    printf("Digite um valor inteiro: ");
    scanf("%d", &x);

    // Exibição do resultado
    printf("Quadrado de %d: %d\n", x, x*x); // Calculo feito no arg. da função 'printf'

    return 0;
}
