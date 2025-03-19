#include <stdio.h>
#include <stdbool.h>

bool pedir_booleano(char name){
    int y;
    printf("Ingrese un Booleano en la variable %c:=",name);
    scanf("%d",&y);
    bool x = y;
    return x;
}

void imprimir_booleano(char name, bool x){
    if (x==0){
        printf("El Booleano %c es Verdadero.\n",name);
    } else if (x!=0) {
        printf("El Booleano %c es Falso.\n",name);
    }
}

int main(){
    bool x = pedir_booleano('x');
    imprimir_booleano('x',x);
    return 0;
}

/*Ejemplos
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./entradas_bool
Ingrese un Booleano en la variable x:=1
El Booleano x es Falso.
lucas@lucas-X555LD:/media/lucas/Dev/P3$ ./entradas_bool
Ingrese un Booleano en la variable x:=0
El Booleano x es Verdadero.
*/