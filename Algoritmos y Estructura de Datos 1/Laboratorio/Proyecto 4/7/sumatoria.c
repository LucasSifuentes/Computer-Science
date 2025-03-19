#include <stdio.h>
#define Tam 3

void pedir_arreglo(int tam, int a[]) {
    int i = 0;

    while (i < tam){
        printf("Ingrese, en la posicion %d del arreglo, el entero = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

int sumatoria(int tam, int a[]) {
    int i = 0;
    int res = 0;

    while (i < tam) {
        res = res + a[i];
        i = i + 1;    
    }

    return res;
}

int main(void) {
    int a[Tam], tam;

    pedir_arreglo(Tam, a);
    tam = sumatoria(Tam, a);

    printf("La sumatoria del arreglo es %d.\n",tam);

    return 0;
}

/*
Ingrese, en la posicion 0 del arreglo, el entero = 1
Ingrese, en la posicion 1 del arreglo, el entero = 2
Ingrese, en la posicion 2 del arreglo, el entero = 3
La sumatoria del arreglo es 6.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 10
Ingrese, en la posicion 1 del arreglo, el entero = 20
Ingrese, en la posicion 2 del arreglo, el entero = 30
La sumatoria del arreglo es 60.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 4
Ingrese, en la posicion 1 del arreglo, el entero = 76
Ingrese, en la posicion 2 del arreglo, el entero = 2
La sumatoria del arreglo es 82.
*/