#include <stdio.h>

#define TERM 20

int main(int argc, char const *argv[])
{
    int n2 = 0, n1 = 1; // Tomando F = (n-2)(n-1), em que 'n' são termos da sequencia. Inicialmente, n2 e n1 são 1
    for (int i = 0; i < TERM; i++) {
        if (!i) {
            printf("%d", n1); 
            continue;
        } 
        int n = n2+n1;
        if (i == TERM-1) {
            printf(", %d\n", n);
        } else if (i) {
            printf(", %d", n);
        } 
        
        n2 = n1;
        n1 = n;
    }
    return 0;
}
