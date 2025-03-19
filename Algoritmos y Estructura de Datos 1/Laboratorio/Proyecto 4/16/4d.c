#include <stdio.h>
#define N 3

struct producto_t {
    int precio;
    int peso;
};

void pedirArreglo_esp(struct producto_t a[], int tam){
    int i = 0;

    while (i < tam) {
        printf("Ingrese el Precio del producto %d = ",i+1);
        scanf("%d",&a[i].precio);
        printf("Ingrese su Peso en Kilos = ");
        scanf("%d",&a[i].peso);
        i = i + 1;
    }
}

struct total_t {
    int precio_total;
    int peso_total;
};

struct total_t calcular_montos(struct producto_t a[], int tam){
    struct total_t total;
    int i = 0;

    total.precio_total = 0;
    total.peso_total = 0;

    while (i < tam) {
        total.precio_total = total.precio_total + a[i].precio;
        total.peso_total = total.peso_total + a[i].peso;
        i = i + 1;
    }
    
    return total;
}

int main(void){
    struct producto_t prod[N];
    struct total_t total;

    pedirArreglo_esp(prod,N);

    total = calcular_montos(prod,N);

    printf("El Peso total es %dkg, y el total a Pagar es = $%d.\n",total.peso_total,total.precio_total);

    return 0;
}