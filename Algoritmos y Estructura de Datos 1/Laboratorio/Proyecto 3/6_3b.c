#include <stdio.h>

int pedir_entero(char name){
    int x;

    printf("Ingrese un entero en la variable %c:=",name);
    scanf("%d",&x);
    
    return x;
}

void imprimir_entero(char name, int x){
    printf("El entero %c es %d.\n",name,x);
}

int main(){
    int x, y;

    x = pedir_entero('x');
    y = pedir_entero('y');

    x = x + y;
    y = y + y;

    imprimir_entero('x',x);
    imprimir_entero('y',y);

    return 0;
}
/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_3b
Ingrese un entero en la variable x:=3
Ingrese un entero en la variable y:=1
El entero x es 4.
El entero y es 2.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_3b
Ingrese un entero en la variable x:=0
Ingrese un entero en la variable y:=9
El entero x es 9.
El entero y es 18.
*/