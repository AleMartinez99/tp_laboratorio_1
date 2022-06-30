#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "miBiblioteca.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main() {

	setbuf(stdout, NULL);
    int seguir = 1;

    int id = 1001;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do {
        switch(menu()) {
            case 1:
                controller_loadFromText("data",listaPasajeros);
                break;
            case 2:
            	controller_loadFromBinary("data.bin",listaPasajeros);
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros, &id);
				break;
            case 4:
            	if(ll_len(listaPasajeros) > 0){
            		controller_editPassenger(listaPasajeros);
                } else {
            		printf("Primero ingrese un empleado\n");
            		system("pause");
            	}
            	break;
            case 5:
            	if(ll_len(listaPasajeros) > 0){
            		controller_removePassenger(listaPasajeros);
            	} else {
            		printf("Primero ingrese un empleado\n");
            		system("pause");
            	}
				break;
            case 6:
            	if(!controller_ListPassenger(listaPasajeros)) {
            		printf("No hay pasajeros que mostrar\n");
            		system("pause");
            	}
				break;
            case 7:
            	if(ll_len(listaPasajeros) > 0) {
            	controller_sortPassenger(listaPasajeros);
            	} else {
            		printf("Primero ingrese un empleado\n");
            		system("pause");
            	}
				break;
            case 8:
            	controller_saveAsText("data",listaPasajeros);
				break;
			case 9:
				controller_saveAsBinary("data.bin",listaPasajeros);
				break;
			case 10:
				if(ll_len(listaPasajeros) > 0) {
					controller_InformePassenger(listaPasajeros);
            	} else {
            		printf("Primero ingrese un empleado\n");
            		system("pause");
            	}
				break;
			case 11:
				seguir = 0;
				printf("SALIO CON EXITO\n");
				break;
			default:
				printf("OPCION INVALIDA\n");
				system("pause");
        }
    } while(seguir);

    system("pause");
    return 0;
}
