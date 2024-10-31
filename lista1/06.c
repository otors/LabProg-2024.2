#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int horas, minutos, segundos;

    // Coleta de Dados
    printf("Digite a quantidade de horas: ");
    scanf("%d", &horas);
    printf("Digite a quantidade de minutos: ");
    scanf("%d", &minutos);
    printf("Digite a quantidade de segundos: ");
    scanf("%d", &segundos);

    // Exibição do resultado
    printf("Total de segundos: %d\n", (horas*3600)+(minutos*60)+(segundos)); // Calculo feito no arg. da função 'printf'
    
    return 0;
}
