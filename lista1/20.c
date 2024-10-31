#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int n1, n2;

    // Coleta de Dados
    printf("Digite um número inteiro: ");
    scanf("%d", &n1);
    printf("Digite outro número inteiro: ");
    scanf("%d", &n2);

    // Exibição do resultado, com o operador ternário sendo utilizado para mostrar o output correto
    printf("O número %d %s de %d\n", n1, (n1%n2 ? "não é multiplo" : "é multiplo"), n2 );

    return 0;
}
