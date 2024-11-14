#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Coletando o intervalo por parte do usuário
    int a, b, start, finish;
    printf("Digite A: ");
    scanf("%d", &a);
    printf("Digite B: ");
    scanf("%d", &b);
    (a < b) ? (start = a, finish = b) : (start = b, finish = a);

    float media = 0;
    for (int i = start; i <= finish; i++) {
        media += i;
    }

    media /= (finish-start);

    printf("Média Aritmética do intervalo [%d, %d]: %.2f\n", start, finish, media);

    return 0;
}
