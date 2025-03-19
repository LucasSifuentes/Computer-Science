#include <stdio.h>
#include <stdbool.h>

int pedir_entero(void){
    int x;
    printf("Ingrese un entero positivo en n = ");
    scanf("%d",&x);
    return x;
}

bool es_primo(int n) {
    int i = 2;

    if (n <= 1) {
        return false;
    }

    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i = i + 1;
    }

    return true;
}

int nesimo_primo(int N) {
    int i = 0;
    int j = i;
    int prim;

    while (j != N) {
        if (es_primo(i)) {
            j = j + 1;
            prim = i;
        }
        i = i + 1;        
    }

    return prim;
}

int main(void) {
    int N, n;

    N = pedir_entero();

    if (N <= 0) {
        printf("\nTiene que ser positivo.\n");
        do {
            printf("Intentelo denuevo.\n");
            N = pedir_entero(); 
        } while (N <= 0);
    }
    
    n = nesimo_primo(N);

    printf("\nEl %d-esimo primo es %d.\n",N,n);

    return 0;
}

/*
Ingrese un entero positivo en n = 3

El 3-esimo primo es 5.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero positivo en n = 4

El 4-esimo primo es 7.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero positivo en n = 5

El 5-esimo primo es 11.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero positivo en n = -1

Tiene que ser positivo.
Intentelo denuevo.
Ingrese un entero en n = -4
Intentelo denuevo.
Ingrese un entero en n = 4

El 4-esimo primo es 7.
*/