#include "reino.h"

struct region{
char nombre [50];
char lema [50];
int ejercito;
};

struct reino{
region_t* regiones;
int cantidad_regiones;
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

	return nuevo_reino;
}

int destruir_reino (reino_t* reino){
	if(!reino) return 1;

	free(reino->regiones);
	free(reino);

	return 0;
}

int agregar_region (reino_t* reino, region_t region){

	region_t* region_nueva = reino->regiones[cantidad_regiones];
	strcpy(region_nueva->nombre, region->nombre);
	strcpy(region_nueva->lema, region->lema);
	region_nueva->ejercito = region->ejercito;

	reino->cantidad_regiones++;

	return 0;
}

void listar_regiones (reino_t* reino){
	for(int i = 0; i < reino->cantidad_regiones; i++){
		fprintf(stdout, "%s\n", reino->regiones[i]->nombre);
	}
}