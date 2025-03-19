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
    int x, y, i;

    x = pedir_entero('x');
    y = pedir_entero('y');

    i = 0;

    while (x>=y){
        x = x - y;
        i = i + 1;
        printf("x es %d, y es %d, i es %d.\n",x,y,i);
    }
    
    return 0;
}

/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_5b_1
Ingrese un entero en la variable x:=13
Ingrese un entero en la variable y:=3
x es 10, y es 3, i es 1.
x es 7, y es 3, i es 2.
x es 4, y es 3, i es 3.
x es 1, y es 3, i es 4.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_5b_1
Ingrese un entero en la variable x:=5
Ingrese un entero en la variable y:=1
x es 4, y es 1, i es 1.
x es 3, y es 1, i es 2.
x es 2, y es 1, i es 3.
x es 1, y es 1, i es 4.
x es 0, y es 1, i es 5.
*/