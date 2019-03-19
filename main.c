#define _POSIX_C_SOURCE 200809L
#include "reino.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
			region_t nueva_region;
			char* datos_region = strtok(linea, ";");
			int i = 0;
			while(datos_region != NULL){
				if(i == 0){
					strcpy(nueva_region.nombre, datos_region);
				}else if(i == 1){
					strcpy(nueva_region.lema, datos_region);
				}else if(i == 2){
					nueva_region.ejercito = atoi(datos_region);
				}
				i++;
				datos_region = strtok(NULL, ";");
			}
			agregar_region(nuevo_reino, nueva_region);
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