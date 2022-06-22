#include "arrayPassenger.h"
#include "myArrayPassenger.h"
#include "my_library.h"

int initPassengers(ePassenger list[], int len)
{
	int ok = 0;

	if(list != NULL && len > 0) {
		for(int i = 0; i<len;i++) {
			list[i].isEmpty = 1;
		}
		ok = 1;
	}
	return ok;
}

int addPassenger(ePassenger list[], int id, char name[], char lastName[], float price,  char flyCode[],int typePassenger,int statusFlight, int len)
{
	int ok = 0;
	int indice;
	ePassenger auxPassenger;

	if(list != NULL && name != NULL && lastName != NULL && flyCode != NULL) {

		indice = searchFree(list,len);

		auxPassenger.id = id;
		strcpy(auxPassenger.name,name);
		strcpy(auxPassenger.lastName,lastName);
		strcpy(auxPassenger.flyCode,flyCode);
		auxPassenger.price = price;
		auxPassenger.typePassenger = typePassenger;
		auxPassenger.statusFlight = statusFlight;

		auxPassenger.isEmpty = 0;

		list[indice] = auxPassenger;

		ok = 1;
	}
	return ok;
}

int findPassengerById(ePassenger list[], int id, int len)
{
	int indice = -1;

	if(list != NULL) {
		for(int i = 0; i<len;i++) {
			if(list[i].id == id) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}


int removePassenger(ePassenger list[], int id, int len)
{
	int ok = 0;
	int indice;
	int confirmacion;

	if(list != NULL) {

        indice = findPassengerById(list,id,len);

        if(indice == -1) {
            printf("ID de pasajero Incorrecta\n");
            system("pause");
        } else {
            printf("Esta seguro que desea darle de baja al usuario:\n");
            printPassenger(list[indice]);
            printf("Confirma baja?:\n");
            printf("1 - SI\n");
            printf("Cualquier tecla - NO\n");
            scanf("%d", &confirmacion);

            if(confirmacion == 1) {
                list[indice].isEmpty = 1;
                ok = 1;
            } else {
                printf("BAJA CANCELADA\n");
                system("pause");
            }
        }
	}
	return ok;
}




int printPassengers(ePassenger list[], int len)
{
	int ok = 0;

	if(list != NULL) {
		ok = 1;
		printf(" **** LISTADO PASAJEROS ****\n\n");
		printf(" ID  -  Apellido     -     Nombre       -      Precio   -   CodigoVuelo - TipoPasajero - EstadoVuelo\n");
		for(int i = 0;i<len;i++) {
			if(list[i].isEmpty == 0) {
				printPassenger(list[i]);
			}
		}
	}

	return ok;
}

int sortPassengers(ePassenger list[], int order, int len)
{
    int ok = 0;
    ePassenger auxPassenger;
    int estaOrdenado;

    if(list != NULL) {
       ok = 1;
       do {
        estaOrdenado = 1;
        len -= 1;
        for(int i = 0; i < len; i++) {
            if((order && strcmp(list[i].lastName,list[i+1].lastName) > 0)||
               (order && strcmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].typePassenger > list[i+1].typePassenger)||
               (!order && strcmp(list[i].lastName,list[i+1].lastName) < 0) ||
               (!order && strcmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].typePassenger < list[i+1].typePassenger)) {

                auxPassenger = list[i];
                list[i] = list[i+1];
                list[i+1]  = auxPassenger;

                estaOrdenado = 0;
                }
            }
        }while(!estaOrdenado);
    }
	return ok;
}

int sortPassengersByCode(ePassenger list[], int len, int order)
{
    int ok = 0;
    ePassenger auxPassenger;
    int estaOrdenado;

    if(list != NULL) {
       ok = 1;
       do {
        estaOrdenado = 1;
        len -= 1;
        for(int i = 0; i < len; i++) {


            if((order && strcmp(list[i].flyCode,list[i+1].flyCode) > 0)||
              (!order && strcmp(list[i].flyCode,list[i+1].flyCode) < 0)) {

                auxPassenger = list[i];
                list[i] = list[i+1];
                list[i+1]  = auxPassenger;

                estaOrdenado = 0;
                }
            }
        }while(!estaOrdenado);
    }
	return ok;
}


