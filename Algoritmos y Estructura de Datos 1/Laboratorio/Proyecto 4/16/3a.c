#include <stdio.h>
#define N 5

void pedir_arreglo(char n, int a[], int tam) {
    int i = 0;

    printf("Para el arreglo %c.\n",n);

    while (i < tam) {
        printf("Ingrese un entero en la posicion %d = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

struct paridad_t {
    int n_pares;
    int n_impares;
};

struct paridad_t contar_paridad(int a[], int tam) {
    struct paridad_t r;
    int i = 0;
    r.n_impares = 0;
    r.n_pares = 0;

    while (i < tam) {
        if (a[i] % 2 == 0 ) {
            r.n_pares = r.n_pares + 1;
        } else {
            r.n_impares = r.n_impares + 1;
        }
        i = i + 1;
    }

    return r;
}

int main(void) {
    int a[N];
    struct paridad_t r;

    pedir_arreglo('a', a, N);
    r = contar_paridad(a, N);

    printf("En el arreglo hay %d elementos Pares, y %d elementos Impares.\n",r.n_pares,r.n_impares);
    
    return 0;
}