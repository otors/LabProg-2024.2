#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int num, cent, dez, uni;

    // Coleta de Dados
    printf("Digite um número inteiro de três digitos: ");
    scanf("%d", &num);

    // Efetuação dos calculos para separação de casas decimais
    cent = num/100;
    dez = (num/10) - 10*cent;
    uni = num%10;

    // Exibição do resultado
    printf("Invertido: %d\n", (uni*100)+(dez*10)+(cent));

    return 0;
}
