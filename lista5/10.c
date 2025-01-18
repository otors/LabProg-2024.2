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

    int vetorF[N] = {0};
    for (int j = 0; j < TAM; j++) *(vetorF+*(vetorX+j)) += 1;

    printf("Vetor X:\n[");
    for (int k = 0; k < TAM; k++) k == TAM-1 ? printf("%d]\n", *(vetorX+k)) : printf("%d, ", *(vetorX+k));

    printf("Vetor F:\n[");
    for (int k = 0; k < N; k++) k == N-1 ? printf("%d]\n", *(vetorF+k)) : printf("%d, ", *(vetorF+k));

    return 0;
}