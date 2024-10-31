#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int n1, n2;
    int sum, prod, diff, rem;
    float quo;

    // Coleta de Dados
    printf("Digite um número inteiro: ");
    scanf("%d", &n1);
    printf("Digite mais um número inteiro: ");
    scanf("%d", &n2);

    // Exibição dos resultados, com calculos feitos no arg. da função 'printf'
    printf("Soma: %d\n", n1+n2);
    printf("Produto: %d\n", n1*n2);
    printf("Diferença: %d\n", n1-n2);
    printf("Quociente: %f\n", (float)n1/n2);
    printf("Resto: %d\n", n1%n2);

    return 0;
}
