#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    // Inicialização de Variaveis
    char a = 'A';
    char b = 'B';

    // Exibição dos valores inicias
    printf("Valores iniciais:\n");
    printf("a: %c\n", a);
    printf("b: %c\n", b);

    // Notifica o usuário que os valores serão trocados
    printf("Efetuando a troca...\n");
    sleep(1);
    char temp = a;
    a = b;
    b = temp;

    /* Uma alternativa para trocar os valores é:
    a = a ^ b; 
    b = a ^ b; 
    a = a ^ b;
    */

    // Exibição do resultado
    printf("\nVariaveis trocadas: \n");
    printf("a: %c\n", a);
    printf("b: %c\n", b);
    
    return 0;
}
