#include <stdio.h>
#include <stdlib.h>
#include "my_library.h"
#include "arrayPassenger.h"
#include "myArrayPassenger.h"
#include "dataWareHouse.h"

#define LEN 2000

int main(void) {

    setbuf(stdout, NULL);

	ePassenger list[LEN];
	int seguir = 1;
	int nextId = 19999;
	char name[21];
	char lastName[21];
	float price;
	char flyCode[7];
	int typePassenger;
	int statusFlight;

	int pedirId;

	int cantidadHardCodeo;

	initPassengers(list,LEN);

	do {
		switch(menu()) {
			case 1:
				if(searchFree(list,LEN) != -1) {
					loadPassenger(&nextId,name,lastName,&price,flyCode,&typePassenger,&statusFlight);
					addPassenger(list,nextId,name,lastName,price,flyCode,typePassenger,statusFlight,LEN);
				} else {
					printf("La lista esta llena\n");
					system("pause");
				}
				break;
			case 2:
				 if(searchFull(list,LEN)) {
                    if(modifyPassenger(list,LEN)) {
                        printf("MODIFICACION realizada con exito\n");
                    }
                } else {
                    printf("No hay pasajeros para modificar\n");
                    system("pause");
                }
				break;
			case 3:
				 if(searchFull(list,LEN)) {
                    printf("\n **** BAJA DE PASAJERO ****\n\n");
                    printPassengers(list,LEN);
                    pedirId = miIngresarEntero("Ingrese ID del usuario a dar de baja: ");
                    if(removePassenger(list,pedirId,LEN)) {
                        printf("BAJA realizada con exito\n");
                    }
                } else {
                    printf("No hay pasajeros para dar de baja\n");
                    system("pause");
                }
				break;
			case 4:
			    if(searchFull(list,LEN)) {
                   menuInformes(list,LEN);
                   system("pause");
                } else {
                    printf("No hay pasajeros para mostrar\n");
                    system("pause");
                }
                break;
			case 5:
				utnGetNumero(&cantidadHardCodeo,"Ingrese cantidad de personas a Hardcodear: ","ERROR... Ingrese de 1 a 10 personas: ",1,10);
				if(hardcodearPasajeros(list,LEN,cantidadHardCodeo, &nextId)) {
					printf("Se realizo la carga forzada con exito\n");
				} else {
					printf("No se pudo realizar la carga forzada\n");
				}
				break;
			case 6:
				printf("Salir");
				seguir = 0;
				break;
			default:
				printf("opcion invalida\n");
				system("pause");
		}
	}while(seguir);

	return EXIT_SUCCESS;
}
