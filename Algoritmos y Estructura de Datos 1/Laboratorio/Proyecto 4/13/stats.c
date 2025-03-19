#include <stdio.h>
#include <assert.h>
#include <limits.h>

int pedir_longitud_arreglo(char name){
    int x;
    printf("Ingrese la longitud del arreglo %c = ",name);
    scanf("%d",&x);
    assert(x > 0);
    return x;
}

void pedir_arreglo_esp(int tam, float a[]) {
    int i = 0;

    while (i < tam){
        printf("Ingrese, en la posicion %d del arreglo, el entero = ",i);
        scanf("%f",&a[i]);
        i = i + 1;
    }
    printf("\n");
}

typedef struct {
    float maximo, minimo, promedio;
} datos_t;

datos_t stats(int tam, float a[]) {
    assert(a[0]);
    
    datos_t info;
    info.maximo = INT_MIN;
    info.minimo = INT_MAX;
    int i = 0;
    float sum = 0;

    while (i < tam) {
        if (info.maximo < a[i]) {
            info.maximo = a[i];
        } 
        if (info.minimo > a[i]) {
            info.minimo = a[i];
        }
        sum = sum + a[i];
        i = i + 1;
    }

    info.promedio = sum/tam;
    
    return info;
}

int main(void) {
    int tam = pedir_longitud_arreglo('a');
    float a[tam];
    datos_t info;

    pedir_arreglo_esp(tam, a);
    info = stats(tam, a);

    printf("El Minimo del arreglo es %f.\nEl Maximo del arreglo es %f.\nEl Promedio de los elementos del arreglo es %f.\n",info.minimo,info.maximo,info.promedio);
    return 0;
}

/*
Ingrese la longitud del arreglo a = 5
Ingrese, en la posicion 0 del arreglo, el entero = 3.5
Ingrese, en la posicion 1 del arreglo, el entero = 4.5
Ingrese, en la posicion 2 del arreglo, el entero = 7.5
Ingrese, en la posicion 3 del arreglo, el entero = 8.5
Ingrese, en la posicion 4 del arreglo, el entero = 1.5

El Minimo del arreglo es 1.500000.
El Maximo del arreglo es 8.500000.
El Promedio de los elementos del arreglo es 5.100000.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese la longitud del arreglo a = 3
Ingrese, en la posicion 0 del arreglo, el entero = 5.43
Ingrese, en la posicion 1 del arreglo, el entero = 6.345
Ingrese, en la posicion 2 del arreglo, el entero = 3.5456

El Minimo del arreglo es 3.545600.
El Maximo del arreglo es 6.345000.
El Promedio de los elementos del arreglo es 5.106866.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese la longitud del arreglo a = 3
Ingrese, en la posicion 0 del arreglo, el entero = 9.9999
Ingrese, en la posicion 1 del arreglo, el entero = 1.12    
Ingrese, en la posicion 2 del arreglo, el entero = 0.00002

El Minimo del arreglo es 0.000020.
El Maximo del arreglo es 9.999900.
El Promedio de los elementos del arreglo es 3.706640.
*/