#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu() {
	  int opcion;

	printf(" **** PASAJEROS ****\n");
	printf("1- Cargar pasajeros archivo texto\n");
	printf("2- Cargar pasajeros archivo binario\n");
	printf("3- Alta pasajero\n");
	printf("4- Modificar pasajero\n");
	printf("5- Baja pasajero\n");
	printf("6- Listar pasajeros\n");
	printf("7- Ordenar pasajeros\n");
	printf("8- Guardar datos de lospasajeros en archivo texto\n");
	printf("9- Guardar datos de lospasajeros en archivo binario\n");
	// Agrego opcion SALIR
	printf("10- SALIR\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}
int menuModificacion() {
	  int opcion;

	printf(" **** MENU MODIFICACION ****\n");
	printf("1- Modificar nombre\n");
	printf("2- Modificar apellido\n");
	printf("3- Modificar precio\n");
	printf("4- Modificar codigo de vuelo\n");
	printf("5- Modificar tipo de pasajero\n");
	printf("6- Modificar estado de vuelo\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}
