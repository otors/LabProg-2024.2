#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum3 = 0, sum5 = 0;

    for (int i = 0; i <= 200; i++) {
        if (i <= 100) {
            sum3 += (i%3) ? 0 : i;
        } else {
            sum5 += (i%5) ? 0 : i;
        }
    }

    printf("Somatório [0, 100], divisivel por 3: %d\n", sum3);
    printf("Somatório ]100, 200], divisivel por 5: %d\n", sum5);

    return 0;
}
