#include <stdio.h> 

int main(int argc, char const *argv[])
{
    int n1,n2; // Usa-se int pois não sabemos o tamanho do valor que será inserido
    puts("Vamos dividir dois valores!");
    printf("Digite o primeiro valor: ");
    scanf("%d", &n1);
    do {
        printf("Digite o primeiro valor(≠0): ");
        scanf("%d", &n2);
    } while(n2==0);

    printf("O quociente dessa divisão é: %f\n", ((float)n1)/n2);
    
    return 0;
}
