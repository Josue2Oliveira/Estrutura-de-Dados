#include<string.h>

typedef struct nodo{
    struct nodo *ant;
    int valor;
    struct nodo *prox;
} Nodo;

Nodo* criarNodo();
Nodo* incluirInicio(Nodo* lista, int v);
Nodo* excluirInicio(Nodo* lista);
Nodo* incluirFinal(Nodo* lista, int v);
Nodo* excluirFinal(Nodo* lista);
Nodo* incluirOrdenado(Nodo* lista, int v);
void mostraLista(Nodo* lista);

Nodo* criarNodo(){
    return (Nodo*)malloc(sizeof(Nodo));
}

Nodo* incluirInicio(Nodo* lista, int v){
    Nodo *novoNodo = criarNodo();
    novoNodo->valor = v;
    novoNodo->ant = NULL;
    novoNodo->prox = lista;
    return novoNodo;
}

Nodo* excluirInicio(Nodo* lista){
    if(lista == NULL)
        printf("Lista Vazia\n");
    else{
        Nodo *aux = lista;
        lista = lista->prox;
        if(lista != NULL)
            lista->ant = NULL;
        free(aux);
    }
    return lista;
}

void mostraLista(Nodo* lista){
    if(lista == NULL)
        printf("#");
    else{
        printf("%i --> ",lista->valor);
        mostraLista(lista->prox);
    }
}

Nodo* incluirFinal(Nodo* lista, int v){
    Nodo *novoNodo = criarNodo();
    novoNodo->valor = v;
    novoNodo->ant = NULL;
    novoNodo->prox = NULL;

    if(lista == NULL)
        lista = novoNodo;
    else{
        Nodo *aux = lista;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novoNodo;
        novoNodo->ant = aux;
    }
    return lista;
}

Nodo* excluirFinal(Nodo* lista){
    if(lista == NULL)
        printf("Lista Vazia\n");
    else{
        if(lista->prox == NULL){
            free(lista);
            lista = NULL;
        }else{
            Nodo *ultimo = lista;
            while(ultimo->prox != NULL)
                ultimo = ultimo->prox;
            ultimo->ant->prox = NULL;
            free(ultimo);
        }
    }
    return lista;
}

Nodo* incluirOrdenado(Nodo* lista, int v){
    Nodo *novoNodo = criarNodo();
    novoNodo->valor = v;
    if(lista == NULL){
        lista = novoNodo;
        novoNodo->ant = NULL;
        novoNodo->prox = NULL;
    }else if(lista->valor > novoNodo->valor){
        novoNodo->ant = lista->ant;
        novoNodo->prox = lista;
        lista->ant = novoNodo;
        lista = novoNodo;
    }else{
        if(lista->prox == NULL){
            lista->prox = novoNodo;
            novoNodo->ant = lista;
            novoNodo->prox = NULL;
        }else{
            Nodo *aux = lista;
            while(aux->valor < v && aux->prox != NULL)
                aux = aux->prox;
            if(aux->valor < v){
                novoNodo->prox = aux->prox;
                novoNodo->ant = aux;
                aux->prox = novoNodo;
            }else{
                aux = aux->ant;
                novoNodo->prox = aux->prox;
                novoNodo->ant = aux;
                aux->prox = novoNodo;
                novoNodo->prox->ant = novoNodo;
            }
        }
    }
    return lista;
}
