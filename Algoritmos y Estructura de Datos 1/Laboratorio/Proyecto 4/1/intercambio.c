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

int main(void){
    int x, y, z;

    int x0 = pedir_entero('x');
    int y0 = pedir_entero('y');
    
    x = x0;
    y = y0;

    assert(x == x0 && y == y0);

    z = x;
    x = y;
    y = z;

    assert(x == y0 && y == x0);

    imprimir_entero('x',x);
    imprimir_entero('y',y);

    return 0;
}

/*
Ingrese un entero en la variable x = 5
Ingrese un entero en la variable y = 10
El entero x es 10.
El entero y es 5.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 10
Ingrese un entero en la variable y = 5
El entero x es 5.
El entero y es 10.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 5
Ingrese un entero en la variable y = 5
El entero x es 5.
El entero y es 5.
*/