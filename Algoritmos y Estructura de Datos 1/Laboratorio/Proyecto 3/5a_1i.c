#include <stdio.h>
int main(){
    int i;

   //Programa 1h

    printf("Ingrese la variable i");
    scanf("%d",&i);

    while (i!=0){
        printf("En el do i es %d\n",i);
        i=0;
        printf("Ahora, i-1 es %d\n",i);
    }

    printf("El valor final de i es %d\n",i);

    return 0;
}
/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej5a_1i 
Ingrese la variable i400
En el do i es 400
Ahora, i-1 es 0
El valor final de i es 0
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej5a_1i 
Ingrese la variable i0
El valor final de i es 0

*/