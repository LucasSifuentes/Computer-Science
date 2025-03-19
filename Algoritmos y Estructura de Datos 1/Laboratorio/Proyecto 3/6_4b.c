#include <stdio.h>

int pedir_entero(char name){
    int x;

    printf("Ingrese un entero en la variable %c:=",name);
    scanf("%d",&x);
    
    return x;
}

void imprimir_entero(char name, int x){
    printf("El entero %c es %d.\n",name,x);
}

int minimo_entre_tres(int x, int y, int z){
    int m;

    if (x<y){
        m=x; 
    } else if (x>=y){
        m=y;
    }
    if (m>=z){
        m=z;
    }

    return m;
}

int main(){
    int x, y, z, m;

    x = pedir_entero('x');
    y = pedir_entero('y');
    z = pedir_entero('z');

    m = minimo_entre_tres(x,y,z);

    imprimir_entero('x',x);
    imprimir_entero('y',y);
    imprimir_entero('z',z);
    imprimir_entero('m',m);
    printf("Y es el minimo ente x,y,z.\n");

    return 0;
}
/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_4b
Ingrese un entero en la variable x:=3
Ingrese un entero en la variable y:=5
Ingrese un entero en la variable z:=2
El entero x es 3.
El entero y es 5.
El entero z es 2.
El entero m es 2.
Y es el minimo ente x,y,z.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_4b
Ingrese un entero en la variable x:=9
Ingrese un entero en la variable y:=8
Ingrese un entero en la variable z:=7
El entero x es 9.
El entero y es 8.
El entero z es 7.
El entero m es 7.
Y es el minimo ente x,y,z.
*/