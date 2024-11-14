#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, qnt = 0;
    printf("Digite um número: ");
    scanf("%d", &num);

    while (num) {
        qnt += (num%10 == 7) ? 1 : 0;
        num /= 10;
    }

    printf("O número tem %d algarismos 7!\n", qnt);
    
    return 0;
}
