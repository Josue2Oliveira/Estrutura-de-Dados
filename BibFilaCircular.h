#include<string.h>

typedef struct nodo{
    int valor;
    struct nodo *prox;
} Nodo;

Nodo* criarNodo();
Nodo* incluir(Nodo* fila, int v);
Nodo* excluir(Nodo* fila);
void mostraFila(Nodo* fila);

Nodo* criarNodo(){
    return (Nodo*)malloc(sizeof(Nodo));
}

Nodo* excluir(Nodo* fila){
    if(fila == NULL)
        printf("Fila Vazia\n");
    else if(fila == fila->prox){
        free(fila);
        fila = NULL;
    }else{
        Nodo *aux = fila;
        while(aux->prox != fila)
            aux = aux->prox;
        fila = fila->prox;
        free(aux->prox);
        aux->prox = fila;
    }
    return fila;
}

void mostraFila(Nodo* fila){
    if(fila != NULL){
        Nodo *aux = fila;
        printf("%i --> ",fila->valor);
        while(aux->prox != fila){
            aux = aux->prox;
            printf("%i --> ",aux->valor);
        }
    }
    printf("#");
}

Nodo* incluir(Nodo* fila, int v){
    Nodo *novoNodo = criarNodo();
    novoNodo->valor = v;
    if(fila == NULL)
        fila = novoNodo;
    else{
        Nodo *aux = fila;
        while(aux->prox != fila)
            aux = aux->prox;
        aux->prox = novoNodo;
    }
    novoNodo->prox = fila;
    return fila;
}
