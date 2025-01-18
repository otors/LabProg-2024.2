#include <stdio.h>
#include <string.h>

#define STRMX 25 //Tamanho máximo da string

int main(int argc, char const *argv[])
{
    char str[STRMX];

    printf("Forneça uma string: ");
    fgets(str, STRMX, stdin);
    str[strcspn(str, "\n")] = '\0';

    int tamanho = 0;
    while (*(str+tamanho) != '\0') {
        tamanho++;
    }

    printf("Tamanho da string: %d\n", tamanho);

    return 0;
}