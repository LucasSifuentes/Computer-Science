#include <stdio.h> 
int main(void){
     int x,y,z,m;
    
    printf("ingrese un x\n");
    scanf("%d", &x);
    printf("ingrese un y\n");
    scanf("%d", &y);
    printf("ingrese un z\n");
    scanf("%d", &z);
    printf("ingrese un m\n");
    scanf("%d", &m);
 
    if (x>y){
    m = x;
    } else if (x>=y){
    m = y;
    }

    printf("x es %d y es %d z es %d m es  %d\n",x,y,z,m);

    if (m>=z){
    m = z;
    }

    printf("x es %d, y es %d, z es %d.\nFinalmente m es %d.\n",x,y,z,m);    

    return 0;
}

/*Lo que hace el programa es devolver el valor minimo 
 entre las variables x,y,z y lo guarda en la variable m.*/

/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej4b
ingrese un x
5
ingrese un y
4
ingrese un z
8
ingrese un m
0
x es 5 y es 4 z es 8 m es  5
x es 5, y es 4, z es 8.
Finalmente m es 5.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej4b
ingrese un x
1
ingrese un y
2
ingrese un z
3
ingrese un m
4
x es 1 y es 2 z es 3 m es  4
x es 1, y es 2, z es 3.
Finalmente m es 3.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./ej4b
ingrese un x
-1
ingrese un y
5
ingrese un z
100
ingrese un m
-4
x es -1 y es 5 z es 100 m es  -4
x es -1, y es 5, z es 100.
Finalmente m es -4.

*/