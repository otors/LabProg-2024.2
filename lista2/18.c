#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned long long int sum_chess = 0;
    for (int i = 0; i < 64; i++) {
        // Solução bitwise
        // sum_chess <<= 1;
        // sum_chess |= 1;

        // Solução bitwise compacta
        // sum_chess += (unsigned long)1 << i;

        // Solução decimal
        sum_chess *= 2;
        sum_chess++;

        printf("%dº quadro: %llu\n", i+1, sum_chess);
    }
    return 0;
}
