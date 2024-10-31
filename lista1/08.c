#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int value;

    // Coleta de Dados
    printf("Digite um valor: ");
    scanf("%d", &value);

    // Exibição do resultado
    printf("Antecessor: %d\n", value-1);
    printf("Sucessor: %d\n", value+1);

    return 0;
}
