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

int main(void) {
    int x, y, z;
    int x0 = pedir_entero('x');
    int y0 = pedir_entero('y');
    int z0 = pedir_entero('z');

    x = x0;
    y = y0;
    z = z0;

    assert(x == x0 && y == y0 && z == z0); //PreCondicion

    x = y0;
    y = x0 + y0 + z0;
    z = y0 + x0;

    assert(x == y0 && y == x0 + y0 + z0 && z == y0 + x0); //PostCondicion

    imprimir_entero('x',x);
    imprimir_entero('y',y);
    imprimir_entero('z',z);

    return 0;
}

/*
Ingrese un entero en la variable x = 2
Ingrese un entero en la variable y = 3
Ingrese un entero en la variable z = 4
El entero x es 3.
El entero y es 9.
El entero z es 5.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 4
Ingrese un entero en la variable y = 4
Ingrese un entero en la variable z = 4
El entero x es 4.
El entero y es 12.
El entero z es 8.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 10
Ingrese un entero en la variable y = 1
Ingrese un entero en la variable z = -100
El entero x es 1.
El entero y es -89.
El entero z es 11.
*/