#include <stdio.h>

int main() {
    int x = 5;

    printf("Valor inicial de x: %d\n", x);

    // Pré-decremento: o valor de x é decrementado antes de ser usado na expressão
    printf("Pré-decremento (--x): %d\n", --x);
    printf("Valor de x após pré-decremento: %d\n", x);

    // Redefinindo x para 5
    x = 5;

    // Pós-decremento: o valor de x é usado na expressão e depois é decrementado
    printf("Pós-decremento (x--): %d\n", x--);
    printf("Valor de x após pós-decremento: %d\n", x);

    return 0;
}
