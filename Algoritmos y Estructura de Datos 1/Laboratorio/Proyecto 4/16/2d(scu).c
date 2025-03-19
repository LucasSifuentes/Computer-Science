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

int suma_cuadrados_pares(int a[], int tam) {
    int i = 0;
    int sum = 0;

    while (i < tam) {
        if (a[i] % 2 == 0) {
            sum = sum + a[i] * a[i];
        }
        i = i + 1;
    }

    return sum;
}

int main(void){
    int a[N];
    int sum;

    pedirArregloEnteros(a,N);
    sum = suma_cuadrados_pares(a,N);

    printf("La Suma de los Elementos del arreglo al cuadrado que son Pares es %d.\n",sum);

    return 0;
}