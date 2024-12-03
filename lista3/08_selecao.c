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

    printf("\nVetor gerado:\n[");
    for (int k = 0; k < TAM; k++) k == TAM-1 ? printf("%d", vetor[k]) : printf("%d, ", vetor[k]);
    printf("]\n");

    for (int i = 0; i < TAM-1; i++) {
        int i_menor = i;

        // Itera sobre os valores do vetor depois de i para encontrar o menor
        for (int j = i + 1; j < TAM; j++) {if (vetor[j] < vetor[i_menor]) {i_menor = j;}}
            
        // Troca os valores
        int temp = vetor[i];
        vetor[i] = vetor[i_menor];
        vetor[i_menor] = temp;
    }

    printf("\nVetor ordenado:\n[");
    for (int k = 0; k < TAM; k++) k == TAM-1 ? printf("%d", vetor[k]) : printf("%d, ", vetor[k]);
    printf("]\n");

    return 0;
}
