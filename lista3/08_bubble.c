#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAM 100

int main(int argc, char const *argv[])
{
    int vetor[TAM];
    int min, max;

    srand(time(NULL));

    printf("Digite o valor mínimo do intervalo: ");
    scanf("%d", &min);
    printf("Digite o valor máximo do intervalo: ");
    scanf("%d", &max);

    for (int i = 0; i < TAM; i++) vetor[i] = min+(rand()%(max-min+1));

    printf("[");
    for (int j = 0; j < TAM; j++) j == TAM-1 ? printf("%d", vetor[j]) : printf("%d, ", vetor[j]);
    printf("]\n");

    for (int i = 0; i < TAM-1; i++) {
        for (int j = 0; j < TAM-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                // Troca os valores
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }

    printf("\nVetor ordenado:\n[");
    for (int k = 0; k < TAM; k++) k == TAM-1 ? printf("%d", vetor[k]) : printf("%d, ", vetor[k]);
    printf("]\n");

    return 0;

}
