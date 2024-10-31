#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    int x;

    // Coleta de Dados
    printf("Entre com um valor: "); 
    scanf("%d", &x);

    // Exibição do resultado
    printf("Hexadecimal: %#x\n", x);
    printf("Octal: %#o\n", x);

    return 0;
}
