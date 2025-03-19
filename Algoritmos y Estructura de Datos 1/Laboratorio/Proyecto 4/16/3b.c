#include <stdio.h>
#define N 5

void pedirArregloEnteros(int a[], int tam){
    int i = 0;

    while (i < tam) {
        printf("Ingrese un Entero en la posicion %d = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

struct paridad_t {
    int n_pares;
    int n_impares;
    int n_ceros;
};

struct paridad_t contar_pares_impares(int a[], int tam){
    int i = 0;
    struct paridad_t paridad;

    paridad.n_ceros = 0;
    paridad.n_impares = 0;
    paridad.n_pares = 0;

    while (i < tam) {
        if (a[i] == 0) {
            paridad.n_ceros = paridad.n_ceros + 1;
        } else if (a[i] % 2 == 0) {
            paridad.n_pares = paridad.n_pares + 1;
        } else {
            paridad.n_impares = paridad.n_impares + 1;
        }
        i = i + 1;
    }
    
    return paridad;
}

int main(void){
    int a[N];
    struct paridad_t paridad;

    pedirArregloEnteros(a,N);
    paridad = contar_pares_impares(a,N);

    printf("Hay %d Ceros en el arreglo.\n",paridad.n_ceros);
    printf("Hay %d Pares en el arreglo.\n",paridad.n_pares);
    printf("Hay %d Impares en el arreglo.\n",paridad.n_impares);

    return 0;
}