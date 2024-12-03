#include <stdio.h>
#include <string.h>

#define STRMX 25 // Tamanho máximo da string

int main() {
    char str1[STRMX], str2[STRMX];

    printf("Forneça a primeira string: ");
    fgets(str1, STRMX, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("Forneça a segunda string: ");
    fgets(str2, STRMX, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    printf("As strings fornecidas concatenadas: %s\n", strcat(str1, str2));
    return 0;
}
