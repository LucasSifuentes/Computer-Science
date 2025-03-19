#include <stdio.h>
int main(){
    int i;

   //Programa 1h

    printf("Ingrese la variable i");
    scanf("%d",&i);

    while (i!=0){
        printf("En el do i es %d\n",i);
        i=i-1;
        printf("Ahora, i-1 es %d\n",i);
    }

    printf("El valor final de i es %d\n",i);

    return 0;
}
/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej5a_1h 
Ingrese la variable i4
En el do i es 4
Ahora, i-1 es 3
En el do i es 3
Ahora, i-1 es 2
En el do i es 2
Ahora, i-1 es 1
En el do i es 1
Ahora, i-1 es 0
El valor final de i es 0
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej5a_1h 
Ingrese la variable i0
El valor final de i es 0


*/