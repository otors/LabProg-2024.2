#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float x[2], y[2]; // Declarando vetores para x₁,x₂ e y₁,y₂

    //Coleta de dados
    printf("Digite as coordenadas do primeiro ponto: \n");
    printf(" — x₁: ");
    scanf("%f", &x[0]);
    printf(" — y₁: ");
    scanf("%f", &y[0]);

    printf("Digite as coordenadas do primeiro ponto: \n");
    printf(" — x₂: ");
    scanf("%f", &x[1]);
    printf(" — y₂: ");
    scanf("%f", &y[1]);
    
    // Exibição do resultado pela formula dada
    printf("Distância: %.2f\n", sqrt((pow((x[1]-x[0]), 2.0) + pow((y[1]-y[0]), 2.0))));
    
    return 0;
}
