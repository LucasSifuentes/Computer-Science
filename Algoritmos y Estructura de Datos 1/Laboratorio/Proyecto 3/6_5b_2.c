#include <stdio.h>
#include <stdbool.h>

int pedir_entero(char name){
    int x;

    printf("Ingrese un entero en la variable %c:=",name);
    scanf("%d",&x);
    
    return x;
}

void imprimir_booleano(char name, bool x){
    if (x==0){
        printf("El Booleano %c es Verdadero.\n",name);
    } else if (x!=0) {
        printf("El Booleano %c es Falso.\n",name);
    }
}

int main(){
    int x, i;
    bool r;

    x = pedir_entero('x');

    i = 2;
    r = true;

    while (i<x && r){
        r = r && ((x%i)!=0);
        i=i+1;
        printf("x es %d, i es %d.\n",x,i);
        imprimir_booleano('r',r);
    }    

    return 0;
}

/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_5b_2
Ingrese un entero en la variable x:=5
x es 5, i es 3.
El Booleano r es Falso.
x es 5, i es 4.
El Booleano r es Falso.
x es 5, i es 5.
El Booleano r es Falso.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_5b_2
Ingrese un entero en la variable x:=6
x es 6, i es 3.
*/