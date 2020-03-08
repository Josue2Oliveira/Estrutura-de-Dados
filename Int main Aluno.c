#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Aluno.c";

int main(){
    char nome[20];
    int aulas, faltas;

    printf("Nome do aluno: ");
    scanf("%s",nome);
    printf("Aulas: ");
    fflush(stdin);
    fgets(nome,20,stdin);
    Aluno *a = novoAluno(nome, aulas);
    printf("Faltas: ");
    scanf("%d",&faltas);
    informarFaltas(a,faltas);
    mostrarAluno(a);

    system("pause");

    printf("Corrigir nome: ");
    fflush(stdin);
    fgets(nome,20,stdin);
    informarNome(a,nome);
    mostrarAluno(a);

    printf("Endereco: %d\n",a);
    a = apagarAluno(a);

    //printf("Aulas: %d\n",a->aulas);
    return 0;
}
