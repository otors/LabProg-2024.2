#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    printf("Digite um número para mostrar sua tabuada: ");
    scanf("%d", &num);

    printf("--=== TABUADA DO %d ===--\n", num);
    for (int i = 1; i < 10; i++) {
        printf("%d*%d = %d\n", num, i, num*i);
    }
    return 0;
}
