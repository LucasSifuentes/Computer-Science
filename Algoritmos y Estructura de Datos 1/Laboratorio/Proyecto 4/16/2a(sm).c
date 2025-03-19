#include <stdio.h>
#include <assert.h>
#define N 5

int pedir_entero_esp(char n) {
    int x;
    printf("Ingrese el indice %c = ",n);
    scanf("%d",&x);
    return x;
}

void pedir_arreglo(char n, int a[], int tam) {
    int i = 0;

    printf("Para el arreglo %c.\n",n);

    while (i < tam) {
        printf("Ingrese un entero en la posicion %d = ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

void mostrar_entero_esp(char n, int k, int x) {
    printf("La suma de todos los valores de %c estrictamente mayores al elemento de la posicion %d es %d.\n",n,k,x);
}

int suma_mayores(int a[], int tam, int k) {
    int r = 0;
    int i = 0;

    while (i < tam) {
        if (a[i] > a[k]) {
            r = r + a[i];
        }
        i = i + 1;
    }
    return r;
}

int main(void) {
    //Creo las variables.
    int k, r, a[N];
    
    //Ingreso el indice que quiero usar, e ingreso los valores del arreglo.
    k = pedir_entero_esp('k');
    pedir_arreglo('a', a, N);
    
    assert(k >= 0 && k < N);    //PreCondicion

    r = suma_mayores(a, N, k);

    //Muestro el la suma.
    mostrar_entero_esp('a',k,r);

    return 0;
}