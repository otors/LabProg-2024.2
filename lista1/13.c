#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    float celsius;

    // Coleta de Dados
    printf("Digite uma temperatura(em °C): ");
    scanf("%f", &celsius);

    // Exibição do resultado
    printf("Temperatura convertida para °F: %.2f\n", (9*celsius +160)/5); // Calculo realizado dentro do arg. de 'printf'
    return 0;
}
