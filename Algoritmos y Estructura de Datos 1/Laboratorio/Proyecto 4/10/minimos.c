#include <stdio.h>
#include <limits.h>
#include <assert.h>
#define Tam 3

int pedir_entero(char name){
    int x;
    printf("Ingrese un entero en la variable %c = ",name);
    scanf("%d",&x);
    printf("\n");
    return x;
}

void pedir_arreglo(int tam, int a[]) {
    int i = 0;

    while (i < tam){
        printf("Ingrese, en la posicion %d del arreglo, el entero = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
    printf("\n");
}

int minimo_pares(int tam, int a[]) {
    int i = 0;
    int res = INT_MAX;

    while (i < tam) {
        if(a[i] < res && a[i] % 2 == 0) {
            res = a[i];
        }
        i = i + 1;
    }

    return res;
}

int minimo_impares(int tam, int a[]) {
    int i = 0;
    int res = INT_MAX;

    while (i < tam) {
        if (a[i] < res && a[i] % 2 != 0) {
            res = a[i];
        }
        i = i + 1;
    }
    
    return res;
}

int minimo(int a, int b) {
    if (a > b) {
        a = b;
    }
    return a;
}

int main(void) {
    int a[Tam];
    int min, minPar, minImpar;

    pedir_arreglo(Tam, a);

    minPar = minimo_pares(Tam, a);
    minImpar = minimo_impares(Tam, a);
    min = minimo(minPar, minImpar);
    
    printf("El elemento Par Minimo del arreglo es %d, y el Impar Minimo es %d.\n",minPar,minImpar);
    printf("Y el elemento minimo del arreglo es %d.\n",min);

    return 0;
}

/*
Ingrese, en la posicion 0 del arreglo, el entero = 1
Ingrese, en la posicion 1 del arreglo, el entero = 2
Ingrese, en la posicion 2 del arreglo, el entero = 3

El elemento Par Minimo del arreglo es 2, y el Impar Minimo es 1.
Y el elemento minimo del arreglo es 1.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 6
Ingrese, en la posicion 1 del arreglo, el entero = 5
Ingrese, en la posicion 2 del arreglo, el entero = 8

El elemento Par Minimo del arreglo es 6, y el Impar Minimo es 5.
Y el elemento minimo del arreglo es 5.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 10
Ingrese, en la posicion 1 del arreglo, el entero = 3
Ingrese, en la posicion 2 del arreglo, el entero = 2

El elemento Par Minimo del arreglo es 2, y el Impar Minimo es 3.
Y el elemento minimo del arreglo es 2.
*/