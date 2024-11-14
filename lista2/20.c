#include <stdio.h>

#define START 1
#define FINISH 10

int main(int argc, char const *argv[])
{
    for (int i = START; i <= FINISH; i++) {
        if (i%2) {
            int fat = i;
            for (int j = 2; j < i; j++) {
                fat *= j;
            }
            printf("Fatorial de %d = %d\n", i, fat);
        }
    }
    
    return 0;
}
