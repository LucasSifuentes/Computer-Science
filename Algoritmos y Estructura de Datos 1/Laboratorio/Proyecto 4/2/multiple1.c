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
    int x, y;
    int x0 = pedir_entero('x');
    int y0 = pedir_entero('y');

    x = x0;
    y = y0;

    assert(x == x0 && y == y0); //PreCondicion

    x = x + 1;
    y = x0 + y;

    assert(x == x0 + 1 && y == x0 + y0); //PostCondicion

    imprimir_entero('x',x);
    imprimir_entero('y',y);

    return 0;
}

/*
Ingrese un entero en la variable x = 2
Ingrese un entero en la variable y = 5
El entero x es 3.
El entero y es 7.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 4
Ingrese un entero en la variable y = 4
El entero x es 5.
El entero y es 8.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 10
Ingrese un entero en la variable y = 4
El entero x es 11.
El entero y es 14.
*/