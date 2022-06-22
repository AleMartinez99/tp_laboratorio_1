#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"

/*
  	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[50];
	char estadoVuelo[50];
 */

ePassenger* Passenger_new() { // Retorna un puntero a passenger

	ePassenger* nuevoPasajero = (ePassenger*) malloc(sizeof(ePassenger));
    if(nuevoPasajero != NULL )
    {
    	nuevoPasajero->id = 0;
        strcpy(nuevoPasajero->nombre,"");
        strcpy(nuevoPasajero->apellido,"");
        nuevoPasajero->precio = 0;
        strcpy(nuevoPasajero->codigoVuelo,"");
        strcpy(nuevoPasajero->tipoPasajero,"");
        strcpy(nuevoPasajero->estadoVuelo,"");
    }
    return nuevoPasajero;
}

ePassenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr) {

	ePassenger* pPassenger = Passenger_new();

	if(pPassenger != NULL) {
		Passenger_setId(pPassenger,(atoi(idStr)));
		Passenger_setNombre(pPassenger,nombreStr);
		Passenger_setApellido(pPassenger,apellidoStr);
		Passenger_setPrecio(pPassenger,(atof(precioStr)));
		Passenger_setCodigoVuelo(pPassenger,codigoVueloStr);
		Passenger_setTipoPasajero(pPassenger,tipoPasajeroStr);
		Passenger_setEstadoVuelo(pPassenger,estadoVueloStr);
	}
	return pPassenger;
}

//////////////////////////////////////////////////////////////////////////////////

void Passenger_delete(ePassenger* this) {

	if(this!= NULL) {
		free(this);
	}
}

//////////////////////////////////////////////////////////////////////////////////

int Passenger_setId(ePassenger* this,int id) {

	int todoOk = 0;
	if(this != NULL && id > 0) {
		this->id = id;
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getId(ePassenger* this,int* id) {

	int todoOk = 0;
	if(this != NULL && id != NULL) {
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////

int Passenger_setNombre(ePassenger* this,char* nombre) {

	int todoOk = 0;

	if(this != NULL) {
		strcpy(this->nombre,nombre);
		todoOk = 1;
	}
	return todoOk;

}
int Passenger_getNombre(ePassenger* this,char* nombre) {

	int todoOk = 0;

	if(this != NULL && nombre != NULL) {
		strcpy(nombre,this->nombre);
		todoOk = 1;
	}
	return todoOk;
}
//////////////////////////////////////////////////////////////////////////////////

int Passenger_setApellido(ePassenger* this,char* apellido) {

	int todoOk = 0;

	if(this != NULL) {
		strcpy(this->apellido,apellido);
		todoOk = 1;
	}
	return todoOk;

}
int Passenger_getApellido(ePassenger* this,char* apellido) {

	int todoOk = 0;

	if(this != NULL && apellido != NULL) {
		strcpy(apellido,this->apellido);
		todoOk = 1;
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////

int Passenger_setPrecio(ePassenger* this,float precio) {
	int todoOk = 0;

	if(this != NULL) {
		this->precio = precio;
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getPrecio(ePassenger* this,float* precio) {

	int todoOk = 0;

	if(this != NULL && precio != NULL) {
		*precio = this->precio;
		todoOk = 1;
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////

int Passenger_setCodigoVuelo(ePassenger* this,char* codigoVuelo) {
	int todoOk = 0;

	if(this != NULL) {
		strcpy(this->codigoVuelo,codigoVuelo);
		todoOk = 1;
	}
	return todoOk;

}
int Passenger_getCodigoVuelo(ePassenger* this,char* codigoVuelo) {

	int todoOk = 0;

	if(this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo,this->codigoVuelo);
		todoOk = 1;
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////

int Passenger_setTipoPasajero(ePassenger* this,char* tipoPasajero) {

	int todoOk = 0;

	if(this != NULL) {
		strcpy(this->tipoPasajero,tipoPasajero);
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getTipoPasajero(ePassenger* this,char* tipoPasajero) {

	int todoOk = 0;

	if(this != NULL && tipoPasajero != NULL) {
		strcpy(tipoPasajero,this->tipoPasajero);
		todoOk = 1;
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////

int Passenger_setEstadoVuelo(ePassenger* this,char* estadoVuelo) {

	int todoOk = 0;

	if(this != NULL && estadoVuelo != NULL) {
		strcpy(this->estadoVuelo,estadoVuelo);
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getEstadoVuelo(ePassenger* this,char* estadoVuelo){

	int todoOk = 0;

	if(this != NULL && estadoVuelo != NULL)	{
		strcpy(estadoVuelo,this->estadoVuelo);
		todoOk = 1;
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////
