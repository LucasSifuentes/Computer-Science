#include <stdio.h>
int main(void)
{
    int x; 
    printf("ingrese un x\n");
    scanf("%d", &x);
    x = 5;
    printf("x es %d\n",x);

    return 0;
}

/*Ejemplos
guest-fsjopx@labo19:~/Escritorio$ ./ej3a
ingrese un x
2
x es 5
guest-fsjopx@labo19:~/Escritorio$ ./ej3a
ingrese un x
7
x es 5
guest-fsjopx@labo19:~/Escritorio$ ./ej3a
ingrese un x
9
x es 5
*/