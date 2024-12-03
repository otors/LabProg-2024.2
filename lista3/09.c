#include <stdio.h>

#define TAM 3

int main(int argc, char const *argv[])
{
    int matriz[TAM][TAM]; // O tipo de dado não foi especificado então usarei 'int'
    
    printf("Digite os elementos da matriz 3x3:\n");
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("Forneça o elemento(int) [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz fornecida:\n");
    for (int i = 0; i < TAM; i++) {
        printf("[");
        for (int j = 0; j < TAM; j++) {
            (j == TAM-1) ? printf("%d]\n", matriz[i][j]): printf("%d, ", matriz[i][j]);
        }
    }

    printf("\nElementos da diagonal principal: ");
    for(int i = 0; i < TAM; i++) printf("%d ", matriz[i][i]);
    printf("\n");

    return 0;
}
