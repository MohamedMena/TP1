#include "reino.h"
#include <string.h>

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

	region_t* region_nueva = &(reino->regiones[reino->cantidad_regiones]);
	strcpy(region_nueva->nombre, region.nombre);
	strcpy(region_nueva->lema, region.lema);
	region_nueva->ejercito = region.ejercito;

	reino->cantidad_regiones++;

	return 0;
}

void listar_regiones (reino_t* reino){
	if(!reino) return;
	for(int i = 0; i < reino->cantidad_regiones; i++){
		fprintf(stdout, "%s;%s;%i\n", reino->regiones[i].nombre, reino->regiones[i].lema, reino->regiones[i].ejercito);
	}
}

void swap_regiones(region_t* region_uno, region_t* region_dos){
	region_t region_aux = *region_uno;
	*region_uno = *region_dos;
	*region_dos = region_aux;
}

void ordenar_reino (reino_t* reino, int (*comparar_regiones) (region_t, region_t)){

	if(!reino) return;
	for(int i = reino->cantidad_regiones-1; i > 0; i--){
		int pos_maximo = 0;
		for(int j = 1; j < i+1; j++){
			if(comparar_regiones(reino->regiones[j], reino->regiones[pos_maximo]) > 0){
				pos_maximo = j;
			}
		}
		swap_regiones(&(reino->regiones[pos_maximo]), &(reino->regiones[i]));
	}
}