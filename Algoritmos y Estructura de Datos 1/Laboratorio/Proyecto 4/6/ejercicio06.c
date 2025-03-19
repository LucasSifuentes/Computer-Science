#include <stdio.h>
#include <assert.h>

int pedir_longitud_arreglo(char name){
    int x;
    printf("Ingrese la longitud del arreglo %c = ",name);
    scanf("%d",&x);
    assert(x > 0);
    return x;
}

void pedir_arreglo(int n_max, int a[]) {
    int i = 0;

    while (i < n_max){
        printf("Ingrese, en la posicion %d del arreglo, el entero = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

void imprimir_arreglo(int n_max, int a[]) {
    int i = 0;

    while (i < n_max){
        printf("El valor del arreglo en la posicion %d es %d.\n",i,a[i]);
        i = i + 1;
    }   
}

int main(void) {
    int n_max = pedir_longitud_arreglo('a');
    int a[n_max];

    pedir_arreglo(n_max, a);
    imprimir_arreglo(n_max, a);

    return 0;
}

/*
Ingrese la longitud del arreglo a = 0
ex06: ejercicio06.c:8: pedir_longitud_arreglo: Assertion `x > 0' failed.
Abortado (`core' generado)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese la longitud del arreglo a = -2
ex06: ejercicio06.c:8: pedir_longitud_arreglo: Assertion `x > 0' failed.
Abortado (`core' generado)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese la longitud del arreglo a = 3
Ingrese, en la posicion 0 del arreglo, el entero = 1
Ingrese, en la posicion 1 del arreglo, el entero = 2
Ingrese, en la posicion 2 del arreglo, el entero = 3
El valor del arreglo en la posicion 0 es 1.
El valor del arreglo en la posicion 1 es 2.
El valor del arreglo en la posicion 2 es 3.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese la longitud del arreglo a = 2
Ingrese, en la posicion 0 del arreglo, el entero = 5
Ingrese, en la posicion 1 del arreglo, el entero = 10
El valor del arreglo en la posicion 0 es 5.
El valor del arreglo en la posicion 1 es 10.
*/