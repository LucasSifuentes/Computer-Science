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
    int x;

    x = pedir_entero('x');
    x = 5;
    imprimir_entero('x',x);

    return 0;
}
/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_3
Ingrese un entero en la variable x:=3
El entero x es 5.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_3
Ingrese un entero en la variable x:=8
El entero x es 5.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_3
Ingrese un entero en la variable x:=0
El entero x es 5.
*/