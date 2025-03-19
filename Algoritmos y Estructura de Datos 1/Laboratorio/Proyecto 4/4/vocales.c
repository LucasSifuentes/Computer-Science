#include <stdio.h>
#include <stdbool.h>

int pedir_char(char name){
    char x;
    printf("Ingrese una letra en la variable %c = ",name);
    scanf("%c",&x);
    return x;
}

bool es_vocal(char letra) {
    if (letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U') {
        return true;
    }
    return false;
}

int main(void) {
    char x = pedir_char('x');

    if (es_vocal(x)) {
        printf("La letra %c es Vocal.\n",x);
    } else {
        printf("La letra %c no es Vocal.\n",x);
    }
    
    return 0;
}

/*
Ingrese una letra en la variable x = a
La letra a es Vocal.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese una letra en la variable x = A
La letra A es Vocal.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese una letra en la variable x = v
La letra v no es Vocal.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ingrese una letra en la variable x = u
La letra u es Vocal.
*/