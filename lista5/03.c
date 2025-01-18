#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *pNum;
    printf("Digite números (0 para parar): ");
    scanf("%d", pNum);
    
    int *pMenor;
    *pMenor = *pNum;
    while (*pNum != 0) {
        if (*pNum < *pMenor) {
            *pMenor = *pNum;
        }
        scanf("%d", pNum);
    }

    printf("O menor número digitado foi: %d\n", *pMenor);

    return 0;
}