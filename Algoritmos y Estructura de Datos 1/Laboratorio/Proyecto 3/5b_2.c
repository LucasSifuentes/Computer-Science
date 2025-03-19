#include <stdio.h>
#include <stdbool.h>

int main(){

    int x, i;
    bool res;

    printf("Ingrese el valor x");
    scanf("%d",&x);

    i = 2;
    res = true;

    while (i<x && res){
        res = res && ((x%i)!=0);
        i=i+1;
        printf("x es %d, i es %d, res es %d.\n",x,i,res);
    }
    
    return 0;
}
/*El programa me dice si un número es par*/
/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej5b_2
Ingrese el valor x5
x es 5, i es 3, res es 1.
x es 5, i es 4, res es 1.
x es 5, i es 5, res es 1.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej5b_2
Ingrese el valor x8
x es 8, i es 3, res es 0.
*/