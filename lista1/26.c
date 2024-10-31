#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float n1, n2, n3;
    
    printf("Digite o primeiro valor: ");
    scanf("%f", &n1);
    printf("Digite o segundo valor: ");
    scanf("%f", &n2);
    printf("Digite o terceiro valor: ");
    scanf("%f", &n3);

    float ma, mg;
    ma = (n1+n2+n3)/3;
    mg = pow((n1*n2*n3), 1.0/3.0);

    printf("Média Aritmética: %.2f\n", ma);
    printf("Média Geométrica: %.2f\n", mg);
    return 0;
}
