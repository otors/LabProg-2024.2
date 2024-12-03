#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Valores arbitrarios pois não há especificação sobre as dimesões nem sobre os valores aleatórios
#define QL 5
#define QC 6

#define RNG_MIN 0
#define RNG_MX 10

int main(int argc, char const *argv[])
{
    // O tipo do elemento não é especificado, então usarei 'int'
    int matriz[QL][QC];
    for (int i = 0; i < QL; i++) {
        for (int j = 0; j < QC; j++) {
            matriz[i][j] = RNG_MIN + rand() % RNG_MX;
        }
    }

    int usr_in, count = 0;
    printf("Digite um número entre %d e %d: ", RNG_MIN, RNG_MX);
    scanf("%d", &usr_in);

    for (int i = 0; i < QL; i++) {
        for (int j = 0; j < QC; j++) {
            count += (matriz[i][j] == usr_in) ? 1 : 0;
        }
    }

    printf("O número %d aparece %d vezes na matriz a seguir:\n", usr_in, count);
    for (int i = 0; i < QL; i++) {
        printf("[");
        for (int j = 0; j < QC; j++) {
            (j == QC-1) ? printf("%d]\n", matriz[i][j]): printf("%d, ", matriz[i][j]);
        }
    }

    return 0;
}
