#include <stdio.h>
#include <assert.h>

int pedir_entero(char name){
    int x;
    printf("Ingrese un entero en la variable %c = ",name);
    scanf("%d",&x);   
    return x;
}

int main(void){
    int x, abs;

    x = pedir_entero('x');

    if (x<0){
        abs = -x;
    } else {
        abs = x;
    }
    
    assert(abs >= 0);

    printf("El valor absoluto de %d es %d.\n",x,abs);

    return 0;
}

/*
Ingrese un entero en la variable x = 5
El valor absoluto de 5 es 5.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = -5
El valor absoluto de -5 es 5.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero en la variable x = 0
El valor absoluto de 0 es 0.
*/