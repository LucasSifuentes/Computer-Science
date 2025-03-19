#include <stdio.h> 
int main(void){
     int x,y;
    printf("ingrese un x\n");
    scanf("%d", &x);
    printf("ingrese un y\n");
    scanf("%d", &y);
    x = x+y;
    y = y+y;
    printf("x es %d\n",x);
    printf("y es %d\n",y);
    return 0;
}
/*Ejemplos
guest-fsjopx@labo19:~/Escritorio$ ./ej3b
ingrese un x
1
ingrese un y
2
x es 3
y es 4
guest-fsjopx@labo19:~/Escritorio$ ./ej3b
ingrese un x
5
ingrese un y
8
x es 13
y es 16
guest-fsjopx@labo19:~/Escritorio$ ./ej3b
ingrese un x
10
ingrese un y
-4
x es 6
y es -8
*/