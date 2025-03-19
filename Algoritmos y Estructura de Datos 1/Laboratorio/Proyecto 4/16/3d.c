#include <stdio.h>
#include <limits.h>
#include <assert.h>
#define N 4

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

struct minMul_t {
    int min;
    int indice;
};

struct minMul_t multiplo_minimo(int a[], int tam, int k) {
    struct minMul_t minMul;
    int i = 0;

    minMul.min = INT_MAX;
    minMul.indice = -1;

    while (i < tam) {
        if (a[i] < minMul.min && a[i] % k == 0) {
            minMul.indice = i;
            minMul.min = a[i];
        }
        i = i + 1;
    }
    
    return minMul;
}

int main(void){
    int k, a[N];
    struct minMul_t minMul;

    pedirArregloEnteros(a,N);
    k = pedirEntero('k');

    assert(k != 0);

    minMul = multiplo_minimo(a,N,k);
    
    printf("El Minimo elemento del arreglo que es multiplo de %d es %d, y esta en el indice %d.\n",k,minMul.min,minMul.indice);
    return 0;
}