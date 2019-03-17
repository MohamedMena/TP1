#include "reino.h"

struct region{
char nombre [50];
char lema [50];
int ejercito;
};

struct reino{
region_t* regiones;
int cantidad_regiones;
int maximo_regiones;
};

reino_t* crear_reino (size_t maximo_regiones){

	reino_t* nuevo_reino = malloc(sizeof(reino_t));
	if(!nuevo_reino) return NULL;

	nuevo_reino->regiones = malloc(sizeof(region_t) * maximo_regiones);
	if(!nuevo_reino->regiones){
		free(nuevo_reino);
		return NULL;
	}

	nuevo_reino->cantidad_regiones = 0;

	nuevo_reino->maximo_regiones = maximo_regiones;

	return nuevo_reino;
}

int destruir_reino (reino_t* reino){
	if(!reino) return 1;

	free(reino->regiones);
	free(reino);

	return 0;
}

int agregar_region (reino_t* reino, region_t region){

	if(!reino) return 1;
	if(reino->cantidad_regiones == reino->maximo_regiones-1) return 1;

	region_t* region_nueva = reino->regiones[cantidad_regiones];
	strcpy(region_nueva->nombre, region->nombre);
	strcpy(region_nueva->lema, region->lema);
	region_nueva->ejercito = region->ejercito;

	reino->cantidad_regiones++;

	return 0;
}

void listar_regiones (reino_t* reino){
	if(!reino) return;
	for(int i = 0; i < reino->cantidad_regiones+1; i++){
		fprintf(stdout, "%s\n", reino->regiones[i]->nombre);
	}
}


void ordenar_reino (reino_t* reino, int (*comparar_regiones) (region_t, region_t)){
	if(!reino) return;


}

int comparar_por_ejercito (region_t region_1, region_t region_2){
	if(region_1.ejercito < region_2.ejercito){
		return -1;
	}else if(region_1 > region_2.ejercito){
		return 1;
	}

	return 0;
}

int comparar_por_nombre (region_t region_1, region_t region_2){
	return strcmp(region_1->nombre, region_2->nombre);
}