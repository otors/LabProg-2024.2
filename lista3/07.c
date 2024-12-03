#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAM 3

int main(int argc, char const *argv[])
{
    int vetor[TAM]; 
    float media_a = 0, media_g = 1;
    
    srand(time(NULL)); 

    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 20;
        media_a += vetor[i];
        media_g *= vetor[i];
    }

    media_a /= TAM;
    media_g = pow(media_g, 1/(float)TAM);
    
    printf("[");
    for (int j = 0; j < TAM; j++) j == TAM-1 ? printf("%d", vetor[j]) : printf("%d, ", vetor[j]);
    printf("]\n");
    printf("Média Aritmética: %.2f\n", media_a);
    printf("Média Geométrica: %.2f\n", media_g);

    return 0;
}
