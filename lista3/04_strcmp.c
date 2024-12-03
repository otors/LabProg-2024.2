#include <stdio.h>
#include <string.h>

#define STRMX 25 //Tamanho máximo da string

int main(int argc, char const *argv[])
{
    char str1[STRMX+1], str2[STRMX+1];
    printf("Forneça a primeira string: ");
    fgets(str1, STRMX, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("Forneça a segunda string: ");
    fgets(str2, STRMX, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (strcmp(str1, str2)) {
        printf("As strings fornecidas são diferentes\n");
    } else {
        printf("As strings fornecidas são iguais\n");
    }
    
    return 0;
}
