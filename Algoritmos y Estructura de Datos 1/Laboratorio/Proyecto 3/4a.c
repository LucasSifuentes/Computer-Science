#include <stdio.h> 
int main(void){
     int x,y;
    
    //solicitamos estado 0
    printf("ingrese un x\n");
    scanf("%d", &x);
    printf("ingrese un y\n");
    scanf("%d", &y);
 
    if (x>=y){
    x = 0;
    //estado 1
    } else if (x<=y){
    x = 2;
    //estado 2
    }

    //imprimimos estado 3 
    printf("x es %d y es  %d\n",x,y);

    return 0;
}

/*Ejemplos

Programa 1e
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej4a 
ingrese un x
3
ingrese un y
1
x es 0 y es  1


Programa 1f
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej4a 
ingrese un x
-100
ingrese un y
1
x es 2 y es  1

*/