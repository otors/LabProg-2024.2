#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned char jose = 150, pedro = 110, count;
    
    while (jose != pedro) {
        jose += 2;
        pedro += 3;
        count++;
    }

    printf("José e Pedro terão a mesma altura (%d cm), em %d anos\n", jose, count);

    return 0;
}
