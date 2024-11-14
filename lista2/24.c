#include <stdio.h>
#include <math.h>

#define LIMIT 500

int main() {
    // Itera sobre todos os valores de c1 e c2
    for (int c1 = 1; c1 <= LIMIT; c1++) {
        for (int c2 = c1; c2 <= LIMIT; c2++) {  // c2 >= c1 para evitar repetições
            // Calcula a hipotenusa
            double h = sqrt((c1 * c1) + (c2 * c2));
            
            // Verifica se h é um número inteiro e não excede o limite
            if (h == (int)h && h <= LIMIT) {
                printf("(%d, %d, %.0f)\n", c1, c2, h);
            }
        }
    }
    return 0;
}
