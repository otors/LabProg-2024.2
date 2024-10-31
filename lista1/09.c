#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    float comprimento, largura, altura;

    // Coleta de Dados
    printf("Digite o comprimento: ");
    scanf("%f", &comprimento);
    printf("Digite a largura: ");
    scanf("%f", &largura);
    printf("Digite a altura: ");
    scanf("%f", &altura);
    
    // Exibição do Resultado
    printf("Volume: %.2f\n", comprimento*largura*altura); // Calculo realizado no arg. da função 'printf'

    return 0;
}
