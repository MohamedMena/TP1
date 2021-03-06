#define _POSIX_C_SOURCE 200809L
#include "reino.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
* Comparará 2 regiones según la cantidad de ejército que tienen .
* Devolverá :
* -1 si el ejército de la region 1 es menor al de la región 2.
* 0 si el ejército de la region 1 es igual al de la región 2.
* 1 si el ejército de la region 1 es mayor al de la región 2.
*/
int comparar_por_ejercito (region_t region_1, region_t region_2){
	if(obtener_cantidad_ejercito(region_1) < obtener_cantidad_ejercito(region_2)){
		return -1;
	}else if(obtener_cantidad_ejercito(region_1) > obtener_cantidad_ejercito(region_2)){
		return 1;
	}

	return 0;
}

/*
* Comparará 2 regiones según el nombre .
* Devolverá :
* -1 si nombre de la region 1 es menor al de la región 2.
* 0 si el nombre de la region 1 es igual al de la región 2.
* 1 si el nombre de la region 1 es mayor al de la región 2.
*/
int comparar_por_nombre (region_t region_1, region_t region_2){
	char* nombre1 = obtener_nombre_region(region_1);
	char* nombre2 = obtener_nombre_region(region_2);
	size_t largo_nombre_1 = strlen(nombre1);
	size_t largo_nombre_2 = strlen(nombre2);

	for(size_t i = 0; i < largo_nombre_1 && i < largo_nombre_2; i++){
		if(nombre1[i] < nombre2[i]){
			free(nombre1);
			free(nombre2);
			return -1;
		}else if(nombre1[i] > nombre2[i]){
			free(nombre1);
			free(nombre2);
			return 1;
		}
	}

	free(nombre1);
	free(nombre2);

	if(largo_nombre_1 < largo_nombre_2){
		return -1;
	}else if(largo_nombre_1 > largo_nombre_2){
		return 1;
	}

	return 0;
}

int main(void){

	FILE* archivo_reino = fopen("reino.txt", "r");

	if(archivo_reino != NULL){
		char* linea = '\0';
		size_t tamanio_linea = 150;
		if(getline(&linea, &tamanio_linea, archivo_reino) == -1){
			fclose(archivo_reino);
			return 0;
		}

		size_t maximo_regiones = (size_t)atoi(linea);
		reino_t* nuevo_reino = crear_reino(maximo_regiones);
		if(!nuevo_reino){
			fclose(archivo_reino);
			return 0;
		}

		while(getline(&linea, &tamanio_linea, archivo_reino) != -1){
			region_t* nueva_region = crear_region(linea);
			if(!nueva_region){
				fclose(archivo_reino);
				free(linea);
				destruir_reino(nuevo_reino);
				return 0;
			}
			agregar_region(nuevo_reino, *nueva_region);
			free(nueva_region);
		}
		free(linea);
		fclose(archivo_reino);
		ordenar_reino(nuevo_reino, comparar_por_ejercito);
		printf("REGIONES ORDENADAS POR EJERCITO\n");
		listar_regiones(nuevo_reino);
		ordenar_reino(nuevo_reino, comparar_por_nombre);
		printf("\n\n");
		printf("REGIONES ORDENADAS POR NOMBRE\n");
		listar_regiones(nuevo_reino);
		destruir_reino(nuevo_reino);
	}
	return 0;
}