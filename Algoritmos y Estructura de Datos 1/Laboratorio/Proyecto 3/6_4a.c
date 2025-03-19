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

    if (x>=y){
        x=0;
    } else if (x<=y){
        x=2;
    }

    imprimir_entero('x',x);
    imprimir_entero('y',y);

    return 0;
}

/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_4a
Ingrese un entero en la variable x:=2
Ingrese un entero en la variable y:=4
El entero x es 2.
El entero y es 4.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_4a
Ingrese un entero en la variable x:=3
Ingrese un entero en la variable y:=1
El entero x es 0.
El entero y es 1.
*/