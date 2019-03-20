#ifndef REINO_H
#define REINO_H

#include <stdio.h>
#include <stdlib.h>
/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

typedef struct region{
	char nombre [50];
	char lema [50];
	int ejercito;
}region_t;

typedef struct reino{
	region_t* regiones;
	int cantidad_regiones;
	size_t maximo_regiones;
}reino_t;

/* ******************************************************************
 *                DEFINICION DE LAS FUNCIONES
 * *****************************************************************/

/*
* Creará la estructura reino , reservando la memoria necesaria .
* Recibe el máximo de regiones que pueden ser cargadas ,
* esta cantidad sirve para revervar la memoria necesaria
* para el vector de regiones .
* Devolverá la estructura , con el tope inicializado en 0.
* En caso de no poder crear el reino , devolverá NULL .
*/
reino_t* crear_reino (size_t maximo_regiones);

/*
* Destruirá la estructura creada para manipular el reino ,
* liberando la memoria reservada para él y sus regiones .
* Devolverá 0 si pudo liberar la memoria o 1 si no pudo .
*/
int destruir_reino (reino_t* reino);

/*
* Agregará una región al vector de regiones del reino .
* Devolverá 0 si pudo agregarla o 1 si no pudo .
*/
int agregar_region (reino_t* reino, region_t region);

/*
* Ordenará el vector de regiones dentro del reino .
* La función de comparación de regiones vendrá como parámetro ,
* esto permite ordenar el reino por cualquiera de los campos
* de la región .
*/
void ordenar_reino (reino_t* reino, int (*comparar_regiones) (region_t, region_t));

//Crea una nueva region a partir de los datos en formato csv
region_t* crear_region(char* datos_region);

/*
* Listará por pantalla las regiones del reino .
*/
void listar_regiones (reino_t* reino);

// Devuelve el nombre de una region
char* obtener_nombre_region(region_t region);

// Devuelve la cantidad de ejercito de una region
int obtener_cantidad_ejercito(region_t region);

#endif