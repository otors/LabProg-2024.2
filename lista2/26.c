#include <stdio.h>

int main(int argc, char const *argv[])
{
    puts("Decimal \tBinário \tOctal\tHexadecimal");
    for (int i = 1; i <= 256; i++) {
        printf("   %d    \t", i);
        for (int j = 7; j >= 0; j--) 
            printf("%d", (i >> j) & 1);
        printf("\t %o\t", i);
        printf(" %#x\n", i);
    }

    return 0;
}
