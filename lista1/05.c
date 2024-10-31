#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    float altura;
    char sexo;

    // Coleta de dados
    printf("Digite sua altura(em metros): ");
    scanf("%f", &altura);
    
    printf("Digite seu sexo(h/m): ");
    do {
        scanf(" %c", &sexo);
    } while (sexo != 'h' && sexo != 'm');

    // Controle de fluxo para exibição do resultado
    if(sexo == 'h') {
        printf("Peso ideal: %.2f\n", 72.7*altura - 58); // Calculo feito no arg. da função 'printf'
    } else {
        printf("Peso ideal: %.2f\n", 62.1*altura - 44.7); // Calculo feito no arg. da função 'printf'
    }
    
    return 0;
}
