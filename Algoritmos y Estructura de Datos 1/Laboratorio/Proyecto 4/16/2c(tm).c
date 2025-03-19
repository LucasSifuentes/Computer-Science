#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

int pedirEntero(char n) {
    int x;
    printf("Ingrese un Entero en %c = ",n);
    scanf("%d",&x);
    return x;
}

void pedirArregloEnteros(int a[], int tam) {
    int i = 0;

    while (i < tam) {
        printf("Ingrese un Entero en la posicion %d = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

bool todos_multiplos(int a[], int tam, int k) {
    int i = 0;

    while (i < tam) {
        if (a[i] % a[k] != 0) {
            return false;
        }
        i = i + 1;
    }
    
    return true;
}

int main(void){
    int a[N];
    int k = pedirEntero('k');

    assert(k >= 0 && k < N && a[k] != 0);

    pedirArregloEnteros(a,N);

    if (todos_multiplos(a,N,k)) {
        printf("Todos los Elementos del arreglo son Multiplos de %d.\n",a[k]);
    } else {
        printf("No todos los Elementos del arreglo son multiplos de %d.\n",a[k]);
    }
    
    return 0;
}