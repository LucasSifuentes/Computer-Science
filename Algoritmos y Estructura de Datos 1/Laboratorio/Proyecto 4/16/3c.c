#include <stdio.h>
#define N 5

void pedirArregloEnteros(int a[], int tam) {
    int i = 0;

    while (i < tam) {
        printf("Ingrese un Entero en la posicion %d = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

struct s_suma_t {
    int suma_pares;
    int suma_impares;
    int suma_total;
};

struct s_suma_t sumas(int a[], int tam) {
    struct s_suma_t sum;
    int i = 0;

    sum.suma_impares = 0;
    sum.suma_pares = 0;
    sum.suma_total = 0;

    while (i < tam) {
        if (a[i] % 2 == 0) {
            sum.suma_pares = sum.suma_pares + a[i];
        } else {
            sum.suma_impares = sum.suma_impares + a[i];
        }
        sum.suma_total = sum.suma_total + a[i];
        i = i + 1;
    }

    return sum;
}

int main(void){
    int a[N];
    struct s_suma_t suma;

    pedirArregloEnteros(a,N);

    suma = sumas(a,N);

    printf("La suma total de los elementos Impares del arreglo es %d.\n",suma.suma_impares);
    printf("La suma total de los elementos Pares del arreglo es %d.\n",suma.suma_pares);
    printf("La suma total de los elementos del arreglo es %d.\n",suma.suma_total);
    
    return 0;
}