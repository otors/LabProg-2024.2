#include <stdio.h>

int main(int argc, char const *argv[])
{
    short user_in;
    short maior = 0, menor = 0;
    puts("Digite 0 para sair");

    do {
        printf("Informe um número: ");
        scanf("%hd", &user_in);
        if (!user_in)
            break;
        maior = (!maior || (maior < user_in)) ? user_in : maior;
        menor = (!menor || (menor > user_in)) ? user_in : menor;
        
        printf("Maior: %d\n", maior);
        printf("Menor: %d\n", menor);
    } while (user_in);

    return 0;
}
