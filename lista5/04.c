#include <stdio.h>

#define TAM 5

int main(int argc, char const *argv[])
{
    char vetorChar[TAM];
    int vetorInt[TAM];
    float vetorFloat[TAM];

    // VETOR DE CHAR
    printf("\n ---==== Vetor de char ====--- \n");
    for (int i = 0; i < TAM; i++) {
        printf("Digite o valor %d(char): ", i + 1);
        scanf(" %c", vetorChar+i);
    }
    for (int k = 0; k < TAM; k++) printf("Valor: %c, Endereço: %p\n", *(vetorChar+k), vetorChar+k);

    // VETOR DE INT
    printf("\n ---==== Vetor de int ====--- \n");
    for (int i = 0; i < TAM; i++) {
        printf("Digite o valor %d(int): ", i + 1);
        scanf("%d", vetorInt+i);
    }
    for (int k = 0; k < TAM; k++) printf("Valor: %d, Endereço: %p\n", *(vetorInt+k), vetorInt+k);

    // VETOR DE FLOAT
    printf("\n ---==== Vetor de float ====--- \n");
    for (int i = 0; i < TAM; i++) {
        printf("Digite o valor %d(float): ", i + 1);
        scanf("%f", vetorFloat+i);
    }
    for (int k = 0; k < TAM; k++) printf("Valor: %f, Endereço: %p\n", *(vetorFloat+k), vetorFloat+k);

    /*  
        Observa-se que os endereços estão espaçados de acordo com o tamanho em bytes do tipo,
        no caso sizeof(char), sizeof(int) e sizeof(float), respectivamente.
    */ 
    
    return 0;
}