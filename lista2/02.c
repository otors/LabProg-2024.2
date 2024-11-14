#include <stdio.h>

int main(int argc, char const *argv[])
{
    char dia = -1;
    puts("Digite 0 para sair");
    do {
        printf("Digite o número de um dia da semana: ");
        scanf("%hhd", &dia);
        switch (dia) {
            case 1:
                printf("Domingo!\n");
                break;
            case 2:
                printf("Segunda-feira!\n");
                break;
            case 3:
                printf("Terça-feira!\n");
                break;
            case 4:
                printf("Quarta-feira!\n");
                break;
            case 5:
                printf("Quinta-feira!\n");
                break;
            case 6:
                printf("Sexta-feira!\n");
                break;
            case 7:
                printf("Sábado!\n");
                break;
            default:
                printf("Número de dia não válido\n");
                break;
        }
    } while (dia);
    return 0;
}
