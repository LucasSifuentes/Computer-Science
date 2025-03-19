#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int pedir_entero(void){
    int x;
    printf("Ingrese un entero n = ");
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
    int N = pedir_entero();
    int n;

    assert(N > 0);
    
    n = nesimo_primo(N);

    printf("El %d-esimo primo es %d.\n",N,n);

    return 0;
}

/*
Ingrese un entero n = 4
El 4-esimo primo es 7.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero n = 6
El 6-esimo primo es 13.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero n = 20
El 20-esimo primo es 71.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero n = -1
exPrimos: primo.c:49: main: Assertion `N > 0' failed.
Abortado (`core' generado)
*/