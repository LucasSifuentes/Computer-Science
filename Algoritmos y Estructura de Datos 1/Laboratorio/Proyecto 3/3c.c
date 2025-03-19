#include <stdio.h> 
int main(void){
     int x,y;
    printf("ingrese un x\n");
    scanf("%d", &x);
    printf("ingrese un y\n");
    scanf("%d", &y);
    y = y + y;
    x = x+y;
    printf("x es %d\n",x);
    printf("y es %d\n",y);
    return 0;
}
/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ gcc -Wall -Wextra -std=c99 3c.c -o ej3c
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej3c 
ingrese un x
2
ingrese un y
6
x es 14
y es 12
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej3c 
ingrese un x
1
ingrese un y
2
x es 5
y es 4
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej3c 
ingrese un x
-2
ingrese un y
3
x es 4
y es 6
*/