#include <stdio.h>
#include <assert.h>

int pedir_entero(char name){
    int x;
    printf("Ingrese un entero en la variable %c = ",name);
    scanf("%d",&x);   
    return x;
}

int main(void){
    int x = pedir_entero('x');
    int y = pedir_entero('y');
    int min;

    if (x<=y){
        min = x;
    } else {
        min = y;
    }
    
    assert(min <= x && min <= y && (min == x || min == y));

    printf("El minimo entero entre %d y %d es %d.\n",x,y,min);

    return 0;
}

/*
Ingrese un entero en la variable x = 3
Ingrese un entero en la variable y = 4
El minimo entero entre 3 y 4 es 3.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = -10
Ingrese un entero en la variable y = 5
El minimo entero entre -10 y 5 es -10.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 5
Ingrese un entero en la variable y = 5
El minimo entero entre 5 y 5 es 5.
*/