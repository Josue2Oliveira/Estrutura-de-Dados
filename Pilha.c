#include<stdio.h>
#define TAMANHO_PILHA 10
void inserirValorPilha( int pilha[], int *topoPilha, int tamanhoMaxPilha, int valor )
{
if ( *topoPilha < tamanhoMaxPilha )
{
pilha[*topoPilha] = valor;*topoPilha = (*topoPilha)+1;
} 
}
int removerValorPilha( int pilha[], int *topoPilha )
{
int retorno = -1;
if ( *topoPilha > 0  ) 
{
*topoPilha = (*topoPilha)-1;
retorno = pilha[*topoPilha];
} 
return retorno;
}
int main()
{ int pilha[TAMANHO_PILHA];
int topoPilha = 0; //considera que uma a ser inciada tem valor de topo = 0  
int valor,cont,op,remo;
do{
printf("\n Menu de Opcao \n");
printf("\n 1-Inserir na Pilha");
printf("\n 2-Excluir da Pilha");
printf("\n 3-Imprimir Pilha");
printf("\n 4-Sair");
printf("\n Escolha a opcao: ");
scanf("%d",&op);
switch(op)
{ case 1 : { if(topoPilha<10)
{printf("Informe o valor a inserir: ");
scanf("%d",&valor);
inserirValorPilha(pilha,&topoPilha,TAMANHO_PILHA,valor);
}
else
{printf("\n Pilha Cheia");
printf("\n");     
}   
break;
}
case 2 : {
if (topoPilha>0)
{remo=removerValorPilha(pilha,&topoPilha);
printf("\n Elemento [%d] Excluido da Pilha",remo);
} 
else
printf("\nPilha Vazia");
printf("\n");     
break;
}
case 3 : {if (topoPilha>0)
{for (cont =0;cont<topoPilha;cont++)
{printf("%d",pilha[cont]);
}
}
else
printf("\n Pilha Vazia");
printf("\n");
break;
}
case 4 : 
{
printf("\n Opção invalida, Escolha outra.");
break;
}
default : { printf("\nOpção invalida, Escolha outra.");
printf("\n");
}
}
}while (op>=1&&op<=3);
return 0;
}

