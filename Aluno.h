#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

typedef struct str_aluno Aluno;

Aluno *novoAluno(char n[], short int qtd);
Aluno *apagarAluno(Aluno *a);
void informarNotas(Aluno *a, float n1, float n2, float n3);
void informarPF(Aluno *a, float nota);
void informarNome(Aluno *a, char n[]);
void informarAulas(Aluno *a, short int qtd);
void informarFaltas(Aluno *a, short int qtd);
void mostrarAluno(Aluno *a);
float media(Aluno *a);
float notaFinal(Aluno *a);
void situacao(Aluno *a)

#endif // ALUNO_H_INCLUDED
