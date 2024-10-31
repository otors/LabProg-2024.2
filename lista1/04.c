#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    float conta;

    // Coleta de dados
    printf("Entre com o valor da conta: ");
    scanf("%f", &conta);
    
    // Exibição do resultado
    printf("O valor total com taxa do garçom: %.2f\n", conta+(0.1*conta)); // Calculo da taxa na função 'printf'

    return 0;
}
