#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "Passenger.h"
#include "LinkedList.h"
#include "Controller.h"
#include "miBiblioteca.h"
#include "parser.h"
#include "menu.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger) {

	int todoOk = 0;
	FILE* pFile;
	pFile = fopen(path, "r");

	if (pFile != NULL && path != NULL && pArrayListPassenger != NULL) {
		if (parser_PassengerFromText(pFile, pArrayListPassenger)) {
			printf("Carga de archivo de texto exitosa\n");
			todoOk = 1;
		}
	} else {
		printf("No se pudo abrir el archivo\n");
	}
	fclose(pFile);
	return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path,LinkedList* pArrayListPassenger) {

	int todoOk  = 0;
	FILE* pFile;
	pFile = fopen(path,"rb");

	if(path != NULL && pArrayListPassenger != NULL && pFile != NULL) {
		if(parser_PassengerFromBinary(pFile,pArrayListPassenger)) {
			printf("Carga de archivo binario exitosa\n");
			todoOk = 1;
		}
	} else {
		printf("No se pudo abrir el archivo\n");
	}

	fclose(pFile);
	return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int* id) {

	ePassenger* nuevoPasajero = NULL;

	char nombre[21];
	char apellido[21];
	char codigoVuelo[10];
	char tipoPasajero[50];
	char estadoPasajero[50];
	float precio;


	int bufferInt;
	int todoOk = 0;
	if(pArrayListPassenger != NULL) {



		utnGetCadenaSoloCaracteres(nombre,"Ingrese nombre: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
		miCorregirUnaCadena(nombre);

		utnGetCadenaSoloCaracteres(apellido,"Ingrese apellido: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
		miCorregirUnaCadena(apellido);

		printf("Ingrese Codigo de vuelo, tiene que tener 7 digitos alfanumericos,(Ejemplo: AC2F6J8):");
		fflush(stdin);
		gets(codigoVuelo);
		while(miValidarLargoCadena(codigoVuelo) < 7 || miValidarLargoCadena(codigoVuelo) > 7) {
			printf("Error... Ingrese un codigo de vuelo de 7 caracteres:");
			fflush(stdin);
			gets(codigoVuelo);
		}
		miPasarAMayusculas(codigoVuelo);

		utnGetNumero(&bufferInt,"Ingrese tipo de pasajero:\n1-FirstClass\n2-ExecutiveClass\n3-EconomyClass\nIngrese su tipo: ","Error... Ingrese numero del 1 al 3\nIngrese su tipo: ",1,3);
		switch(bufferInt) {
			case 1:
				strcpy(tipoPasajero,"FirstClass");
				break;
			case 2:
				strcpy(tipoPasajero,"ExecutiveClass");
				break;
			case 3:
				strcpy(tipoPasajero,"EconomyClass");
				break;
		}

		utnGetNumero(&bufferInt,"Estado de pasajero\n1-Aterrizado\n2-En Horario\n3-Demorado\n4-En Vuelo\nIngrese su estado: ","Error... Ingrese numero del 1 al 4\nIngrese su Estado: ",1,4);
		switch(bufferInt) {
			case 1:
				strcpy(estadoPasajero,"Aterrizado");
				break;
			case 2:
				strcpy(estadoPasajero,"En Horario");
				break;
			case 3:
				strcpy(estadoPasajero,"Demorado");
				break;
			case 4:
				strcpy(estadoPasajero,"En Vuelo");
				break;
		}
		utnGetNumeroFlotanteSoloMinimo(&precio,"Ingrese precio:","Error...Ingrese precio mayor a 0",0.1);

		nuevoPasajero = Passenger_new();

		if(nuevoPasajero != NULL) {
			if( Passenger_setId(nuevoPasajero,*id) &&
				Passenger_setNombre(nuevoPasajero,nombre) &&
				Passenger_setApellido(nuevoPasajero,apellido) &&
				Passenger_setPrecio(nuevoPasajero,precio) &&
				Passenger_setCodigoVuelo(nuevoPasajero,codigoVuelo) &&
				Passenger_setTipoPasajero(nuevoPasajero,tipoPasajero) &&
				Passenger_setEstadoVuelo(nuevoPasajero,estadoPasajero))	{

				ll_add(pArrayListPassenger,nuevoPasajero);
				(*id)++;
				printf("\nPasajero agregado con exito!!\n");

				todoOk = 1;
			} else {
				free(nuevoPasajero);
				printf("Ocurrio un error en el alta\n");
				system("pause");
			}
		}
	}
	else {
		printf("No hay espacio para generar otro alta\n");
		system("pause");
	}
	return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger) {
	ePassenger* auxPassenger = NULL;

	int idIngresado;//Por el usuario
	int indice = -1;//

	char nombre[21];
	char apellido[21];
	float precio;
	char codigoVuelo[7];
	char tipoPasajero[50];
	char estadoPasajero[50];

	int bufferInt;
	int todoOk = 0;

	if(pArrayListPassenger != NULL)	{
		printf("  **** MODIFICACION DE PASAJERO ****\n");

		controller_ListPassenger(pArrayListPassenger);

		idIngresado = miIngresarEntero("Ingrese ID del pasajero a modificar: ");
		auxPassenger = controller_searchPassengerID(pArrayListPassenger,idIngresado,&indice);
		if(indice != -1) {
			controller_showPassenger(auxPassenger);
			switch(menuModificacion()) {
			case 1:
				utnGetCadenaSoloCaracteres(nombre, "Ingrese nombre: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
				miCorregirUnaCadena(nombre);
				Passenger_setNombre(auxPassenger,nombre);
				todoOk = 1;
				break;
			case 2:
				utnGetCadenaSoloCaracteres(apellido, "Ingrese apellido: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
				miCorregirUnaCadena(apellido);
				Passenger_setApellido(auxPassenger,apellido);
				todoOk = 1;
				break;
			case 3:
				utnGetNumeroFlotanteSoloMinimo(&precio,"Ingrese precio:","Error...Ingrese precio mayor a 0",0.1);
				Passenger_setPrecio(auxPassenger,precio);
				todoOk = 1;
				break;
			case 4:
				printf("Ingrese Codigo de vuelo, tiene que tener 7 digitos alfanumericos,(Ejemplo: AC2F6J8):");
				fflush(stdin);
				gets(codigoVuelo);

				while(miValidarLargoCadena(codigoVuelo) < 7 || miValidarLargoCadena(codigoVuelo) > 7) {
					printf("Error... Ingrese un codigo de vuelo de 7 caracteres:");
					fflush(stdin);
					gets(codigoVuelo);
				}
				miPasarAMayusculas(codigoVuelo);
				Passenger_setCodigoVuelo(auxPassenger,codigoVuelo);
				todoOk = 1;
				break;
			case 5:
				utnGetNumero(&bufferInt,"Ingrese tipo de pasajero:\n1-FirstClass\n2-ExecutiveClass\n3-EconomyClass\n","Error... Ingrese numero del 1 al 3: ",1,3);
				switch(bufferInt) {
					case 1:
						strcpy(tipoPasajero,"FirstClass");
						break;
					case 2:
						strcpy(tipoPasajero,"ExecutiveClass");
						break;
					case 3:
						strcpy(tipoPasajero,"EconomyClass");
						break;
					}
				todoOk = 1;
					break;
				case 6:
					utnGetNumero(&bufferInt,"Ingrese tipo de pasajero\n1-Aterrizado\n2-En Horario\n3-Demorado\n4-En Vuelo\n","Error... Ingrese numero del 1 al 4: ",1,4);
					switch(bufferInt) {
						case 1:
							strcpy(estadoPasajero,"Aterrizado");
							break;
						case 2:
							strcpy(estadoPasajero,"En Horario");
							break;
						case 3:
							strcpy(estadoPasajero,"Demorado");
							break;
						case 4:
							strcpy(estadoPasajero,"En Vuelo");
							break;
						}
						break;
					todoOk = 1;
					break;
				default:
					printf("OPCION INVALIDA!\nVolvera al menu\n");
					system("pause");
					break;
				}

		} else {
			printf("*** Pasajero el id %d no existe. ****\n",idIngresado);
			system("pause");
		}
	}
	return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger) {
	ePassenger* auxPassenger = NULL;
	int idIngresado;//Por el usuario
	int indice = -1;
	int confirmacion;
	int todoOk = 0;

	if(pArrayListPassenger != NULL)	{
		controller_ListPassenger(pArrayListPassenger);
		idIngresado = miIngresarEntero("Ingresa ID del pasajero a remover: ");
		auxPassenger = controller_searchPassengerID(pArrayListPassenger,idIngresado,&indice);

		if(indice != -1) {
			printf("CONFIRMACION DE BAJA\n");
			controller_showPassenger(auxPassenger);
			printf("Confirma baja este pasajero?:\n");
			printf("1 - SI\n");
			printf("Cualquier tecla - NO\n");
			scanf("%d", &confirmacion);
			if(confirmacion == 1) {
				if(ll_remove(pArrayListPassenger,indice) == 0) {
					printf("Pasajero removido con exito\n");
					todoOk = 1;
					system("pause");
				}
				Passenger_delete(auxPassenger);
			} else {
				printf("Baja cancelada\n");
				system("pause");
			}
		} else {
			printf("Pasajero con id %d no se encuentra en el sistema\n",idIngresado);
			system("pause");
			todoOk = -1;
		}
	}
	return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger){
	ePassenger* pAuxPassenger = NULL;
	int todoOk = 0;
	int len;

	if(pArrayListPassenger != NULL)	{
		len =  ll_len(pArrayListPassenger);
		if(len > 0) {
			printf("              ***LISTA PASAJEROS  ***\n");
			printf("------------------------------------------------------------------------------------\n");
			printf(" ID  NOMBRE        APELLIDO        PRECIO   CODIGOVUELO    TIPOPASAJERO     ESTADOVUELO  MILLAS \n");
			printf("-------------------------------------------------------------------------------------\n");
			for(int i = 0; i < len; i++) {
				pAuxPassenger = ll_get(pArrayListPassenger,i);
				controller_showPassenger(pAuxPassenger);
			}
			todoOk =1;
		}
	}
	return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int opcion;
	int orden;
	if (pArrayListPassenger != NULL)
	{
		todoOk = 1;
		printf("Ordenar empleados\n");

		utnGetNumero(&orden,"Como desea ordenar?\n0 Descendente\n1 Ascendente\n","ERROR... Ingrese 1 para Asc y 0 para Desc\n",0,1);
		utnGetNumero(&opcion,"Criterio de ordenamiento:\n1-Id\n2-Nombre\n3-Apellido\n4-Codigo de vuelo\n5- Precio\n6-SALIR\n","ERROR...\n1-Id\n2-Nombre\n3-Apellido\n4-Codigo de vuelo\n5- Precio\n6-SALIR\n",0,6);

		switch (opcion)	{
			case 1:
				printf("ORDENADO POR ID");
				ll_sort(pArrayListPassenger,controller_CompararId, orden);
				controller_ListPassenger(pArrayListPassenger);
				break;
			case 2:
				printf("ORDENADO POR NOMBRE");
				ll_sort(pArrayListPassenger, controller_CompararNombre,orden);
				controller_ListPassenger(pArrayListPassenger);
				break;
			case 3:
				printf("ORDENADO POR APELLIDO");
				ll_sort(pArrayListPassenger, controller_CompararApellido,orden);
				controller_ListPassenger(pArrayListPassenger);
				break;
			case 4:
				printf("ORDENADO POR PRECIOS");
				ll_sort(pArrayListPassenger, controller_CompararPrecios,orden);
				controller_ListPassenger(pArrayListPassenger);
				break;
			case 5:
				printf("ORDENADO POR CODIGO DE VUELO");
				ll_sort(pArrayListPassenger, controller_CompararCodigoVuelo,orden);
				controller_ListPassenger(pArrayListPassenger);
				break;
			case 6:
				printf("SALIO DEL MENU ORDENAMIENTO\n");
				system("pause");
				break;
		}
	}
	return todoOk;
}
int controller_InformePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int contadorInforme1;
	char cogidoInforme2[100];
	LinkedList* nuevaListaInforme2 = NULL;
	if (pArrayListPassenger != NULL)
	{
		todoOk = 1;
		printf("Informe empleados\n");

		switch (menuInformes())	{
			case 1:
				printf("INFORME - CANTIDAD DE PASS POR CLASE\n");
				switch(subMenuInforme1()) {
					case 1:
						contadorInforme1 = ll_count(pArrayListPassenger,controller_InformeEconomyClass);
						if(contadorInforme1 >= 0) {
							printf("De la clase economica hay %d pasajeros\n",contadorInforme1);
						} else {
							printf("ERROR\n");
							system("pause");
						}
						break;
					case 2:
						contadorInforme1 = ll_count(pArrayListPassenger,controller_InformeFirstClass);
						if(contadorInforme1 >= 0) {
							printf("De la primer clase hay %d pasajeros\n",contadorInforme1);
						} else {
							printf("ERROR\n");
							system("pause");
						}
						 break;
					case 3:
						contadorInforme1 = ll_count(pArrayListPassenger,controller_InformeExecutiveClass);
						if(contadorInforme1 >= 0) {
							printf("De la clase ejecutva hay %d pasajeros\n",contadorInforme1);
						} else {
							printf("ERROR\n");
							system("pause");
						}
						break;
				}
				break;
			case 2:
				printf("NUEVA LISTA - ARCHIVO\n");
				printf("Ingrese codigo de vuelo:\n");
				fflush(stdin);
				scanf("%s",cogidoInforme2);
				nuevaListaInforme2 = ll_filter(pArrayListPassenger, controller_SegundoInforme, cogidoInforme2);
				// controller_saveAsText("data",listaPasajeros);
				controller_saveAsText("codVueloArchivo",nuevaListaInforme2);
				break;
			case 3:
				printf("AGREGAR MILLAS\n");
				break;
			case 4:
				printf("INFORME - CLASE ECONOMICA\n");
				ll_Informe(pArrayListPassenger,controller_InformeEconomyClass);
				break;
			case 5:
				printf("INFORME - Precio total y promedios\n");
				informesPrecioPromedios(pArrayListPassenger);
				break;
			default:
				printf("ERROR...\n");

		}
	}
	return todoOk;
}
/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger) {

	int todoOk = 0;
	int id;
	char nombre[100];
	char apellido[100];
	float precio;
	char codigoVuelo[100];
	char tipoPasajero[100];
	char estadoVuelo[100];
	int len;

	FILE* pFile;
	pFile = fopen(path, "w");
	ePassenger* auxPassenger = NULL;

	if (path != NULL && pArrayListPassenger != NULL && pFile != NULL) {

		len = ll_len(pArrayListPassenger);

		//fprintf(pFile, "id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo\n");

		for (int i = 0; i < len; i++) {

			auxPassenger = ll_get(pArrayListPassenger, i);

			Passenger_getId(auxPassenger,&id);
			Passenger_getNombre(auxPassenger,nombre);
			Passenger_getApellido(auxPassenger,apellido);
			Passenger_getPrecio(auxPassenger,&precio);
			Passenger_getCodigoVuelo(auxPassenger,codigoVuelo);
			Passenger_getTipoPasajero(auxPassenger,tipoPasajero);
			Passenger_getEstadoVuelo(auxPassenger,estadoVuelo);

			fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n", id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

			todoOk = 1;
		}
			printf("EL archivo se guardo exitosamente\n");
	} else {
		printf("No se pudo abrir el archivo\n");
	}

	fclose(pFile);

	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger) {
	int todoOk = 0;
	FILE* pFile;
	ePassenger* auxPassenger;

	if (path != NULL && pArrayListPassenger != NULL) {
		pFile = fopen(path, "wb");
		if (pFile == NULL) {
			printf("No se pudo abrir el archivo\n");
		}

		for (int i = 0; i < ll_len(pArrayListPassenger); i++) {
			auxPassenger = ll_get(pArrayListPassenger, i);
			if ((auxPassenger) != NULL)	{
				fwrite(auxPassenger, sizeof(ePassenger), 1, pFile);
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int controller_showPassenger(ePassenger* pPassenger) {

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	char tipoPasajero[50];
	char estadoVuelo[50];
	int millas;

    int todoOk = 0;

    if(pPassenger != NULL &&
		Passenger_getId(pPassenger,&id) &&
		Passenger_getNombre(pPassenger,nombre) &&
		Passenger_getApellido(pPassenger,apellido) &&
		Passenger_getPrecio(pPassenger,&precio) &&
		Passenger_getCodigoVuelo(pPassenger,codigoVuelo) &&
		Passenger_getTipoPasajero(pPassenger,tipoPasajero) &&
		Passenger_getEstadoVuelo(pPassenger,estadoVuelo))
    {
    	Passenger_getMilla(pPassenger,&millas);
        printf("%3d %-15s%-15s%5.2f    %-15s   %-15s   %-15s %d\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo,millas);
        todoOk = 1;
    }
    return todoOk;
}

int controller_IdSiguiente(LinkedList* pArrayListPassenger) {
	ePassenger* auxPassenger = NULL;
	int maximo;
	int id;
	int len;
	if(pArrayListPassenger != NULL)	{
		len = ll_len(pArrayListPassenger);
		for(int i = 0; i < len ; i++) {
			auxPassenger = ll_get(pArrayListPassenger,i);
			Passenger_getId(auxPassenger, &id);
			if(id > maximo || i == 0) {
				maximo = id;
			}
		}
	}
	return maximo;
}

ePassenger* controller_searchPassengerID(LinkedList* pArrayListPassenger,int id, int* index) {

	ePassenger* auxPassenger = NULL;
	int auxId;
	*index = -1;
	int len = ll_len(pArrayListPassenger);
	for(int i = 0 ; i < len ; i++ )	{
		auxPassenger  = (ePassenger*) ll_get(pArrayListPassenger,i);
		Passenger_getId(auxPassenger ,&auxId);
		if(auxPassenger  != NULL && auxId == id) {
			(*index) = i;
			break;
		}
	}
	return auxPassenger;
}

int controller_CompararNombre(void* a, void* b) {

	int todoOk = 0;
	char auxNombreA[40];
	char auxNombreB[40];

	if(a != NULL && b != NULL) {
		strcpy(auxNombreA,((ePassenger*)a)->nombre);
		strcpy(auxNombreB,((ePassenger*)b)->nombre);
		todoOk = strcmp(auxNombreA,auxNombreB);
	}
	return todoOk;
}

int controller_CompararApellido(void* a, void* b) {

	int todoOk = 0;
	char auxApellidoA[40];
	char auxApellidoB[40];

	if(a != NULL && b != NULL) {
		strcpy(auxApellidoA,((ePassenger*)a)->apellido);
		strcpy(auxApellidoB,((ePassenger*)b)->apellido);
		todoOk = strcmp(auxApellidoA,auxApellidoB);
	}
	return todoOk;
}

int controller_CompararId(void* a, void* b ) {

	int todoOk;
	if(a != NULL && b != NULL) {
		if(((ePassenger*)a)->id > ((ePassenger*)b)->id)	{
			todoOk = 1;
		} else {
			if(((ePassenger*)a)->id < ((ePassenger*)b)->id) {
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

int controller_CompararPrecios(void* a, void* b) {

	int todoOk = 0;
	if(a != NULL && b != NULL) {
		if(((ePassenger*)a)->precio > ((ePassenger*)b)->precio) {
			todoOk = 1;
		} else {
			if(((ePassenger*)a)->precio < ((ePassenger*)b)->precio) {
				todoOk = -1;
			}
		}
	}
	return todoOk;
}


int controller_CompararCodigoVuelo(void* a, void* b) {

	int todoOk = 0;
	char auxCodigoA[40];
	char auxCodigoB[40];

	if(a != NULL && b != NULL) {
		strcpy(auxCodigoA,((ePassenger*)a)->codigoVuelo);
		strcpy(auxCodigoB,((ePassenger*)b)->codigoVuelo);
		todoOk = strcmp(auxCodigoA,auxCodigoB);
	}
	return todoOk;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INFORMES.

int informesPrecioPromedios(LinkedList* pArrayListPassenger) {

	int ok=0;
	ePassenger* auxPassenger = NULL;
	float acumulador = 0;
	int contador = 0;

	int len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL) {
		for(int i = 0 ; i < len ; i++ )	{
			auxPassenger  =  (ePassenger*) ll_get(pArrayListPassenger,i);
			if(auxPassenger  != NULL ) {
				acumulador += auxPassenger->precio;
				contador ++;
			}
		}

		if(contador > 0) {
			printf("La suma de los precios es: %.2f\n", acumulador);
			printf("El promedio es: %.2f\n", (acumulador / (float)contador));
		} else {
			printf("No hay ningun precio para promediar\n");
		}
	}

	return ok;
}

/////////////////////////////////////////////////////////////////////////////

int controller_InformeEconomyClass(void* a) {
	int todoOk = 0;

	if(a != NULL) {
		if(!strcmp(((ePassenger*)a)->tipoPasajero,"EconomyClass")) {
			todoOk = 1;
		}
	}
	return todoOk;
}

int controller_InformeExecutiveClass(void* a) {
	int todoOk = 0;

	if(a != NULL) {
		if(!strcmp(((ePassenger*)a)->tipoPasajero,"ExecutiveClass")) {
			todoOk = 1;
		}
	}
	return todoOk;
}

int controller_InformeFirstClass(void* a) {
	int todoOk = 0;

	if(a != NULL) {
		if(!strcmp(((ePassenger*)a)->tipoPasajero,"FirstClass")) {
			todoOk = 1;
		}
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////

int controller_SegundoInforme(void* a, char* codigo) {
	int todoOk = 0;

	if(a != NULL) {
		if(!strcmp(((ePassenger*)a)->codigoVuelo,codigo)) {
			todoOk = 1;
		}
	}
	return todoOk;
}

//////////////////////////////////////////////////////////////////////////////////////

ePassenger*  controller_MapTercerInforme(void* a) {

	int millas;
	float aux;

	if(1) {

		aux = ((ePassenger*)a)->precio / (float)100;
		millas = (int)aux;
		if(controller_InformeFirstClass((ePassenger*)a)) {
				millas = millas * 2;
		} else if (controller_InformeExecutiveClass((ePassenger*)a)) {
			millas = millas * 3;
		}
		((ePassenger*)a)->millas = millas;
		printf("Las millas de %s son: %d\n",((ePassenger*)a)->nombre,((ePassenger*)a)->millas);
	}
	return ((ePassenger*)a);
}
