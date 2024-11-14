#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int fat; // int foi usado por causa da taxa acelerada de crescimento do fatorial
    printf("Fatorial de: ");
    scanf("%d", &fat);

    // Calculo iterativo do Fatorial de 'fat'
    for (int i = fat-1; i > 0 ; i--) {
        fat *= i;
    }

    printf("Fatorial: %d\n", fat);

    return 0;
}
