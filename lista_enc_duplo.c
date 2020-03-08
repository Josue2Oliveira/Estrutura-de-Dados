#include<stdio.h>
#include "BibLista2.h"

int main(){
    int op, v;
    Nodo *lista = NULL;
    do{
        printf("\nLista: ");
        mostraLista(lista);
        printf("\n\n.:OPCOES:.\n");
        printf("1 - Incluir elemento no inicio\n");
        printf("2 - Incluir elemento ordenado\n");
        printf("3 - Incluir elemento no final\n");
        printf("4 - Excluir elemento do inicio\n");
        printf("5 - Excluir elemento do final\n");
        printf("0 - Sair\n");
        printf("opcao: ");
        scanf("%i",&op);
        switch(op){
            case 1:
                printf("valor: ");
                scanf("%i",&v);
                lista = incluirInicio(lista,v);
                break;
            case 2:
                printf("valor: ");
                scanf("%i",&v);
                lista = incluirOrdenado(lista,v);
                break;
            case 3:
                printf("valor: ");
                scanf("%i",&v);
                lista = incluirFinal(lista,v);
                break;
            case 4:
                lista = excluirInicio(lista);
                break;
            case 5:
                lista = excluirFinal(lista);
                break;
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        system("pause");
        system("cls");
    }while(op!=0);
    return 0;
}
