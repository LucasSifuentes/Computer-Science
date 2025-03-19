#include <stdio.h>
#include <assert.h>

int pedir_entero(char name){
    int x;
    printf("Ingrese un entero positivo en la variable %c = ",name);
    scanf("%d",&x);
    return x;
}

struct info_t {
    int cociente;
    int resto;
}div_t;  

div_t division(int x, int y) {
    div_t d;
    d.cociente = x/y;
    d.resto = x%y;
    return d;
}

int main(void) {
    int x = pedir_entero('x');
    int y = pedir_entero('y');

    assert(y > 0 && x >= 0);

    div_t resultado;

    resultado = division(x,y);

    printf("La division de %d/%d. Deja Resto %d y Cociente %d.\n",x,y,resultado.resto,resultado.cociente);

    return 0;
}

/*
Ingrese un entero positivo en la variable x = 1
Ingrese un entero positivo en la variable y = 2
La division de 1/2. Deja Resto 1 y Cociente 0.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero positivo en la variable x = 9
Ingrese un entero positivo en la variable y = 5
La division de 9/5. Deja Resto 4 y Cociente 1.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese un entero positivo en la variable x = 100
Ingrese un entero positivo en la variable y = 3
La division de 100/3. Deja Resto 1 y Cociente 33.
*/