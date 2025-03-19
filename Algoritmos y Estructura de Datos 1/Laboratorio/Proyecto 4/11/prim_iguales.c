#include <stdio.h>
#define Tam 3

void pedir_arreglo(int tam, int a[]) {
    int i = 0;

    while (i < tam){
        printf("Ingrese, en la posicion %d del arreglo, el entero = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
    printf("\n");
}

int prim_iguales(int tam, int a[]) {
    int i = 0;
    int cos = 0;

    while (i < tam) {
        if (a[0] != a[i]) {
            return cos;
        }
        cos = cos + 1;
        i = i + 1;
    }
    
    return cos;
}

int main(void) {
    int a[Tam];
    int iguales;

    pedir_arreglo(Tam, a);
    iguales = prim_iguales(Tam, a);

    if (iguales == 1) {
        printf("No hay un tramo inicial con elementos iguales en el arreglo.\n");
    } else {
        printf("La longitud del tramo inicial con elementos iguales del arreglo es %d.\n",iguales);

    }
    
    return 0;
}

/*
Ingrese, en la posicion 0 del arreglo, el entero = 2
Ingrese, en la posicion 1 del arreglo, el entero = 3
Ingrese, en la posicion 2 del arreglo, el entero = 2

No hay un tramo inicial con elementos iguales en el arreglo.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 1
Ingrese, en la posicion 1 del arreglo, el entero = 1
Ingrese, en la posicion 2 del arreglo, el entero = 1

La longitud del tramo inicial con elementos iguales del arreglo es 3.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 1
Ingrese, en la posicion 1 del arreglo, el entero = 2
Ingrese, en la posicion 2 del arreglo, el entero = 3

No hay un tramo inicial con elementos iguales en el arreglo.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 1
Ingrese, en la posicion 1 del arreglo, el entero = 1
Ingrese, en la posicion 2 del arreglo, el entero = 2

La longitud del tramo inicial con elementos iguales del arreglo es 2.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 2
Ingrese, en la posicion 1 del arreglo, el entero = 3
Ingrese, en la posicion 2 del arreglo, el entero = 3

No hay un tramo inicial con elementos iguales en el arreglo.
*/