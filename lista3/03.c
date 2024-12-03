#include <stdio.h>

#define STRMX 25 //Tamanho máximo da string

int main(int argc, char const *argv[])
{
    char str_in[STRMX];
    printf("Digite uma string qualquer: ");
    fgets(str_in, STRMX, stdin);
    str_in[strcspn(str_in, "\n")] = '\0';

    int count = 0;
    while (str_in[count] != '\0') {
        count++;
    }

    printf("A string fornecida possui %d caracteres\n", count);

    return 0;
}
