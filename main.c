#include "reino.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void){

	FILE* archivo_reino = fopen("reino.txt", "r");

	if(archivo_reino != NULL){
		char* linea = NULL;
		int tamanio_linea = 150;
		if(!fgets(linea, tamanio_linea, archivo_reino)){
			fclose(archivo_reino);
			return 0;
		}
		size_t maximo_regiones = (size_t)atoi(linea);
		reino_t* nuevo_reino = crear_reino(maximo_regiones);
		if(!nuevo_reino){
			fclose(archivo_reino);
			return 0;
		}

		bool leyo = (fgets(linea, tamanio_linea, archivo_reino) != NULL);

		while(feof(archivo_reino) == 0 && leyo){
			region_t nueva_region;
			char* datos_region = strtok(linea, ";");
			int i = 0;
			while(datos_region != NULL){
				if(i == 0){
					strcpy(nueva_region.nombre, linea);
				}else if(i == 1){
					strcpy(nueva_region.lema, linea);
				}else if(i == 2){
					nueva_region.ejercito = atoi(linea);
				}
				i++;
				datos_region = strtok(linea, ";");
			}
			agregar_region(nuevo_reino, nueva_region);
			leyo = (fgets(linea, tamanio_linea, archivo_reino) != NULL);
		}
		ordenar_reino(nuevo_reino, comparar_por_ejercito);
		listar_regiones(nuevo_reino);
		ordenar_reino(nuevo_reino, comparar_por_nombre);
		listar_regiones(nuevo_reino);
	}
	return 0;
}