#include <stdio.h>

#define CASAS_DEC 500
int main(int argc, char const *argv[])
{
    double pi = 0;
    char sinal = 4;

    for (int i = 0; i < CASAS_DEC; i++) {
        pi += (double)sinal/((i*2) +1);
        sinal *= -1;
        printf("PI com %d termos: %.12f\n", i+1, pi);
    }
    return 0;
}
