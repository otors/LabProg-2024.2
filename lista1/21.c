#include <stdio.h>

int main() {
    
    // Exibição dos caracteres obrigatórios ( 'A' 'B' 'C' 'a' 'b' 'c' '0' '1' '2' '$' '*' '+' '/' ' ' )
    printf("Caractere -> Valor Inteiro\n");
    printf("----------------------------\n");
    printf("   %c      ->     %d\n", 'A', 'A');
    printf("   %c      ->     %d\n", 'B', 'B');
    printf("   %c      ->     %d\n", 'C', 'C');
    printf("   %c      ->     %d\n", 'a', 'a');
    printf("   %c      ->     %d\n", 'b', 'b');
    printf("   %c      ->     %d\n", 'c', 'c');
    printf("   %c      ->     %d\n", '0', '0');
    printf("   %c      ->     %d\n", '1', '1');
    printf("   %c      ->     %d\n", '2', '2');
    printf("   %c      ->     %d\n", '$', '$');
    printf("   %c      ->     %d\n", '*', '*');
    printf("   %c      ->     %d\n", '+', '+');
    printf("   %c      ->     %d\n", '/', '/');
    printf("   %c      ->     %d\n", ' ', ' ');

    puts("----------------------------"); // Separação para organizar
    
    // Exibição dos caracteres da tabela ASCII de 65 a 126
    for (char i = 65; i < 127; i++) {
        printf("   %c      ->     %d\n", i, i);
    }

    return 0;
}

