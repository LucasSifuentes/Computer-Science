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
    int x = pedir_entero('x');
    imprimir_entero('x',x);

    return 0;
}

/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./entradas
Ingrese un entero en la variable x:=34
El entero x es 34.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./entradas
Ingrese un entero en la variable x:=-432
El entero x es -432.
*/