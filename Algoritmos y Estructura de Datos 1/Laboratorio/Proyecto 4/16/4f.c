#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

int pedirEntero(char n) {
    int x;
    printf("Ingrese el segmento inicial k en el cual quiere comprobar si hay 0:   %c = ",n);
    scanf("%d",&x);
    return x;
}

void pedirArregloEnteros(int a[], int tam) {
    int i = 0;

    while (i < tam) {
        printf("Ingrese un Entero en la posicion %d = ",i+1);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

bool hay0_si(int tam, int a[], int k) {
    int i = 0;
    assert(k >= 0 && k <= tam);
    while (i < k) {
        if (a[i] == 0) {
            return true;
        }else{
            return false;
        }
        i = i + 1;
    }
    
    return true;
}

int main(void){
    int a[N];
    int k = pedirEntero('k');

    pedirArregloEnteros(a,N);

    if (hay0_si(N, a,k)) {
        printf("Hay 0s al comienzo");
    } else {
        printf("No hay 0s al comienzo");
    }
    
    return 0;
}