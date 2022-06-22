#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayPassenger.h"
#include "dataWareHouse.h"
#include "myArrayPassenger.h"

char nombres[10][20] = {
    "Juan",
    "Alejandro",
    "Sofia",
    "Luis",
    "Mabel",
    "Facundo",
    "Julieta",
    "Fernando",
    "Lucia",
    "Miguel"
};

char apellidos[10][20] = {
    "Rodriguez",
    "Martinez",
    "Santero",
    "Zenobi",
    "Martinez",
    "Larroulette",
    "Lopez",
    "Fernandez",
    "Rodriguez",
    "Perez"
};

float precios[10] = {2500.45,4657,7853.50,3647.99,1000.65,4657.69,3215.90,3215,20000,18456.21};

char CodigoVuelo[10][7] = {
    "48FFQD",
    "MNI5GF",
    "YTB87Q",
    "ACB690",
    "8UZQ54",
    "NM00NN",
    "FG4W7Q",
    "QWERTY",
    "6FG4T7",
    "2DFS56"
};

int status[10] = {0,1,1,1,1,0,1,1,1,1};

int tipoPasajero[10] = {3,1,5,6,2,3,4,5,4,6};

int hardcodearPasajeros(ePassenger list[], int len, int cant, int* pId){

    int todoOk = 0;


    if(list != NULL && len > 0 && cant <= len && pId != NULL) {
        todoOk = 1;

        for(int i = searchFree(list,len); i < cant; i++) {
            (*pId)++;
            list[i].id= *pId;
            strcpy(list[i].name, nombres[i]);
            strcpy(list[i].lastName, apellidos[i]);
            list[i].price = precios[i];
            strcpy(list[i].flyCode, CodigoVuelo[i]);
            list[i].statusFlight = status[i];
            list[i].typePassenger = tipoPasajero[i];
            list[i].isEmpty = 0;
        }
    }

    return todoOk;
}
