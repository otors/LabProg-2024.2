#include <stdio.h>
#include <string.h>

#define STRMX 25 //Tamanho máximo da string

int main(int argc, char const *argv[])
{
    char str[STRMX], c;
    printf("Digite uma string qualquer: ");
    fgets(str, STRMX, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Digite um caracter a ser buscado: ");
    scanf(" %c", &c);

    for (int i = 0, tam = strlen(str); i < tam; i++) {
        if(*(str+i) == c) {
            printf("O caracter '%c' está contido em '%s'\n", c, str);
            return 0;
        }
    }

    printf("O caracter '%c' não está contido em '%s'\n", c, str);
    
    return 0;
}
