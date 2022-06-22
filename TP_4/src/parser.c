#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger) {

	ePassenger* pPassengerAux;
	int cantLeida;
	char buffer[7][128];
	int todoOk = 0;

	if(pFile != NULL && pArrayListPassenger != NULL) {
		 do {
			 cantLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);

			if(cantLeida < 7) {
				break;
			}
			pPassengerAux = Passenger_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);

			if(pPassengerAux != NULL) {
				ll_add(pArrayListPassenger,pPassengerAux);
				todoOk = 1;
			}
		} while(!feof(pFile));
	} else {
		printf("Error abriendo el archivo\n");
		todoOk = 0;
		system("pause");
	}
	fclose(pFile);

	return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger) {

	int todoOk = 0;
	int cantidad; //Cantidad leida

	ePassenger* auxPassenger;

	int auxId;
	char auxNombre[128];
	char auxApellido[128];
	float auxPrecio;
	char auxCodigoVuelo[128];
	char auxTipoPasajero[128];
	char auxEstadoVuelo[128];

	if(pFile != NULL && pArrayListPassenger != NULL) {
		do {
			auxPassenger = Passenger_new();
			cantidad = fread(auxPassenger,sizeof(ePassenger),1,pFile);

			if( auxPassenger != NULL && cantidad == 1 &&
				Passenger_getId(auxPassenger,&auxId) &&
				Passenger_getNombre(auxPassenger,auxNombre) &&
				Passenger_getApellido(auxPassenger,auxApellido) &&
				Passenger_getPrecio(auxPassenger,&auxPrecio) &&
				Passenger_getCodigoVuelo(auxPassenger,auxCodigoVuelo) &&
				Passenger_getTipoPasajero(auxPassenger,auxTipoPasajero) &&
				Passenger_getEstadoVuelo(auxPassenger,auxEstadoVuelo)) {

				ll_add(pArrayListPassenger,auxPassenger);
				todoOk = 1;
			}
		}
		while(!feof(pFile));
	}

	fclose(pFile);
	return todoOk;
}
