#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    float x;

    // Coleta de Dados
    printf("Entre com um valor: ");
    scanf("%f", &x);

    // Exibição do resultado
    printf("Valor recebido com uma casa decimal: %.1f\n", x);

    return 0;
}
