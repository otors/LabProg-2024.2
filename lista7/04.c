#include <stdio.h>

#define STR_MAX 128
#define AMOUNT 3

typedef struct aluno {
    char nome[STR_MAX];
    float nota1;
    float nota2;
    float media;
} Aluno;

int main(int argc, char const *argv[])
{
    Aluno alunos[3];
    
    for (int k = 0; k < 3; k++) {
        printf("--== Aluno %d ==--\n", k+1);
        printf("\tNome: ");
        fgets(alunos[k].nome, STR_MAX, stdin);
        printf("\tNota 1: ");
        scanf("%f", &alunos[k].nota1);
        printf("\tNota 2: ");
        scanf("%f", &alunos[k].nota2);
        fgetc(stdin);
        alunos[k].media = alunos[k].nota1 + alunos[k].nota2/2;
    }

    calcularMedia(alunos, 3);

    return 0;
}

float calcularMedia(Aluno alunos[], int amount) {
    float media_geral = 0;
    for (int k = 0; k < amount; k++) {
        media_geral += alunos[k].media;
    }
    media_geral /= amount;
    return media_geral;
}