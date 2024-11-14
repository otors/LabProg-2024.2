#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Mostrando os valores em °F de 0 a 100 °C
    for (int i = 0; i < 10; i++) {
        int celsius = (i+1)*10;
        // Formula (°C × 9/5) + 32
        int fahrenheit = ((celsius*9)/5) + 32;
        printf("%d°C = %d°F\n", celsius, fahrenheit);
    }

    return 0;
}
