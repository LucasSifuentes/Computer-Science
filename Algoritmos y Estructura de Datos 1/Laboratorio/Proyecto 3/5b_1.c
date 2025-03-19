#include <stdio.h>

int main(){

    int x, y, i;

    printf("Ingrese el valor x");
    scanf("%d",&x);
    printf("Ingrese el valor y");
    scanf("%d",&y);

    i=0;

    while (x>=y){
        x=x-y;
        i=i+1;
        printf("x es %d, y es %d, i es %d.\n",x,y,i);
    }
    
    return 0;
}
/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./5b_1 
Ingrese el valor x13
Ingrese el valor y3
x es 10, y es 3, i es 1.
x es 7, y es 3, i es 2.
x es 4, y es 3, i es 3.
x es 1, y es 3, i es 4.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./5b_1 
Ingrese el valor x5
Ingrese el valor y9
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./5b_1 
Ingrese el valor x0
Ingrese el valor y1
*/