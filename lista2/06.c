#include <stdio.h>

int main(int argc, char const *argv[])
{
    char paulo = 0, renata = 0, branco = 0, nulo = 0, usr_in;
    do {
        printf("\e[1;1H\e[2J"); // Limpar console
        puts("Digite qualquer número menor que zero para sair");
        printf("Digite o número do seu candidato: ");
        scanf("%hhd", &usr_in);

        switch(usr_in) {
            case 5:
                printf("Confirmar voto em PAULO(s/n)? ");
                while ((usr_in = getchar()) != '\n' && usr_in != EOF); // Limpando o buffer
                scanf("%c", &usr_in);
                if (usr_in == 'n') continue;
                paulo++;
                break;
            case 7:
                printf("Confirmar voto em RENATA(s/n)? ");
                while ((usr_in = getchar()) != '\n' && usr_in != EOF); // Limpando o buffer
                scanf("%c", &usr_in);
                if (usr_in == 'n') continue;
                renata++;
                break;
            case 0:
                printf("Confirmar voto em BRANCO(s/n)? ");
                while ((usr_in = getchar()) != '\n' && usr_in != EOF); // Limpando o buffer
                scanf("%c", &usr_in);
                if (usr_in == 'n') continue;
                branco++;
                break;
            default:
                if (usr_in < 0) break; // Handle interno ao default para sair da votação
                printf("Confirmar voto NULO(s/n)? ");
                while ((usr_in = getchar()) != '\n' && usr_in != EOF); // Limpando o buffer
                scanf("%c", &usr_in);
                if (usr_in == 'n') continue; 
                nulo++;
                break;
        }
    } while (usr_in > 0);

    short total = paulo + renata + branco + nulo;
    
    printf("\e[1;1H\e[2J"); // Limpar console
    puts("--== Resultados ==--");
    printf("Paulo: %.1f%%\n", ((float)paulo/total)*100);
    printf("Renata: %.1f%%\n", ((float)renata/total)*100);
    printf("Branco: %.1f%%\n", ((float)branco/total)*100);
    printf("Nulo: %.1f%%\n", ((float)nulo/total)*100);

    // Considerando o sistema de votos válidos (brancos e nulos não sao considerados para o resultado)
    if (paulo > renata) {
        printf("Paulo ganhou com %d dos %d votos válidos!\n", paulo, (paulo+renata));
    } else if (renata > paulo) {
        printf("Renata ganhou com %d dos %d votos válidos!\n", renata, (renata+paulo));
    } else {
        puts("Empate! Prepare-se para o segundo turno!");
    }

    return 0;
}