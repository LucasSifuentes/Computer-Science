#include <stdio.h>
#include <assert.h>

int pedir_entero(char n) {
    int x;
    printf("Ingrese un entero en %c = ",n);
    scanf("%d",&x);
    return x;
}

void mostrar_entero(char n, int x) {
    printf("El entero %c es %d.\n",n,x);
}

int main(void) {
    int r, R, s, S;
    
    //Ingreso los valores de r y s que son los mismos valores de R y S.
    r = pedir_entero('r');
    s = pedir_entero('s');
    R = r;
    S = s;

    assert(r == R && s == S && S > R);  //PreCondicion

    r = S - R;
    s = R + S;

    assert(r == S - R && s == R + S);   //PostCondicion

    //Muestro los valores de r y s.
    mostrar_entero('r',r);
    mostrar_entero('s',s);

    return 0;
}



//-----------------------------------------------------------------------------------------------------------------EJERCICIO ESTRELLA

#include <stdio.h>
#include <assert.h>

int pedir_entero(char name){
    int x;
    printf("Ingrese un entero positivo en la variable %c = ",name);
    scanf("%d",&x);
    return x;
}

struct info_t {
    int op_sum; //guarda suma
    int op_mul; //guarda multiplicacion
    int op_div; //guarda division entera
    int op_dist; //guarda valor abs de la resta
};

int valor_absoluto(int x){
    int abs;
    if (x>0)
    {
        abs = x;
    }else
    {
        abs = -x;
    }

    return abs;
}

struct info_t operar (int x, int y) {
struct info_t resultado;

resultado.op_sum  = x+y;
resultado.op_mul  =x*y;
resultado.op_div  = x/y;
resultado.op_dist = valor_absoluto(x-y);

return resultado ;
}

int main (void){

    int a = pedir_entero('a');
    int b = pedir_entero('b');

    // Ambas variables deben tener valores mayores a cero y que a > b
    assert(a > 0 && b > 0 && a > b);

    struct info_t res = operar(a, b);

    printf("===Resultados===\n");
    printf("res.op_sum = %d\n", res.op_sum);
    printf("res.op_mul = %d\n", res.op_mul);
    printf("res.op_div = %d\n", res.op_div);
    printf("res.op_dist = %d\n", res.op_dist);
    return 0;
}



//-----------------------------------------------------------------------------------------------------------------EJERCICIO ESTRELLA
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
