#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *matriz;
    int amount;
    float media;
} MediaMatriz;

#define MX 100

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    if (argc != 3) {
        printf("Uso: %s <width> <height>\n", argv[0]);
        exit(1);
    }

    MediaMatriz m1;
    m1.amount = atoi(argv[1])*atoi(argv[2]);
    m1.matriz = (int *) malloc(m1.amount*sizeof(int));
    m1.media = 0;
    for (int k = 0; k < m1.amount; k++) {
        m1.matriz[k] = rand() % MX;
        m1.media += m1.matriz[k];
    }

    m1.media /= m1.amount;
    printf("Media: %.2f\n", m1.media);

    return 0;
}
