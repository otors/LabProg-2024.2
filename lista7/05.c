#include <stdio.h>

#define STR_MAX 128

typedef struct disciplina {
    char nome[STR_MAX];
    int codigo;
    struct professor {
        char nome[STR_MAX];
        char email[STR_MAX];
    };
} Disciplina;

