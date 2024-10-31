#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declarando as Variaveis
    float raio;

    // Coleta de dados
    printf("Forneça o raio de um círculo: ");
    scanf("%f", &raio);

    // Exibição do resultado
    printf("Diametro: %f\n", 2*raio);
    printf("Circunferêcia: %f\n", 2*3.14159*raio);
    printf("Área: %f\n", 3.14159*raio*raio);
    
    return 0;
}
