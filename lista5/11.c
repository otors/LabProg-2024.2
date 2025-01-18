#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define N 7

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    
    int vetorX[TAM];
    for (int i = 0; i < TAM; i++) *(vetorX+i) = rand() % N;
    int vetorY[TAM];
    for (int i = 0; i < TAM; i++) *(vetorY+i) = rand() % N;

    int matrizM[N][N] = {0};
    for (int j = 0; j < TAM; j++) matrizM[*(vetorY+j)][*(vetorX+j)] += 1;

    printf("Vetor X:\n[");
    for (int k = 0; k < TAM; k++) k == TAM-1 ? printf("%d]\n", *(vetorX+k)) : printf("%d, ", *(vetorX+k));
    printf("Vetor Y:\n[");
    for (int k = 0; k < TAM; k++) k == TAM-1 ? printf("%d]\n", *(vetorY+k)) : printf("%d, ", *(vetorY+k));

    printf("Matriz M:\n");
    for (int i = 0; i < N; i++) {
        printf("[");
        for (int j = 0; j < N; j++) {
            (j == N-1) ? printf("%d]\n", matrizM[i][j]) : printf("%d, ", matrizM[i][j]);
        }
    }


    return 0;
}