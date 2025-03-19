#include <stdio.h>
#include <stdbool.h>
#define N 5 //tamaño arreglo

typedef struct {
    int cant_veces_encontrado;
    int cant_pares;
    int cant_impares;
    bool hay_8;
}datos;  

datos llenar_estructura(int a[], int tam, int v) {
    datos resultado;
    int i = 0;

    resultado.cant_veces_encontrado= 0;
    resultado.cant_pares= 0;
    resultado.cant_impares= 0;
    resultado.hay_8= false;
    
    while (i < tam) {
        if (a[i] == v) {
            resultado.cant_veces_encontrado++;
        }
        if(a[i]%2==0){
            resultado.cant_pares++;
        }else{
            resultado.cant_impares++;
        }
        if(a[i]==8){
            resultado.hay_8= true;
        }
        i++;
    }
    return resultado;
}

int main(void) {
    int a[N];
    int v;
    int i = 0;

    printf("=Ingrese %d enteros para el arreglo=\n", N);

    while (i < N) {
        printf("Ingrese el entero para el lugar %d:\n", i+1);
            scanf("%d", &a[i]);
        i++;
    }

    printf("Ingrese un valor entero v:\n");
    scanf("%d", &v);

    datos resultado = llenar_estructura(a, N, v);

    printf("===Resultados===\n");
    printf("Cantidad de veces que se encontró a v: %d\n", resultado.cant_veces_encontrado);
    printf("Cantidad de pares: %d\n", resultado.cant_pares);
    printf("Cantidad de impares: %d\n", resultado.cant_impares);
    if(resultado.hay_8){
	    printf("Hay al menos un 8 en el arreglo\n");
    }
    else{
	    printf("No hay ningún 8 en el arreglo\n");
    }

    return 0;
}

