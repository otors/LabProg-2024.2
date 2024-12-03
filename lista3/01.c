#include <stdio.h>

#define TAM 15 

int main(int argc, char const *argv[])
{
    float arr[TAM];
    float maior, menor;
    for (int i = 0; i < TAM; i++) {
        printf("Digite um valor de ponto flutuante: ");
        scanf("%f", &arr[i]);
        if (!i) {
            maior = arr[i];
            menor = arr[i];
            continue;
        }
        maior = maior < arr[i] ? arr[i] : maior; 
        menor = menor > arr[i] ? arr[i] : menor; 
    }

    printf("Vetor lido:\n");
    for(int j = 0; j < TAM; j++) {
        if (!j) {
            printf("[%f, ", arr[j]);
        } else if (j == TAM-1) {
            printf("%f]\n", arr[j]);
        } else {
            printf("%f, ", arr[j]);
        }
    }

    printf("Soma do maior(%f) com o menor(%f) valor: %f\n", maior, menor, maior+menor);

    return 0;
}
