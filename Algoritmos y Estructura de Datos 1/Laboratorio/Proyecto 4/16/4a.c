#include <stdio.h>
#include <limits.h>
#define N 3

struct persona_t {
    int dni;
    float altura;
};

void pedir_arreglo_esp(char n, struct persona_t a[], int tam) {
    int i = 0;

    printf("Para el arreglo %c.\n",n);

    while (i < tam) {
        printf("Ingrese el DNI de la persona %d = ",i);
        scanf("%d",&a[i].dni);
        printf("Ingrese la Altura = ");
        scanf("%f",&a[i].altura);
        i = i + 1;
    }
}

struct stats_t {
    float altura_media;
    float altura_min;
    float altura_max;
};

struct stats_t calcular_estadisticas(struct persona_t a[], int tam) {
    struct stats_t stats;
    int i = 0;
    float prom = 0;

    stats.altura_max = INT_MIN;
    stats.altura_min = INT_MAX;

    while (i < tam) {
        if (a[i].altura > stats.altura_max) {
            stats.altura_max = a[i].altura;
        }
        if (a[i].altura < stats.altura_min) {
            stats.altura_min = a[i].altura;
        }
        prom = prom + a[i].altura;
        i = i + 1;
    }

    stats.altura_media = prom/tam;

    return stats;
}

int main(void) {
    struct persona_t a[N];
    struct stats_t stats;

    pedir_arreglo_esp('A', a, N);

    stats = calcular_estadisticas(a, N);

    printf("La Altura Promedio es = %f.\n",stats.altura_media);
    printf("La Altura Minima es = %f.\n",stats.altura_min);
    printf("La Altura Maxima es = %f.\n",stats.altura_max);

    return 0;
}