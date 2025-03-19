#include <stdio.h>
#include <stdbool.h>
#define Tam 3

typedef char clave_t;

typedef int valor_t;

typedef struct {
    clave_t clave;
    valor_t valor;
} asoc;

asoc pedir_entero_esp(void){
    asoc x;
    printf("Ingrese la clave para buscar = ");
    scanf(" %c",&x.clave);
    printf("\n");
    return x;
}

void pedir_arreglo_esp(int tam, asoc a[]) {
    int i = 0;
    while (i < tam){
        printf("Ingrese, en la posicion %d del arreglo, la clave = ",i);
        scanf(" %c",&a[i].clave);
        printf("Ingrese el valor = ");
        scanf("%d",&a[i].valor);
        i = i + 1;
    }    
    printf("\n");
}

bool asoc_existe(int tam, asoc a[], clave_t c) {
    int i = 0;

    while (i < tam) {
        if (a[i].clave == c) {
            return true;
        }
        i = i + 1;
    }
    return false;
}

int main(void) {
    asoc a[Tam];
    pedir_arreglo_esp(Tam, a); 

    asoc c = pedir_entero_esp();
    
    if (asoc_existe(Tam, a, c.clave)) {
        printf("La clave %c, existe en el Arreglo.\n",c.clave);
    } else {
        printf("La clave %c, no existe en el Arreglo.\n",c.clave);
    }

    return 0;
}

/*
Ingrese, en la posicion 0 del arreglo, la clave = P
Ingrese el valor = 1
Ingrese, en la posicion 1 del arreglo, la clave = S
Ingrese el valor = 2
Ingrese, en la posicion 2 del arreglo, la clave = I
Ingrese el valor = 3

Ingrese la clave para buscar = I

La clave I, existe en el Arreglo.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, la clave = P
Ingrese el valor = 1
Ingrese, en la posicion 1 del arreglo, la clave = S
Ingrese el valor = 2
Ingrese, en la posicion 2 del arreglo, la clave = I
Ingrese el valor = 3

Ingrese la clave para buscar = Q

La clave Q, no existe en el Arreglo.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese, en la posicion 0 del arreglo, la clave = P
Ingrese el valor = 1
Ingrese, en la posicion 1 del arreglo, la clave = S
Ingrese el valor = 2
Ingrese, en la posicion 2 del arreglo, la clave = I
Ingrese el valor = 3

Ingrese la clave para buscar = S

La clave S, existe en el Arreglo.
*/