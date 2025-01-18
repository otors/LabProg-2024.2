#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define MX 256

int main(int argc, char const *argv[])
{
    int vetor[TAM];
    int min, max;

    srand(time(NULL));

    for (int i = 0; i < TAM; i++) *(vetor+i) = rand() % MX;

    printf("Vetor:\n[");
    for (int j = 0; j < TAM; j++) j == TAM-1 ? printf("%d", *(vetor+j)) : printf("%d, ", *(vetor+j));
    printf("]\n");

    for (int i = 0; i < TAM-1; i++) {
        for (int j = 0; j < TAM-i-1; j++) {
            if (*(vetor+j) > *(vetor+j+1)) {
                int temp = *(vetor+j);
                *(vetor+j) = *(vetor+j+1);
                *(vetor+j+1) = temp;
            }
        }
    }

    printf("\nVetor ordenado:\n[");
    for (int k = 0; k < TAM; k++) k == TAM-1 ? printf("%d", *(vetor+k)) : printf("%d, ", *(vetor+k));
    printf("]\n");

    return 0;

}
