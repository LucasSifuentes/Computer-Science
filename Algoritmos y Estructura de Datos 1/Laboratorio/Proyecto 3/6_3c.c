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

    y = y + y;
    x = x + y;

    imprimir_entero('x',x);
    imprimir_entero('y',y); 

    return 0;
}

/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_3c
Ingrese un entero en la variable x:=4
Ingrese un entero en la variable y:=7
El entero x es 18.
El entero y es 14.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_3c
Ingrese un entero en la variable x:=-2
Ingrese un entero en la variable y:=8
El entero x es 14.
El entero y es 16.
*/