#include "myArrayPassenger.h"
#include "my_library.h"

int menu() {

    int opcion;

    printf(" **** PASAJEROS ****\n");
    printf("1- Alta pasajero\n");
    printf("2- Modificar pasajero\n");
    printf("3- Baja pasajero\n");
    printf("4- Informar pasajeros\n");
    printf("5- HardCodear pasajeros\n");
    // Agrego opcion SALIR
    printf("6- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void menuInformes(ePassenger list[],int len) {

    int opcionInforme;
    int criterioOrdenamiento;  // 1 - Ascendente, 0 - Descendente.

    printf("Que desea informar:\n");
    printf("1- Listado ordenado por apellido y tipo de pasajero\n");
    printf("2- Total y primedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio\n");
    printf("3- Listado ordenado por codigo de vuelo y estados de vuelos 'ACTIVOS'\n");
    opcionInforme = miIngresarEntero("Ingrese opcion: ");

    switch(opcionInforme) {
        case 1:
            printf("De que manera desea ordenar?:\n");
            printf("0 - Descendente\n");
            printf("1 - Ascendente\n");
            utnGetNumero(&criterioOrdenamiento,"","Error... 0 - Descendente y 1 - Ascendente: ",0,1);
            sortPassengers(list,criterioOrdenamiento,len);
            printPassengers(list,len);
            break;
        case 2:
            informarPrecios(list,len);
            system("pause");
            break;
        case 3:
            printf("De que manera desea ordenar?:\n");
            printf("0 - Descendente\n");
            printf("1 - Ascendente\n");
            utnGetNumero(&criterioOrdenamiento,"","Error... 0 - Descendente y 1 - Ascendente: ",0,1);
            sortPassengersByCode(list,len,criterioOrdenamiento);
            printPassengersActive(list,len);
            break;
        default:
        printf("Opcion incorrecta.\nVuelve al menu\n");
        system("pause");
    }
}

int loadPassenger(int* pId, char name[], char lastName[],float* pPrice, char flyCode[],int* pTypePassenger,int* pStatusFlight) {

	int ok = 0;

	if(pId != NULL && name != NULL && lastName != NULL && pPrice != NULL && flyCode != NULL && pTypePassenger != NULL) {

		printf("  **** ALTA PASAJERO ****\n");
		(*pId)++;

		utnGetCadenaSoloCaracteres(name,"Ingrese nombre: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
        miCorregirUnaCadena(name);

        utnGetCadenaSoloCaracteres(lastName,"Ingrese apellido: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
        miCorregirUnaCadena(lastName);

		utnGetNumeroFlotanteSoloMinimo(pPrice,"Ingrese precio:","Error...Ingrese precio mayor a 0",0.1);

		printf("Ingrese Codigo de vuelo, tiene que tener 6 digitos alfanumericos,(Ejemplo: A2F6J8):");
		fflush(stdin);
		gets(flyCode);

		while(miValidarLargoCadena(flyCode) < 6 || miValidarLargoCadena(flyCode) > 6) {
			printf("Error... Ingrese un codigo de vuelo de 6 caracteres:");
			fflush(stdin);
			gets(flyCode);
		}

		flyCode = strupr(flyCode);

		utnGetNumero(pTypePassenger,"Ingrese tipo de pasajero: ","Error... Ingrese numero del 1 al 6: ",1,6);
		utnGetNumero(pStatusFlight,"Ingrese estado de vuelo:\n1 - ACTIVO\n0 - CANCELADO\n- ","Error... 1 para ACTIVO, 0 para CANCELADO: ",0,1);

		ok = 1;
	}

	return ok;
}


int searchFree(ePassenger list[], int len) {

	int indice = -1;

	if(list != NULL) {
		for(int i = 0;i<len;i++) {
			if(list[i].isEmpty) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int searchFull(ePassenger lista[], int tam) {

    int ok = 0;

    if(lista != NULL && tam > 0) {
        ok = 0;
        for(int i = 0;i < tam;i++) {
            if(!lista[i].isEmpty) {
                ok = 1;
            }
        }
    }
    return ok;
}

int modifyPassenger(ePassenger list[], int len) {

    int ok = 1;
    int id;
    int indice;
    int opcion;
    ePassenger auxPassenger;

    if(list != NULL) {
        printf("  **** MODIFICACION DE PASAJERO ****\n");
        printf("Que pasajero desea modificar:\n");
        printPassengers(list,len);
        printf("\nIngrese ID del usuario a modificar: ");
        scanf("%d",&id);

        indice = findPassengerById(list,id,len);

        if(indice == -1) {
            printf("ID de pasajero Incorrecta\n");
            ok = 0;
            system("pause");
        } else {
            printf("Que desea modificar del pasajero:\n");
            printPassenger(list[indice]);
            printf("1- Nombre\n");
            printf("2- Apellido\n");
            printf("3- Precio\n");
            printf("4- Tipo de Pasajero\n");
            printf("5- Codigo de Vuelo\n");
            scanf("%d", &opcion);
            switch(opcion) {
                case 1:

                	utnGetCadenaSoloCaracteres(auxPassenger.name,"Ingrese nuevo nombre: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
					miCorregirUnaCadena(auxPassenger.name);
					strcpy(list[indice].name,auxPassenger.name);

                    break;
                case 2:
                	utnGetCadenaSoloCaracteres(auxPassenger.lastName,"Ingrese nuevo apellido: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
					miCorregirUnaCadena(auxPassenger.lastName);
					strcpy(list[indice].lastName,auxPassenger.lastName);
                    break;
                case 3:
                    utnGetNumeroFlotanteSoloMinimo(&list[indice].price,"Ingrese precio:","Error...Ingrese precio mayor a 0",1);
                    break;
                case 4:
                    utnGetNumero(&list[indice].typePassenger,"Ingrese tipo de pasajero","Error... Ingrese numero del 1 al 6",1,6);
                    break;
                case 5:
                    printf("Ingrese Codigo de vuelo, tiene que tener 6 digitos alfanumericos,(Ejemplo: A2F68): ");
                    fflush(stdin);
                    fgets(list[indice].flyCode,6,stdin);
                    fflush(stdin); // limpio el buffer por si el usuario se pasa en caracteres.
                    break;
                default:
                    printf("Opcion incorrecta\nReedirigido al menu principal\n");
                    system("pause");
                    ok = 0;
            }

        }
    }
    return ok;
}

void printPassenger(ePassenger aPassenger) {

    char descripcion[20];

    if(aPassenger.statusFlight == 1) {
        strcpy(descripcion,"ACTIVO");
    } else {
        strcpy(descripcion,"CANCELADO");
    }

    printf("%d   %-19s%-19s %-10.2f     %s           %d         %-10s\n",
           aPassenger.id,
           aPassenger.lastName,
           aPassenger.name,
           aPassenger.price,
           aPassenger.flyCode,
           aPassenger.typePassenger,
           descripcion
           );
}

int informarPrecios(ePassenger list[], int len) {
    int ok = 0;

    float totalPrecios = 0;
    float promedioPrecios;
    int contador = 0;
    int contadorSalariosMayorDelPromedio = 0;

    if(list != NULL) {
        ok = 1;
        for(int i = 0;i<len;i++) {
            if(list[i].isEmpty == 0) {
                contador++;
                totalPrecios += list[i].price;
            }
        }
        promedioPrecios = totalPrecios / contador;

        printf("Total precio de los pasajes: %.2f\n",totalPrecios);
        printf("Promedio del precio: %.2f\n", promedioPrecios);

        for(int i = 0;i<len;i++) {
            if(list[i].isEmpty == 0 && list[i].price > promedioPrecios) {
                contadorSalariosMayorDelPromedio++;
            }
        }
        if(!contadorSalariosMayorDelPromedio) {
            printf("Ningun pasajero supera el precio promedio\n");
        } else {
            printf("Cantidad de pasajeros que superan el precio promedio: %d\n", contadorSalariosMayorDelPromedio);
        }

    }
    return ok;
}

int printPassengersActive(ePassenger list[], int len)
{
	int ok = 0;

	if(list != NULL) {
		ok = 1;
		printf("                     **** LISTADO PASAJEROS ACTIVOS ****\n\n");
		printf(" ID  -  Apellido     -     Nombre       -      Precio   -   CodigoVuelo - TipoPasajero - EstadoVuelo\n");
		for(int i = 0;i<len;i++) {
			if(list[i].isEmpty == 0 && list[i].statusFlight == 1) {
				printPassenger(list[i]);
			}
		}
	}

	return ok;
}
