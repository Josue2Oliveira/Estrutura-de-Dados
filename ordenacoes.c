#include<stdio.h>

void lerVet(int v[], int tam, int pos);
void escreverVet(int v[], int tam);
void Merge(int vetor[], int tamanho);
void MergeSort(int vetor[], int tamanho);
void QuickSort(int vetor[], int inicio, int fim);

int main(){
    int tam = 10;
    int vet[tam];

    lerVet(vet,tam,0);
    system("cls");
    escreverVet(vet,tam);
    printf("\n\n================\n\n");
    MergeSort(vet,tam);
    QuickSort(vet,0,tam-1);
    printf("\n\n================\n\n");
    insertionSort(vet,tam);
    insertionSortR(vet,tam,1);
    selectionSort(vet,tam);
    bubbleSort(vet,tam);
    countSort(vet,tam);
    escreverVet(vet,tam);

    return 0;
}

void lerVet(int v[], int tam, int pos){
    printf("v[%i]: ",pos);
    scanf("%i",&v[pos]);
    if(pos<tam-1)
        lerVet(v, tam, ++pos);
}

void escreverVet(int v[], int tam){
    int i;
    printf("  0   1   2   3   4   5   6   7   8   9\n");
    for(i=0;i<tam;i++)
        printf("|%2d|",v[i]);
}
void insertionSort(int v[], int tam){
    int i,j, aux;
    for(i=1;i<tam;i++){
        aux = v[i];
        j=i-1;
        while(j>=0 && v[j]>aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;

        // imprimir estado temporário
        printf("\npos: %d\n",i);
        escreverVet(v,tam);
        // imprimir estado temporário
    }
}

void insertionSortR(int v[], int tam, int pos){
    int j, aux;
    aux = v[pos];
    j=pos-1;
    while(j>=0 && v[j]>aux){
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = aux;

    // imprimir estado temporário
    printf("\npos: %d\n",pos);
    escreverVet(v,tam);
    // imprimir estado temporário

    if(pos<tam-1)
        insertionSortR(v, tam, pos+1);
}

void trocar(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selectionSort(int v[], int tam){
    int i, j, menor;
    for(i=0;i<tam-1;i++){
        menor = i;
        for(j=i+1;j<tam;j++){
            if(v[j] < v[menor])
                menor = j;
        }
        trocar(&v[menor],&v[i]);

        // imprimir estado temporário
        printf("\npos: %d\n",i);
        escreverVet(v,tam);
        // imprimir estado temporário
    }
}

void bubbleSort(int v[], int tam){
    int i, trocou, ciclo=0;
    do{
        trocou=0;
        printf("\n---------------\n");
        for(i=0;i<tam-1;i++){
            if(v[i]>v[i+1]){
                trocou=1;
                trocar(&v[i],&v[i+1]);
                printf("\ntrocou v[%d] por v[%d]\n",i,i+1);
                escreverVet(v,tam);
            }
        }
        printf("\n---------------\n");
        // imprimir estado temporário
        printf("\nciclo: %d\n",++ciclo);
        escreverVet(v,tam);
        // imprimir estado temporário
        tam--;
    }while(trocou);
}

//MergeSort inicio
void Merge(int vetor[], int tamanho){
	int meio;
	int i, j, k;
	int* aux;

	aux = (int*) malloc(tamanho * sizeof(int));
	if (aux != NULL){
		meio = tamanho/2;
		i = 0;
		j = meio;
		k = 0;
		while(i < meio && j < tamanho){
			if(vetor[i] < vetor[j])
				aux[k++] = vetor[i++];
			else
				aux[k++] = vetor[j++];
		}

		if(i == meio){
			while(j < tamanho)
				aux[k++] = vetor[j++];
		}else{
			while(i < meio)
				aux[k++] = vetor[i++];
		}

		for(i=0; i<tamanho; ++i)
			vetor[i] = aux[i];
		free(aux);
	}
}

void MergeSort(int vetor[], int tamanho){
	int meio;
	if(tamanho > 1){
		meio = tamanho/2;
		MergeSort(vetor, meio);
		printf("vetor+meio = %d + %d = %d\n",vetor,meio,(vetor+meio));
		system("pause");
		MergeSort(vetor + meio, tamanho - meio);
		Merge(vetor, tamanho);
	}
}

// QuickSort
void QuickSort(int vetor[], int inicio, int fim){
	int i = inicio, f = fim;
	printf("Vetor:\n");
	while(i<=fim){
		printf("vetor[%d] = %d;   ",i,vetor[i]);
		i++;
	}
	printf("\n");
	i = inicio, f = fim;

	int pivo = vetor[(i+f)/2]; // escolha do pivo
	printf("pivo = %d\n\n",pivo);
	while(i < f){
		while(vetor[i] < pivo)
			i++;
		while(vetor[f] > pivo)
			f--;
		if(i <= f){
			printf("troca %d e %d\n",vetor[i],vetor[f]);
			int aux = vetor[i];
			vetor[i] = vetor[f];
			vetor[f] = aux;
			i++;
			f--;
		}
	}
	system("pause");

	if(inicio < f){
		printf(" +++++ chama QuickSort(vetor, %d, %d) +++++\n\n",inicio,f);
		QuickSort(vetor, inicio, f);
	}
	if(i < fim){
		printf(" +++++ chama QuickSort(vetor, %d, %d) +++++\n\n",i,fim);
		QuickSort(vetor, i, fim);
	}
}
//ShellSort
void ShellSort(int vetor[], int tamanho){
    int i, j, aux, salto=1;

    do{
        salto = 3*salto+1;
    }while(salto < tamanho);

    do{
        salto /= 3;
        printf("\n==> salto: %i",salto);

        for(i=salto;i<tamanho;i++){
            aux = vetor[i];
            j=i-salto;
            printf("\naux: %i \n",aux, 0, j);
            while(j>=0 && aux < vetor[j]){
                printf("[%i]\n",j);
                vetor[j+salto] = vetor[j];
                escreverVet(vetor,tamanho);
                printf("\n");
                j -= salto;
            }
            vetor[j+salto] = aux;
            escreverVet(vetor,tamanho);
            printf("\n");
        }
    }while(salto > 1);
}
void countSort(int v[], int tam){
    int i, max=v[0], v2[tam];
    for(i=1;i<tam;i++){
        if(v[i]>max)
            max = v[i];
    }

    int aux[max+1];
    for(i=0;i<=max;i++)
        aux[i]=0;

    for(i=0;i<tam;i++)
        aux[v[i]]++;

    for(i=1;i<=max+1;i++)
        aux[i] += aux[i-1];

    for(i=max;i>0;i--)
        aux[i] = aux[i-1];
    aux[0]=0;

    for(i=0;i<tam;i++){
        v2[aux[v[i]]] = v[i];
        aux[v[i]]++;
    }
