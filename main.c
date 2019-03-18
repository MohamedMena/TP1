#include "reino.h"

int main(void){

	FILE* archivo_reino = fopen("reino.txt", "r");

	if(archivo_reino != NULL){
		char* linea;
		size_t tamanio_linea = 150;
		getline(&linea, &tamanio_linea, archivo_reino);
		size_t maximo_regiones = atoi(linea);
		reino_t* nuevo_reino = crear_reino(maximo_regiones);
		if(!nuevo_reino){
			fclose(archivo_reino);
			return 0;
		}

		while(getline(&linea, &tamanio_linea, archivo_reino) != -1){
			region_t nueva_region;
			char* datos_region = strtok(linea, ";");
			int i = 0;
			while(datos_region[i] != NULL){
				strcpy();
			}
		}
	}
	return 0;
}