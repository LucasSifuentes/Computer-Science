#include <stdio.h>
#include <stdbool.h>
#define Tam 3

void pedir_arreglo(int n_max, int a[]) {
    int i = 0;

    while (i < n_max){
        printf("Ingrese, en la posicion %d del arreglo, el entero = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

bool todos_pares(int tam, int a[]) {
    int i = 0;

    while (i < tam) {
        if (a[i] % 2 != 0) {
            return false;
        }
        i = i + 1;
    }
    
    return true;
}

bool existe_multiplo(int m, int tam, int a[]) {
    int i = 0;

    while (i < tam) {
        if (a[i] % m == 0) {
            return true;
        }
        i = i + 1;
    }
    
    return false;
}

int main(void) {
    int a[Tam];
    int funcion, m;

    pedir_arreglo(Tam, a); 

    printf("\nPresione 1 para ver si los Elementos de su arreglo son Par.\nPresione 2 para ver si hay algun Elemento de su arreglo es Multiplo de un numero que usted elija.\n");
    printf("Elija = ");
    scanf("%d",&funcion);

    if (funcion == 1) {

        if (todos_pares(Tam, a)) {
            printf("\nTodos los elementos de su arreglo son Par.\n");
        } else {
            printf("\nNo todos los elementos de su arreglo son Par.\n");
        }

    } else if (funcion == 2) {
        printf("\nIngrese un entero para buscar si el arreglo tiene multiplos = ");
        scanf("%d",&m);

        if (existe_multiplo(m, Tam, a)) {
            printf("\nExiste un multiplo de %d en el Arreglo.\n",m);
        } else {
            printf("\nNo existe un multiplo de %d en el Arreglo.\n",m);
        }

    } else {
        printf("No a ingresado una opcion valida.");
    }
    
    return 0;
}

/*
Ingrese, en la posicion 0 del arreglo, el entero = 1
Ingrese, en la posicion 1 del arreglo, el entero = 2
Ingrese, en la posicion 2 del arreglo, el entero = 3

Presione 1 para ver si los Elementos de su arreglo son Par.
Presione 2 para ver si hay algun Elemento de su arreglo es Multiplo de un numero que usted elija.
Elija = 1

No todos los elementos de su arreglo son Par.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 2
Ingrese, en la posicion 1 del arreglo, el entero = 2
Ingrese, en la posicion 2 del arreglo, el entero = 2

Presione 1 para ver si los Elementos de su arreglo son Par.
Presione 2 para ver si hay algun Elemento de su arreglo es Multiplo de un numero que usted elija.
Elija = 1

Todos los elementos de su arreglo son Par.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 4
Ingrese, en la posicion 1 del arreglo, el entero = 8
Ingrese, en la posicion 2 del arreglo, el entero = 6

Presione 1 para ver si los Elementos de su arreglo son Par.
Presione 2 para ver si hay algun Elemento de su arreglo es Multiplo de un numero que usted elija.
Elija = 2

Ingrese un entero para buscar si el arreglo tiene multiplos = 2

Existe un multiplo de 2 en el Arreglo.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 4
Ingrese, en la posicion 1 del arreglo, el entero = 8
Ingrese, en la posicion 2 del arreglo, el entero = 9

Presione 1 para ver si los Elementos de su arreglo son Par.
Presione 2 para ver si hay algun Elemento de su arreglo es Multiplo de un numero que usted elija.
Elija = 2

Ingrese un entero para buscar si el arreglo tiene multiplos = 2

Existe un multiplo de 2 en el Arreglo.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, el entero = 3
Ingrese, en la posicion 1 del arreglo, el entero = 5
Ingrese, en la posicion 2 del arreglo, el entero = 7

Presione 1 para ver si los Elementos de su arreglo son Par.
Presione 2 para ver si hay algun Elemento de su arreglo es Multiplo de un numero que usted elija.
Elija = 2

Ingrese un entero para buscar si el arreglo tiene multiplos = 2

No existe un multiplo de 2 en el Arreglo.
*/