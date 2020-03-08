#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "Aluno.h";

typedef struct str_aluno{
    char nome[20];
    float n1, n2, n3, pf;
    short int aulas, faltas;
} Aluno;

Aluno *novoAluno(char n[], short int qtd){
    Aluno *a = (Aluno*) malloc(sizeof(Aluno));
    strcpy(a->nome, n);
    a->aulas = qtd;
    a->n1 = -1;
    a->n2 = -1;
    a->n3 = -1;
    a->pf = -1;
    return a;
}

Aluno *apagarAluno(Aluno *a){
    free(a);
    return NULL;
}

void informarNotas(Aluno *a, float n1, float n2, float n3){
    a->n1 = n1;
    a->n2 = n2;
    a->n3 = n3;
}

void informarPF(Aluno *a, float nota){
    printf("PF: ");
    a->pf = nota;
}

void informarNome(Aluno *a, char n[]){
    strcpy(a->nome,n);
}

void informarAulas(Aluno *a, short int qtd){
    a->aulas = qtd;
}

void informarFaltas(Aluno *a, short int qtd){
    a->faltas = qtd;
}

float media(Aluno *a){
    return (a->n1 + a->n2 + a->n3)/3;
}

float notaFinal(Aluno *a){
    if(media(a) >= 7)
        return media(a);
    else
        return (media(a) + a->pf)/2;
}

void situacao(Aluno *a){
    if(a->faltas > 0.25 * a->aulas){
        printf("situacao: REPROVADO POR FREQUENCIA\n");
    }else{
        if(media(a) < 7)
            if(notaFinal(a) < 5)
                printf("situacao: REPROVADO COM PF\n");
            else
                printf("situacao: APROVADO COM PF\n");
        else
            printf("situacao: APROVADO POR MEDIA\n");
    }
}

void mostrarAluno(Aluno *a){
    printf("\nNome: %s\n", a->nome);
    if(a->aulas >= 0)
        printf("Aulas (faltas): %d (%d)\n", a->aulas, a->faltas);
    else
        printf("Aulas (faltas): Nao informado\n");

    if(a->n1 >= 0)
        printf("Nota 1: %.2f\n", a->n1);
    else
        printf("Nota 1: Nao informado\n");

    if(a->n2 >= 0)
        printf("Nota 2: %.2f\n", a->n2);
    else
        printf("Nota 2: Nao informado\n");

    if(a->n3 >= 0)
        printf("Nota 3: %.2f\n", a->n3);
    else
        printf("Nota 3: Nao informado\n");

    if(a->faltas > 0.25*a->aulas){
       situacao(a);
    }else{
        if(a->n1 >= 0 & a->n2 >= 0 & a->n3 >= 0){
            printf("Media: %.2f\n",media(a));
            if(media(a) < 7){
                if(a->pf>=0){
                    printf("PF: %.2f\n",a->pf);
                    printf("NF: %.2f\n",notaFinal(a));
                    situacao(a);
                }else{
                    printf("PF: Nao informada\n");
                    printf("NF: Não calculada\n");
                }
            }else{
                printf("NF: %.2f\n",notaFinal(a));
                situacao(a);
            }
        }else{
            printf("Media: Nao calculada\n");
            printf("NF: Nao calculada\n");
        }
    }
}
