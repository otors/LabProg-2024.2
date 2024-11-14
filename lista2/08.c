#include <stdio.h>

int main(int argc, char const *argv[])
{
    float produto, entrada;
    int prestacoes; // p1 e p2 são as prestações

    printf("Forneça o valor do produto: ");
    scanf("%f", &produto);

    prestacoes = produto/3;
    entrada = produto - (prestacoes*2);

    printf("R$ %.2f, a entrada  ́e de R$ %.2f e as duas prestações são iguais a R$ %.2f.\n", produto, entrada, (float)prestacoes);

    return 0;
}
