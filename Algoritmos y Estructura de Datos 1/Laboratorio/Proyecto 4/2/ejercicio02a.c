#include <stdio.h>
#include <assert.h>

int pedir_entero(char name){
    int x;
    printf("Ingrese un entero en la variable %c = ",name);
    scanf("%d",&x);
    return x;
}

void imprimir_entero(char name, int x){
    printf("El entero %c es %d.\n",name,x);
}

void programa1(int x, int x0, int y, int y0) {
    printf("\nPrograma 1\n");

    assert(x == x0 && y == y0); //PreCondicion

    x = x + 1;
    y = x0 + y;

    assert(x == x0 + 1 && y == x0 + y0); //PostCondicion

    imprimir_entero('x',x);
    imprimir_entero('y',y);
}

void programa2(int x, int x0, int y, int y0, int z, int z0) {
    printf("\nPrograma 2\n");

    assert(x == x0 && y == y0 && z == z0); //PreCondicion

    x = y0;
    y = x0 + y0 + z0;
    z = y0 + x0;

    assert(x == y0 && y == x0 + y0 + z0 && z == y0 + x0); //PostCondicion

    imprimir_entero('x',x);
    imprimir_entero('y',y);
    imprimir_entero('z',z);
}

int main(void) {
    int x, y, z;
    int x0 = pedir_entero('x');
    int y0 = pedir_entero('y');
    int z0 = pedir_entero('z');

    x = x0;
    y = y0;
    z = z0;

    programa1(x,x0,y,y0);
    programa2(x,x0,y,y0,z,z0);

    return 0;
}

/*
Ingrese un entero en la variable x = 2
Ingrese un entero en la variable y = 2
Ingrese un entero en la variable z = 2

Programa 1
El entero x es 3.
El entero y es 4.

Programa 2
El entero x es 2.
El entero y es 6.
El entero z es 4.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 1
Ingrese un entero en la variable y = 2
Ingrese un entero en la variable z = 3

Programa 1
El entero x es 2.
El entero y es 3.

Programa 2
El entero x es 2.
El entero y es 6.
El entero z es 3.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 10
Ingrese un entero en la variable y = 1
Ingrese un entero en la variable z = -100

Programa 1
El entero x es 11.
El entero y es 11.

Programa 2
El entero x es 1.
El entero y es -89.
El entero z es 11.
*/