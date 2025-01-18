#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *pa, *pb, *resultado;
    printf("Digite o primeiro valor: ");
    scanf("%d", pa);
    printf("Digite o segundo valor: ");
    scanf("%d", pb);

    *resultado = *pa + *pb;

    printf("Soma: %d, Endereço: %p\n", *resultado, resultado);

    return 0;
}