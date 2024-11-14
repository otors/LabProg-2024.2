#include <stdio.h>

int main() {
    int numero;
    
    // Lê um número inteiro de cinco dígitos
    do {
        printf("Digite um número inteiro de cinco dígitos: ");
        scanf("%d", &numero);
    } while(numero < 10000 || numero > 99999);

    // Separa os dígitos
    int digito1 = numero / 10000;          // Primeiro dígito
    int digito2 = (numero / 1000) % 10;    // Segundo dígito
    int digito4 = (numero / 10) % 10;      // Quarto dígito
    int digito5 = numero % 10;             // Quinto dígito

    // Verifica se o número é um palíndromo
    if (digito1 == digito5 && digito2 == digito4) {
        printf("O número %d é um palíndromo.\n", numero);
    } else {
        printf("O número %d não é um palíndromo.\n", numero);
    }

    return 0;
}
