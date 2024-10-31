#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    float cotacao, real;

    // Coleta de Dados
    printf("Digite o valor a ser convertido(em reais): ");
    scanf("%f", &real);
    printf("Digite a cotação do dólar: ");
    scanf("%f", &cotacao);
    
    // Exibição do resultado
    printf("Valor convertido para dólar: %.2f\n", real*cotacao);
    return 0;
}
