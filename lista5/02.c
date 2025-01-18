#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *pa, *pb, *resultado;
    printf("Digite o valor a: ");
    scanf("%d", pa);
    printf("Digite o valor b: ");
    scanf("%d", pb);

    int temp = *pa;
    *pa = *pb;
    *pb = temp;

    printf("Valores trocados: a = %d, b = %d\n", *pa, *pb);

    return 0;
}