#include <stdio.h>
#include <string.h>

#define STRMX 25 // Tamanho máximo da string

int main() {
    char str_in[STRMX];
    printf("Digite uma string qualquer: ");
    fgets(str_in, STRMX, stdin);
    str_in[strcspn(str_in, "\n")] = '\0';

    int length = strlen(str_in);

    printf("String invertida: ");
    for(int i = length - 1; i >= 0; i--) printf("%c", str_in[i]);

    printf("\n");

    return 0;
}