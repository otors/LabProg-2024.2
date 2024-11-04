#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void mostrar_tabela(unsigned char controle); // Protótipo da função mostra_tabela

int main(int argc, char const *argv[])
{
    unsigned char armarios = 0; // Inicialização da variavel de controle com armários desocupados
    char escolha;
    do {
        printf("\e[1;1H\e[2J"); // Limpar console
        
        srand(time(NULL)); // Definição da seed para o rand() baseado no tempo

        // Exibição do Menu
        puts("----====== Menu ======----");
        puts("1. Ocupar armário");
        puts("2. Liberar armário");
        puts("3. Sair");
        scanf("%hhd", &escolha);

        unsigned char masc = 1; // Inicialização da mascara antes de cada operação
        if (escolha == 1) {
            // Mostrando ao usuário os armários antes de ocupar
            printf("\e[1;1H\e[2J"); // Limpar console
            puts("----===== Armários =====----");
            mostrar_tabela(armarios), sleep(1);

            // Handler do caso em que todos os armarios estão ocupados
            if (armarios == 255) {
                puts("Todos os armários estão ocupados!"), sleep(1);
                continue;
            }
            
            // Avisando ao usuário que o programa está efetuando a operação
            puts("Ocupando um armário..."), sleep(1);
            
            // Ocupando um armario aleatório
            char random; // Variavel para guardar o armário gerado aleatoriamente
            do {
                masc = 1; // Resetando a masc para cada iteração
                random = rand() % 8;
                masc <<= random; // Sorteando um armario dentre os possiveis
            } while(armarios & masc);
            armarios |= masc;

            // Mostrando ao usuário os armários após ocupar o armário aleatório 
            printf("\e[1;1H\e[2J"); // Limpar console
            puts("----===== Armários =====----");
            mostrar_tabela(armarios), sleep(1);         

            // Informa ao usuário o armário que foi ocupado
            printf("O armário %d foi ocupado!\n", random), sleep(1);   

        } else if (escolha == 2) {
            // Mostrando ao usuário os armários antes de desocupar
            printf("\e[1;1H\e[2J"); // Limpar console
            puts("----===== Armários =====----");
            mostrar_tabela(armarios), sleep(1);

            // Handler do caso em que todos os armarios estão desocupados
            if (!armarios) {
                puts("Todos os armários estão livres!"), sleep(1);
                continue;
            }
            
            // Pedindo ao usuário o armário que ele deseja liberar
            char liberar;
            do {
                printf("Digite o armário que deseja liberar (0 a 7): ");
                scanf("%hhd", &liberar);
            } while (liberar < 0 || liberar > 7);

            // Avisando ao usuário que o programa está efetuando a operação
            printf("Liberando armário %d...\n", liberar), sleep(1);

            // Liberando o armário selecionado
            masc <<= liberar;
            armarios &= ~masc;

            // Mostrando ao usuário os armários após desocupar o armário selecionado
            printf("\e[1;1H\e[2J"); // Limpar console
            puts("----===== Armários =====----");
            mostrar_tabela(armarios), sleep(1);
            printf("O armário %d foi liberado!\n", liberar), sleep(1);

        }

    } while(escolha != 3);

    printf("\e[1;1H\e[2J"); // Limpar console

    return 0;
}

/*
    Essa função recebe uma variável de controle para mostrar os bits 
    da variavel em uma tabela.

    *controle: variavel de controle para observação dos bits. Troque 
               o tipo da variavel para mais bits.
*/
void mostrar_tabela(unsigned char controle) {
    char tam = 8*sizeof(controle)-1; // Variavel para gerenciar o tamanho da tabela
    
    printf("--");
    for (int i = tam; i >= 0; i--) 
        i > 9 ? printf("----") : printf("---"); // Tabela correta para tipos com mais de 1 byte
    printf("--\n");

    // Exibindo pesos dos bits
    printf("| ");
    for (int j = tam; j >= 0; j--) 
        printf(" %d ", j);
    printf(" |\n");
    
    // Exibindo bits
    printf("| ");
    for (int k = tam; k >= 0; k--) 
        printf(" %d ", (controle >> k) & 1);
    printf(" |\n");

    printf("--");
    for (int i = tam; i >= 0; i--) 
        i > 9 ? printf("----") : printf("---"); // Tabela correta para tipos com mais de 1 byte
    printf("--\n");
}
