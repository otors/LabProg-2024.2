#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int num;

    // Coleta de Dados
    printf("Digite um valor inteiro: ");
    scanf("%d", &num);

    // Exibição do resultado
    printf("O módulo do número fornecido é: %d\n", num < 0 ? -num : num); // Operador ternario para definir o output

    return 0;
}
