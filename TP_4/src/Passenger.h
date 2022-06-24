#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[50];
	char estadoVuelo[50];
	int millas;

}ePassenger;

ePassenger* Passenger_new();
ePassenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr);

void Passenger_delete();

int Passenger_setId(ePassenger* this,int id);
int Passenger_getId(ePassenger* this,int* id);

int Passenger_setMilla(ePassenger* this,int milla);
int Passenger_getMilla(ePassenger* this,int* milla);

int Passenger_setNombre(ePassenger* this,char* nombre);
int Passenger_getNombre(ePassenger* this,char* nombre);

int Passenger_setApellido(ePassenger* this,char* apellido);
int Passenger_getApellido(ePassenger* this,char* apellido);

int Passenger_setPrecio(ePassenger* this,float precio);
int Passenger_getPrecio(ePassenger* this,float* precio);

int Passenger_setCodigoVuelo(ePassenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(ePassenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(ePassenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(ePassenger* this,char* tipoPasajero);

int Passenger_setEstadoVuelo(ePassenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(ePassenger* this,char* estadoVuelo);

#endif /* PASSENGER_H_ */
