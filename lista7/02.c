#include <stdio.h>

#define STR_MAX 128

typedef struct estoque {
    char nome[STR_MAX];
    int numPeca;
    float preco;
    int numPedido;
} Estoque;

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Uso: %s <quantidade>\n", argv[0]);
        exit(1);
    }

    int amount = atoi(argv[1]);
    Estoque *estoque;
    for (int k = 0; k < amount; k++) {
        printf("--== Peça %d ==--\n", k+1);
        printf("\tNome: ");
        fgets(estoque[k].nome, STR_MAX, stdin);
        printf("\tNúmero da Peça: ");
        scanf("%d", &estoque[k].numPeca);
        printf("\tPreço: ");
        scanf("%f", &estoque[k].preco);
        printf("\tNúmero do Pedido: ");
        scanf("%d", &estoque[k].numPedido);
        fgetc(stdin);
    }

    return 0;
}
