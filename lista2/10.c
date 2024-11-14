#include <stdio.h>

#define START 15
#define FINISH 90

int main(int argc, char const *argv[])
{
    char count = 0; // Variavel de controle para o printf
    for (int i = START; i <= FINISH; i++) {
        if (!(i%4)) (!count ? printf("%d", i*i) : printf(", %d", i*i)), count++;
        if (i == FINISH) printf("\n");
    }

    return 0;
}
