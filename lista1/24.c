#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declaração de Variaveis
    unsigned hr, min, seg;

    // Coleta de dados
    printf("Digite o tempo em segundos: ");
    scanf("%d", &seg);

    // Calculo do tempo
    hr = seg/3600;
    min = (seg/60)%60;
    seg = seg%60;
    
    // Exibição do resultado
    printf("HH:mm:ss -> %02d:%02d:%02d\n", hr, min, seg); // Saida formatada para HH:mm:ss

    return 0;
}
