#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    // Declarando maior e menor tal que eles sempre serão mudados
    int num, maior = INT_MIN, menor = INT_MAX;
    puts("-== Digite qualquer número negativo par para sair ==-");
    while (1) {
        printf("Digite um número: ");
        scanf("%d", &num);

        if ((num < 0) && !(num % 2)) break;

        maior = (maior < num) ? num : maior;
        menor = (menor > num) ? num : menor;
    }

    printf("O produto do maior(%d) pelo menor(%d) é igual a %d\n", maior, menor, maior*menor);

    return 0;
}
