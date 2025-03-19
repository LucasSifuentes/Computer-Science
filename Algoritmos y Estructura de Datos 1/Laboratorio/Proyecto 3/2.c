#include <stdio.h>
#include <stdbool.h>
int main (void) {

int x,y,z;
bool b,w;

printf("ingrese un b bool\n");
scanf("%d", &x);
b = x;
printf("ingrese un w bool\n");
scanf("%d", &x);
w = x;

printf("ingrese un x entero\n");
scanf("%d", &x);
printf("ingrese un y entero\n");
scanf("%d", &y);
printf("ingrese un z entero\n");
scanf("%d", &z);


printf("x=%d, y=%d; z=%d; b=%d; w=%d; entonces =%d\n",x,y,z,b,w, x % 4 == 0);
printf("x=%d, y=%d; z=%d; b=%d; w=%d; entonces =%d\n",x,y,z,b,w, (x + y == 0) && (y - x == (-1) * z ));
printf("x=%d, y=%d; z=%d; b=%d; w=%d; entonces =%d\n",x,y,z,b,w, (!b) && w );

return 0 ;

}

/* Ejemplos
guest-fsjopx@labo19:~/Escritorio$ ./ej2 
ingrese un b bool
0
ingrese un w bool
0
ingrese un x entero
0
ingrese un y entero
0
ingrese un z entero
0
x=0, y=0; z=0; b=0; w=0; entonces =1
x=0, y=0; z=0; b=0; w=0; entonces =1
x=0, y=0; z=0; b=0; w=0; entonces =0
guest-fsjopx@labo19:~/Escritorio$ ./ej2 
ingrese un b bool
1
ingrese un w bool
1
ingrese un x entero
4
ingrese un y entero
-4
ingrese un z entero
8
x=4, y=-4; z=8; b=1; w=1; entonces =1
x=4, y=-4; z=8; b=1; w=1; entonces =1
x=4, y=-4; z=8; b=1; w=1; entonces =0
*/