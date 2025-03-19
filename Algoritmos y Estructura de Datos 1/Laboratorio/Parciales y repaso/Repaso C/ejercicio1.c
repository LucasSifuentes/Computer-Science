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