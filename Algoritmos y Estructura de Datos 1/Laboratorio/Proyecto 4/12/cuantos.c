#include <stdio.h>
#define Tam 5

int pedir_entero_esp(void){
    int x;
    printf("Ingrese un elemento para buscar elementos minimos, iguales o mayores en el arreglo = ");
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

typedef struct {
    int menores, iguales, mayores;
} comp_t;

comp_t cuantos(int tam, int a[], int elem) {
    comp_t comp;
    int i = 0;

    comp.menores = 0;
    comp.iguales = 0;
    comp.mayores = 0;

    while (i < tam) {
        if (a[i] < elem) {
            comp.menores = comp.menores + 1;
        } else if (a[i] == elem) {
            comp.iguales = comp.iguales + 1;
        } else if (a[i] > elem) {
            comp.mayores = comp.mayores + 1;
        }
        i = i + 1;
    }
    
    return comp;
}

int main(void) {
    int a[Tam];
    int elem = pedir_entero_esp();
    comp_t comp;

    pedir_arreglo(Tam, a);

    comp = cuantos(Tam, a, elem);

    printf("Hay %d elementos minimos a %d.\nHay %d elementos iguales a %d.\nHay %d elementos mayores a %d.\n",comp.menores,elem,comp.iguales,elem,comp.mayores, elem);

    return 0;
}

/*
Ingrese un elemento para buscar elementos minimos, iguales o mayores en el arreglo = 3

Ingrese, en la posicion 0 del arreglo, el entero = 1
Ingrese, en la posicion 1 del arreglo, el entero = 2
Ingrese, en la posicion 2 del arreglo, el entero = 3
Ingrese, en la posicion 3 del arreglo, el entero = 3
Ingrese, en la posicion 4 del arreglo, el entero = 4

Hay 2 elementos minimos a 3.
Hay 2 elementos iguales a 3.
Hay 1 elementos mayores a 3.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un elemento para buscar elementos minimos, iguales o mayores en el arreglo = 3

Ingrese, en la posicion 0 del arreglo, el entero = 3       
Ingrese, en la posicion 1 del arreglo, el entero = 3
Ingrese, en la posicion 2 del arreglo, el entero = 3
Ingrese, en la posicion 3 del arreglo, el entero = 3
Ingrese, en la posicion 4 del arreglo, el entero = 4

Hay 0 elementos minimos a 3.
Hay 4 elementos iguales a 3.
Hay 1 elementos mayores a 3.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un elemento para buscar elementos minimos, iguales o mayores en el arreglo = 1

Ingrese, en la posicion 0 del arreglo, el entero = 2
Ingrese, en la posicion 1 del arreglo, el entero = 3
Ingrese, en la posicion 2 del arreglo, el entero = 0
Ingrese, en la posicion 3 del arreglo, el entero = 4
Ingrese, en la posicion 4 del arreglo, el entero = 5

Hay 1 elementos minimos a 1.
Hay 0 elementos iguales a 1.
Hay 4 elementos mayores a 1.
*/