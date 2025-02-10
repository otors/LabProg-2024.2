#include <stdio.h>

#define STR_MAX 128

typedef struct aluno {
    char nome[STR_MAX];
    float nota1;
    float nota2;
    float media;
} Aluno;

int main(int argc, char const *argv[])
{
    Aluno aluno;
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, STR_MAX, stdin);
    printf("Digite a primeira nota: ");
    scanf("%f", &aluno.nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &aluno.nota2);

    aluno.media = (aluno.nota1+aluno.nota2)/2;
    printf("\nMédia: %.2f\n", aluno.media);

    return 0;
}
