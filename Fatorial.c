#include<stdio.h>
    int fatorial(int n);
    int fatrec(int n);
    int fibonacci(int n);
    int PA(int a1, int n, int r);
    int main()
        {

    int fat, fib,n,c;
    printf("Insira um valor para o qual deseja calcular seu fatorial: ");
    scanf("%d", &n);
    fat=fatorial(n);
    fat=fatrec(n);
    fib=fibonacci(n);
    printf("\n Fatorial : %d", fat);
    printf("\n Fibonaci : %d \n", fib);

    int a1,r;   
    printf("Digite o primeiro termo: ");
    scanf("%d",&a1); 
    printf("Digite a razao: ");
    scanf("%d",&r);  
    printf("Digite o n termo: ");
    scanf("%d",&n);
    printf("O termo n é: %d \n",PA(a1,n,r) );

    return 0;
    }
    int fatrec(int n)
    {int c;
    if (n==0 )
    {return 1;
    }
    else
    {return n *fatrec(n-1);
    }
    }
    int fatorial(int n) 
    {int c;
    if (n==0 )
    {return 1;
    }
    else
    {for(c = n; c > 1; c--)
    {n = n * (c-1);
    }
    return n;
    }
    }
    int PA(int a1, int n, int r) {
    if(n==1)
    return a1;
    return PA(a1 + r,n -1,r);
    }
    int fibonacci(int n)
    { int a;
    if(n==1 || n==2)
    {
    return 1;
    }
    else
    {
    return fibonacci(n-1) + fibonacci(n-2);
    }
    }

