#include <stdio.h>
#include <stdbool.h>

int pedir_entero(char name){
    int x;

    printf("Ingrese un entero en la variable %c:=",name);
    scanf("%d",&x);
    
    return x;
}

bool pedir_booleano(char name){
    int y;
    printf("Ingrese un Booleano en la variable %c:=",name);
    scanf("%d",&y);
    bool x = y;
    return x;
}

int main(){
    int x, y, z;
    bool b, w;

    b = pedir_booleano('b');
    w = pedir_booleano('w');
    x = pedir_entero('x');
    y = pedir_entero('y');
    z = pedir_entero('z');

    printf("(x mod 4 == 0) = %d\n",(x%4==0));
    printf("(x + y == 0 && y - x == (-1) * z) = %d\n",(x+y==0&&y-x==(-1)*z));
    printf("(not b && w) = %d\n",(!b&&w));

    return 0;
}

/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_2 
Ingrese un Booleano en la variable b:=1
Ingrese un Booleano en la variable w:=1
Ingrese un entero en la variable x:=3
Ingrese un entero en la variable y:=2
Ingrese un entero en la variable z:=7
(x mod 4 == 0) = 0
(x + y == 0 && y - x == (-1) * z) = 0
(not b && w) = 0
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./6_2 
Ingrese un Booleano en la variable b:=0
Ingrese un Booleano en la variable w:=0
Ingrese un entero en la variable x:=2
Ingrese un entero en la variable y:=3
Ingrese un entero en la variable z:=1
(x mod 4 == 0) = 0
(x + y == 0 && y - x == (-1) * z) = 0
(not b && w) = 0
*/