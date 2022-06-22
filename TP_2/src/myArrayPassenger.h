#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"


#ifndef MYARRAYPASSENGER_H_
#define MYARRAYPASSENGER_H_

#endif /* MYARRAYPASSENGER_H_ */

/// @brief Permite la carga de los datos para el pasajero
///
/// @pre
/// @post
/// @param pId
/// @param name
/// @param lastName
/// @param pPrice
/// @param flyCode
/// @param pTypePassenger
/// @param pStatusFlight
/// @return retorna 1 si pudo cargar los datos, 0 sino
int loadPassenger(int* pId, char name[], char lastName[],float* pPrice, char flyCode[],int* pTypePassenger,int* pStatusFlight);

/// @brief Busca el primer lugar libre del array
///
/// @pre
/// @post
/// @param list
/// @param len
/// @return retorna el indice del primer lugar libre, -1 en caso de no poder o estar lleno
int searchFree(ePassenger* list, int len);

/// @brief Busca si al menos una posicion del array esta ocupada
///
/// @pre
/// @post
/// @param lista
/// @param tam
/// @return retorna 1 si puedo encontrarla, 0 sino
int searchFull(ePassenger lista[], int tam);

/// @brief Permite imprimir los datos de un pasajero
///
/// @pre
/// @post
/// @param aPassenger
void printPassenger(ePassenger aPassenger);

/// @brief Permite modificar los datos de un pasajero
///
/// @pre
/// @post
/// @param list
/// @param len
/// @return retorna 1 si pudo modificar, 0 sino
int modifyPassenger(ePassenger list[], int len);

/// @brief informe sobre el precio del pasaje
///
/// @pre
/// @post
/// @param list
/// @param len
/// @return retorna 1 si pudo, 0 sino
int informarPrecios(ePassenger list[], int len);

/// @brief Imprime el menu de opciones general
///
/// @pre
/// @post
/// @return retorna la opcion elegida
int menu();

/// @brief Imprime el menu de opciones para los informes
///
/// @pre
/// @post
/// @param list
/// @param len
void menuInformes(ePassenger list[],int len);
/// @brief Permite imprimir los pasajeros ACTIVOS
///
/// @pre
/// @post
/// @param list
/// @param len
/// @return
int printPassengersActive(ePassenger list[], int len);


