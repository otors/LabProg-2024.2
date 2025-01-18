#include <stdio.h>
#include <string.h>

#define STRMX 25 //Tamanho máximo da string

int main(int argc, char const *argv[])
{
    char str[STRMX];
    printf("Forneça uma string: ");
    fgets(str, STRMX, stdin);
    str[strcspn(str, "\n")] = '\0';

    char destino[STRMX];
    for (int i = 0; str[i] != '\0'; i++) {
        *(destino+i) = str[i];
    }
    *(destino+strlen(str)) = '\0';

    printf("String original (endereço): %s (%p)\n", str, &str);
    printf("String copiada (endereço): %s (%p)\n", destino, &destino);

    return 0;
}