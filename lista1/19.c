#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int num;

    // Coleta de dados
    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    // Exibição do resultado
    printf("o número é: %s\n", num%2 ? "Ímpar":"Par");

    return 0;
}
