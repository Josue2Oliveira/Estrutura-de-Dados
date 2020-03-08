#include<stdio.h>
#include "BibFilaCircular.h"

int main(){
    int op, v;
    Nodo *fila = NULL;
    do{
        printf("\nFila: ");
        mostraFila(fila);
        printf("\n\n.:OPCOES:.\n");
        printf("1 - Incluir\n");
        printf("2 - Excluir\n");
        printf("0 - Sair\n");
        printf("opcao: ");
        scanf("%i",&op);
        switch(op){
            case 1:
                printf("valor: ");
                scanf("%i",&v);
                fila = incluir(fila,v);
                break;
            case 2:
                fila = excluir(fila);
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
