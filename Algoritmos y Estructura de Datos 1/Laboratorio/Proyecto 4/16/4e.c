#include <stdio.h>
#include <stdbool.h>
#define N 5

void llena_con_char(char a[], int tam) {
int i = 0;
while (i < tam) {
    printf("Ingrese una letra en la posicion %d = ",i);
    scanf(" %c",&a[i]);
    i = i + 1;
    }

}


bool es_vocal(char letra) {
    if (letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U') {
        return false;
    }
    return true;
}


bool hay_mas_de_2_consonantes(char a[], int tam){
    int i = 0;
    bool x = false;
    int cantidad_vocales = 0;
    while (i<tam)
    {
        if(es_vocal(a[i])){
    cantidad_vocales++;
    }
    if (cantidad_vocales>=2){
        x = true;
    }
    i++;
    }
    
    return x;
}

int main(void) {
    char a[N];
    bool res= false;
    llena_con_char (a, N);
    res = hay_mas_de_2_consonantes(a, N);
    printf("la respuesta es:   %d", res);
    return 0;
}
/*
visitante@lab08:~/Escritorio/Laboratorio AYED1$ gcc -Wall -Wextra -std=c99 parcialEj2.c -o visitante@lab08:~/Escritorio/Laboratorio AYED1$ ./e2
Ingrese una letra en la posicion 0 = a
Ingrese una letra en la posicion 1 = e
Ingrese una letra en la posicion 2 = t
Ingrese una letra en la posicion 3 = f
Ingrese una letra en la posicion 4 = o
la respuesta es1visitante@lab08:~/Escritorio/Laboratorio AYED1$ */