#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define Tam 5

int pedir_entero(char name){
	int x;
	printf("Ingrese tramo inicial %c = ",name);
	scanf("%d",&x);
	return x;
}

void pedir_arreglo(int tam,int a[]){
	int i=0;
	while(i<tam){
		printf("Ingrese en la pos %d del arreglo = ",i);
		scanf("%d",&a[i]);
		i++;
	}
}

bool hay0_si(int tam,int a[],int k){
	assert((k<=tam) && (k>=0));
	int i=0;
	bool res=false;
	while(i<k){
		if(a[i]==0){
			res=true;	
		}
		i++;
	}
	return res;
}

int main(void){
	int a[Tam];
	int k=pedir_entero('k');
	pedir_arreglo(Tam,a);
	bool band=hay0_si(Tam,a,k);

	if(band){
		printf("hay 0s al comienzo\n");
	}else{
		printf("no hay 0s al comienzo.\n");
	}

}