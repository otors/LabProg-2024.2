#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned hr, min, seg;

    printf("Digite o tempo em segundos: ");
    scanf("%d", &seg);

    hr = seg/3600;
    min = (seg/60)%60;
    seg = seg%60;

    printf("HH:mm:ss -> %02d:%02d:%02d\n", hr, min, seg);

    return 0;
}
