#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaraçãp de variaveis
    int dias_trab;
    float bruto, liquido;

    // Coleta de dados
    printf("Digite a quantidade de dias trabalhados: ");
    scanf("%d", &dias_trab);

    // Estrutura de decisão para designar a gratificação correta
    if(dias_trab <= 10) {
        // Sem gratificação 
        bruto = dias_trab*50.25;
        puts("Sem Gratificação");
    } else if (dias_trab > 10 && dias_trab <= 20) {
        // Gratificação de 10%
        bruto = 1.1*(dias_trab*50.25);
        puts("Gratificação de 10%");
    } else if (dias_trab > 20) {
        // Gratificação de 20%
        bruto = 1.3*(dias_trab*50.25);
        puts("Gratificação de 20%");
    }

    // Imposto de Renda de 10 %
    liquido = bruto*0.9;

    // Exibição do resultado
    printf("Liquido: %.2f\n", liquido);
    return 0;
}
