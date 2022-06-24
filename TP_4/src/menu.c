#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "miBiblioteca.h"

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
	printf("10- INFORMES\n");
	// Agrego opcion SALIR
	printf("12- SALIR\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int menuInformes() {
	int opcion;

	printf(" **** MENU INFORMES ****\n");
	printf("1- CANT POR CLASE\n");
	printf("2- generar archivo vuelo\n");
	printf("3- calcular millas acumuladas\n");
	printf("4- MIINFORME clase economica\n");
	printf("5- MIINFORME PRECIOS\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int subMenuInforme1() {
	int opcion;

	utnGetNumero(&opcion,"\n1- Economica\n2- Primera\n3- Ejecutiva\n","Error... \n1- Economica\n2- Primera\n3- Ejecutiva:",1,3);

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
