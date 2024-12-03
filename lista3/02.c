#include <stdio.h>
#include <string.h>

#define STRMX 25 //Tamanho máximo da string

int main(int argc, char const *argv[])
{
    char str_in[STRMX], c;
    printf("Digite uma string qualquer: ");
    fgets(str_in, STRMX, stdin);
    str_in[strcspn(str_in, "\n")] = '\0';

    printf("Digite um caracter a ser buscado: ");
    scanf(" %c", &c);

    for (int i = 0, tam = strlen(str_in); i < tam; i++) {
        if(str_in[i] == c) {
            printf("O caracter '%c' está contido em '%s'\n", c, str_in);
            break;
        }
        if(i == tam-1) {
            printf("O caracter '%c' não está contido em '%s'\n", c, str_in);
        }
    }
    return 0;
}
