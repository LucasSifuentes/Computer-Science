#include <stdio.h>
#include <assert.h>

int pedir_entero(char name){
    int x;
    printf("Ingrese un entero positivo en la variable %c = ",name);
    scanf("%d",&x);   
    return x;
}

void hola_hasta(int n){
    int i = 0;
    while (i < n){
        printf("Hola\n");
        i = i + 1;
    }
}

int main(void){
    int n = pedir_entero('n');

    assert(n > 0);

    hola_hasta(n);

    return 0;
}

/*
Ingrese un entero positivo en la variable n = 3
Hola
Hola
Hola
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero positivo en la variable n = 0
ex01: ejercicio01.c:22: main: Assertion `n > 0' failed.
Abortado (`core' generado)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero positivo en la variable n = -3
ex01: ejercicio01.c:22: main: Assertion `n > 0' failed.
Abortado (`core' generado)
*/