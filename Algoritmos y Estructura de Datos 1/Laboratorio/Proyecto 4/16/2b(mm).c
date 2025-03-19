#include <stdio.h>
#include <limits.h>
#include <assert.h>
#define N 5

int pedirEntero_esp(char n){
    int x;
    printf("Ingrese un Entero, diferente a 0 para buscarle el minimo multiplo, en %c = ",n);
    scanf("%d",&x);
    return x;
}

void imprimirEntero(int x, int k){
    printf("El Menor Multiplo de %d en el arreglo es %d.\n",k,x);
}

void pedirArregloEnteros(int a[], int tam){
    int i = 0;

    while (i < tam) {
        printf("Ingrese un Entero en la posicion %d = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

int multiplo_minimo(int a[], int tam, int k){
    int i = 0, min = INT_MAX, res;

    while (i < tam) {
        if (a[i] % k == 0 && a[i] < min){
            res = a[i];
            min = a[i];
        }
        i = i + 1;
    }

    return res;
}

int main(void){
    int k = pedirEntero_esp('k');
    int a[N];
    int r;

    assert(k != 0);

    pedirArregloEnteros(a,N);

    r = multiplo_minimo(a,N,k);

    imprimirEntero(r,k);

    return 0;
}