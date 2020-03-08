#include<stdio.h>
#define Tam 5
void Inserir( int fila[], int *fim, int tam, int valor )
{  fila[(*fim)] = valor;
*fim= (*fim)+1;
}
int Remover(int fila[], int *fim )
{  int excluido, posicaoAux; 
excluido = fila[0];   
*fim = (*fim-1);
for ( posicaoAux=0; posicaoAux < *fim; posicaoAux++ )
{
fila[posicaoAux] = fila[ posicaoAux + 1 ];
}
return excluido;
}
int main()
{ int fila[5];
int fim = 0; //considera que uma fila a ser inciada tem valor de fim = 0    
int valor,cont,op,excluido;int tam=5;
do{  
printf("\n Menu de Opcao \n");
printf("\n 1-Inserir na Fila");
printf("\n 2-Excluir da Fila");
printf("\n 3-Imprimir Fila");
printf("\n 4-Sair");
printf("\n Escolha a opcao: ");
scanf("%d",&op);
switch(op)
{ case 1 : { if(fim<tam )
{printf("Informe o valor a inserir: ");
scanf("%d",&valor);
Inserir(fila,&fim,tam,valor);
}
else
{printf("\n Fila Cheia");
printf("\n");     
}  
break;
}
case 2 : 
{
if (fim>0)
{excluido=Remover(fila,&fim)
;
printf("\n Elemento [%d] Excluido da Fila",excluido);
} 
else
printf("\n Fila Vazia");
printf("\n");    
break;
}
case 3 : {if (fim!=0)
{
printf("________________________\n ");
for (cont =0;cont<fim;cont++)
{
printf("%d  ",fila[cont]);
}
printf("\n________________________");
printf("\n");
}
else
printf("\n Fila Vazia");
printf("\n");
break;
}
case 4 : {printf("\n Saindo do Programa....\n");
break;
}
default : { printf("\n Opção invalida, Escolha outra.");
printf("\n");
}
}
}while (op>=1&&op<=3);
return 0;
}

