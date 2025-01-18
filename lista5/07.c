#include <stdio.h>
#include <string.h>

#define STRMX 25 //Tamanho máximo da string

int main(int argc, char const *argv[])
{
    char str1[2*STRMX], str2[STRMX]; //Declaração de str1 com 2*STRMX, pois str1 receberá str2 de tamanho STRMX

    printf("Forneça a primeira string: ");
    fgets(str1, STRMX, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Forneça a segunda string: ");
    fgets(str2, STRMX, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove o caractere de nova linha

    int i = 0, j = 0;

    while (*(str1+i) != '\0') i++;

    while (*(str2+j) != '\0') {
        *(str1+i) = *(str2+j);
        i++, j++;
    }

    *(str1+i) = '\0';

    printf("As strings fornecidas concatenadas: %s\n", str1);
    return 0;
}