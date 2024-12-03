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

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        printf("As strings fornecidas são diferentes\n");
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            printf("As strings fornecidas são diferentes\n");
            return 0;
        }
    }

    printf("As strings fornecidas são iguais\n");
    return 0;
}
