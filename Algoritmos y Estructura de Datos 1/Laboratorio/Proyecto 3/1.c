#include <stdio.h>
int main(void)            
 {
	int x, y, z;
	printf("Ingrese un valor para x\n"); 
	scanf("%d", &x); 
	printf("Ingrese un valor para y\n"); 
	scanf("%d", &y); 
    printf("Ingrese un valor para z\n"); 
	scanf("%d", &z); 
	
	printf("x=%d, y=%d; z=%d; entonces x+y+1=%d\n",x,y,z, x+y+1); 
    printf("x=%d, y=%d; z=%d; entonces z * z + y * 45 - 15 * x=%d\n",x,y,z, z * z + y * 45 - 15 * x ); 
    printf("x=%d, y=%d; z=%d; entonces y - 2 == (x * 3 + 1) modulo 5=%d\n",x,y,z, y - 2 == (x * 3 + 1) % 5); 
    printf("x=%d, y=%d; z=%d; entonces y / 2 * x=%d\n",x,y,z, y / 2 * x); 
    printf("x=%d, y=%d; z=%d; entonces y < x * z=%d\n",x,y,z, y < x * z); 

       return 0;
}

/* Ejemplos
guest-fsjopx@labo19:~/Escritorio$ gcc -Wall -Wextra -std=c99 1.c -o ej1
guest-fsjopx@labo19:~/Escritorio$ ./ej1 
Ingrese un valor para x
1
Ingrese un valor para y
2
Ingrese un valor para z
3
x=1, y=2; z=3; entonces x+y+1=4
x=1, y=2; z=3; entonces z * z + y * 45 - 15 * x=84
x=1, y=2; z=3; entonces y - 2 == (x * 3 + 1) modulo 5=0
x=1, y=2; z=3; entonces y / 2 * x=1
x=1, y=2; z=3; entonces y < x * z=1*/