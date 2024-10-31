#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    float hr_aula, bruto, liquido;
    int hrs_trab;

    // Coleta de Dados
    printf("Digite o valor da hora aula: ");
    scanf("%f", &hr_aula);
    printf("Digite a quantidade de horas trabalhadas no mês: ");
    scanf("%d", &hrs_trab);

    // Calculo do Salário Bruto
    bruto = hr_aula*hrs_trab;

    /*
        Tabela Contribuição INSS 2024
    Salário de Contribuição (R$)	Alíquota (%)
    até R$ 1.412,00	                7,5 %
    de R$ 1.412,01 até R$ 2.666,68	9,0%
    de R$ 2.666,69 até R$ 4.000,03	12,0%
    de R$ 4.000,04 até R$ 7.786,02	14,0%
    */

    /* Os valores ao final do desconto(21.18, 101.18, 181.18), foram calculados da seguinte maneira:
        desc_fixo = desc_fixo_anterior + (max_anterior*taxa_atual)-(max_anterior*taxa_anterior)

       Tomando a segunda faixa como exemplo, temos: 
        21.18 = 0 + (1412*0.09)-(1412*0.075)
    */ 

    // Estrutura de decisão para aplicação correta da taxa do INSS
    if (bruto <= 1412) {
        liquido = bruto-(bruto*0.075);
    } else if((bruto > 1412) && (bruto <= 2666.68)) {
        liquido = bruto-((bruto*0.09)-21.18); 
    } else if ((bruto > 2666.68)&&(bruto <= 4000.03)) {
        liquido = bruto-((bruto*0.12)-101.18);
    } else if ((bruto > 4000.03) && (bruto <= 7786.02)) {
        liquido = bruto-((bruto*0.14)-181.18);
    } else {
        liquido = bruto-((7786.02*0.14)-181.18);
    }

    printf("Bruto: %.2f\n", bruto);
    printf("Liquido: %.2f\n", liquido);
    return 0;
}
