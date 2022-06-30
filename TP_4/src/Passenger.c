#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "miBiblioteca.h"

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

    return nuevoPasajero;
}

ePassenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr,char* millas) {

	ePassenger* pPassenger = Passenger_new();

	if(pPassenger != NULL) {
		Passenger_setId(pPassenger,(atoi(idStr)));
		Passenger_setNombre(pPassenger,nombreStr);
		Passenger_setApellido(pPassenger,apellidoStr);
		Passenger_setPrecio(pPassenger,(atof(precioStr)));
		Passenger_setCodigoVuelo(pPassenger,codigoVueloStr);
		Passenger_setTipoPasajero(pPassenger,tipoPasajeroStr);
		Passenger_setEstadoVuelo(pPassenger,estadoVueloStr);
		Passenger_setMilla(pPassenger,(atoi(millas)));
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

int Passenger_setMilla(ePassenger* this,int milla) {

	int todoOk = 0;
	if(this != NULL && milla > 0) {
		this->id = milla;
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getMilla(ePassenger* this,int* milla) {

	int todoOk = 0;
	if(this != NULL && milla != NULL) {
		*milla = this->millas;
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

////////////////////////////////////////////////////////////////////////// PRACTICA

float Passenger_PrecioPorCodivoVuelo(void* a) {

	float price;
	char pedirCodVuelo[10];
	char codigo[10];
	ePassenger* passenger = (ePassenger*)a;

	if(a != NULL) {

		miGetCadena("Ingrese codigo de vuelo",pedirCodVuelo);
		Passenger_getCodigoVuelo(passenger,codigo);
		if(!strcmp(pedirCodVuelo,codigo)) {
			price = passenger->precio;
		}
	}
	return price;
}

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int Passenger_InformeEconomyClass(void* a) {

	int todoOk = -1;
	char tipoPasajero[50];

	if(a != NULL) {
		Passenger_getTipoPasajero(a,tipoPasajero);
		if(!strcmp(tipoPasajero,"EconomyClass")) {
			todoOk = 1;
		}
	}
	return todoOk;
}

int Passenger_InformeExecutiveClass(void* a) {

	int todoOk = -1;
	char tipoPasajero[50];

	if(a != NULL) {

		Passenger_getTipoPasajero(a,tipoPasajero);
		if(!strcmp(tipoPasajero,"ExecutiveClass")) {
			todoOk = 1;
		}
	}
	return todoOk;
}
// PASAR A PASSENGER
int Passenger_InformeFirstClass(void* a) {

	int todoOk = -1;
	char tipoPasajero[50];

	if(a != NULL) {
		Passenger_getTipoPasajero(a,tipoPasajero);
		if(!strcmp(tipoPasajero,"FirstClass")) {
			todoOk = 1;
		}
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////

int Passenger_SegundoInforme(void* a) {

	int todoOk = 0;
	char tipoPasajero[50];

	if(a != NULL) {
		Passenger_getTipoPasajero(a,tipoPasajero);
		if(!strcmp(tipoPasajero,"FirstClass")) {
			todoOk = 1;
		}
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////////

void Passenger_MapTercerInforme(void* a) {

	int millas;
	float aux;

	if(a != NULL) {
		Passenger_getPrecio(a,&aux);
		aux = aux / (float)100;
		millas = (int)aux;
		if(Passenger_InformeFirstClass((ePassenger*)a)) {
			millas = millas * 2;
		} else if (Passenger_InformeExecutiveClass((ePassenger*)a)) {
			millas = millas * 3;
		}
		Passenger_setMilla(a,millas);
	//	printf("Las millas de %s son: %d\n",((ePassenger*)a)->nombre,((ePassenger*)a)->millas);
	}
}

