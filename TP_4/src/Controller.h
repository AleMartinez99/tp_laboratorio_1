#include "Passenger.h"
#include "LinkedList.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger,int* id);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger) ;

ePassenger* controller_searchPassengerID(LinkedList* pArrayListPassenger,int id, int* index);

int controller_showPassenger(ePassenger* pPassenger);
int controller_IdSiguiente(LinkedList* pArrayListPassenger);

int controller_CompararId(void* a, void* b);
int controller_CompararNombre(void* a, void* b);
int controller_CompararApellido(void* a, void* b);
int controller_CompararPrecios(void* a, void* b);
int controller_CompararCodigoVuelo(void* a, void* b);
int controller_IdSiguiente(LinkedList* pArrayListPassenger);
