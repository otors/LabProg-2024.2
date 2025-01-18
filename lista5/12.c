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

    int r = 1+(rand() % 10);
    char mod;
    if (r > 0 && r <= 3) mod = 0;
    if (r > 3 && r <= 5) mod = -1;
    if (r > 5 && r <= 7) mod = +1;
    if (r > 7 && r <= 9) mod = -2; //Essa condição esta diferente para incluir o caso r = 8, que poderia ser um caso de erro
    if (r > 9 && r <= 10) mod = +2;

    int vetorY[TAM];
    for (int i = 0; i < TAM; i++) {
        *(vetorY+i) = *(vetorX+i) + mod;

        //Casos de borda
        if(*(vetorY+i) < 0) *(vetorY+i) = 0;
        if(*(vetorY+i) > N-1) *(vetorY+i) = *(vetorX+i);
    }

    int matrizM[N][N] = {0};
    for (int j = 0; j < TAM; j++) matrizM[*(vetorY+j)][*(vetorX+j)] += 1;

    printf("Vetor X:\n[");
    for (int k = 0; k < TAM; k++) k == TAM-1 ? printf("%d]\n", *(vetorX+k)) : printf("%d, ", *(vetorX+k));
    printf("Valor r: %d\n", r);
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