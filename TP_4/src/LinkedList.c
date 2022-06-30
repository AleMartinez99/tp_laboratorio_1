#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){

	LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));

	if(this != NULL) {
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){
	int retorno = -1;

	if(this != NULL) {
		retorno = this->size;
	}
	return retorno;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
Node* getNode(LinkedList* this, int nodeIndex){
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){

		pNode = this->pFirstNode; /// ACA pNode tiene el puntero del NODO 0

		for(int i = 0;i<nodeIndex;i++){
			pNode = pNode->pNextNode; /// ACA en pNode ya tnego guardado el nodo, y lo voy pasando de a uno a travez de las direcciones de memoria.
			// pNode = pNode->pNextNode->pNextNode->pNextNode->pNextNode;
		}
	}
	return pNode;
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int addNode(LinkedList* this, int nodeIndex,void* pElement) {
	int retorno = -1;
	Node* pNuevoNodo = NULL;
	Node* pAuxNodo = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){

		pNuevoNodo = (Node*) malloc(sizeof(Node));

		if(pNuevoNodo != NULL) {

			pNuevoNodo->pNextNode = NULL;

			if(nodeIndex == 0) {

				pNuevoNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = pNuevoNodo;
				pNuevoNodo->pElement = pElement;
				this->size++;
				retorno = 0;

			} else {

				pAuxNodo = getNode(this,nodeIndex - 1);

				if(pAuxNodo != NULL) {

					pNuevoNodo->pNextNode = pAuxNodo->pNextNode;
					pAuxNodo->pNextNode = pNuevoNodo;

					pNuevoNodo->pElement = pElement;
					this->size++;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief  Agrega un elemento al final de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){

	int retorno = -1;

	if(this != NULL) {
		retorno = addNode(this,ll_len(this),pElement);
	}
	return retorno;
}

/** \brief Agrega un elemento a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) {

	void* returnAux = NULL;
	Node* pNodo = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)) {
		pNodo = getNode(this,index);
		if(pNodo != NULL) {
			returnAux = pNodo->pElement;
		}
	}
	return returnAux;
}

/** \brief MODIFICA un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement) {
	int returnAux = -1;
	Node* pNodo = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)) {

		pNodo = getNode(this,index);

		if(pNodo != NULL) {

			pNodo->pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) {

	int retorno = -1;
	int len = ll_len(this);
	Node* pAuxNodo = NULL; // NODO ANTERIOR
	Node* pAuxNodoAnterior = NULL;

	if(this != NULL && index >= 0 && index < len) {

		pAuxNodo = getNode(this,index);

		if(pAuxNodo != NULL) {
			if(index == 0) {

				this->pFirstNode = pAuxNodo->pNextNode;

			} else {

				pAuxNodoAnterior = getNode(this,index - 1);

				if(pAuxNodoAnterior != NULL) {

					pAuxNodoAnterior->pNextNode = pAuxNodo->pNextNode;
				}
			}
			this->size--;
			free(pAuxNodo);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this) {

	int retorno = -1;
	int len = ll_len(this);

	if(this != NULL && len > 0) {
		for(int i = 0;i<len;i++) {

			ll_remove(this,i);
		}

		/*
		 while(!len) {
		 	 ll_remove(this,0);
		 }
		 */
		retorno = 0;
	}
	return retorno;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this){

	 int retorno = -1;

	if (this != NULL && !ll_clear(this)) {
		free(this);
		retorno = 0;
	}

	return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement) {

	int retorno = -1;
	int len = ll_len(this);
	Node* auxNode = NULL;

	if(this != NULL) {
		for(int i = 0;i<len;i++) {

			auxNode = getNode(this,i);

			if(auxNode->pElement == pElement) {

				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this){
	int retorno = -1;

	if(this != NULL){
		if(ll_len(this) > 0) {
			retorno = 0;
		} else {
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement){

	int retorno = -1;

	if(this != NULL && index >= 0 && index <= ll_len(this)) {

		retorno = addNode(this,index,pElement);
	}
	return retorno;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index){

	void* retorno = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)) {

		retorno = ll_get(this,index);

		ll_remove(this,index);
	}
	return retorno;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){

	int retorno = - 1;

	if(this != NULL) {

		if(ll_indexOf(this,pElement) != -1) {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2){

	int retorno = -1;
	int len;
	void* pElement = NULL;

	if(this != NULL && this2 != NULL) {

		len = ll_len(this2);
		retorno = 1;
		for(int i = 0;i<len;i++) {

			pElement = ll_get(this2,i);

			if(!ll_contains(this2,pElement)) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to) {

	LinkedList* subList = NULL;
	void* auxElement = NULL;

	if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this)) {

		subList = ll_newLinkedList();

		if(subList != NULL) {
			// si queiro de 1 a 4 pongo from 1 y to 5
			for(int i = from;i<to;i++) {

				auxElement = ll_get(this,i);

				ll_add(subList,auxElement);
			}
		}
	}
	return subList;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) {

	LinkedList* clone = NULL;

	if(this != NULL) {
		clone = ll_subList(this,0,ll_len(this));
	}
	return clone;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
	int retorno = -1;
	int estaOrdenado;
	int len;
	void* auxElement = NULL;
	void* auxElement2 = NULL;
	//ordena elementos
	/// pFunc es el criterio por el que va a ordenar
	/// Retorna si corresponde o no corresponde ordenar
	/// pFunc se toma como un if

	///funcion parametros - retorna <0 (mayor a cero) si el primero es mayor
	/// 0 si son iguales
	/// y >0 (menor a cero) si el segundo es mayor

	if(this != NULL && (order == 0 || order == 1) && pFunc != NULL) {
		len = ll_len(this);

		do {
			estaOrdenado = 1;
			len--;

			for(int i = 0;i<len;i++) {
				auxElement = ll_get(this,i); ///obtengo una direccion de memoria
				auxElement2 = ll_get(this,i+1); ///obtengo otra direccion de memoria

				if((order == 1 && pFunc(auxElement,auxElement2) > 0) ||
				  (order == 0 && pFunc(auxElement,auxElement2) < 0)) {
					ll_set(this,i,auxElement2); /// le pasa el elemento que quiero que ponga en una posicion determinada
					ll_set(this,i+1,auxElement);
					estaOrdenado = 0;

					/*
					 aux = ll_get(this,i);
					 ll_set(this,i,ll_get(this,i+1));
					 ll_set(this,i+1,aux);

					 */
				}
			}
		}while(estaOrdenado == 0);
		retorno = 0;
	}
		return retorno;
}

///////////////////////////////////////////////////////////////////////////////////////////////

int ll_Informe(LinkedList* this, int (*pFunc)(void*)){
	int retorno = -1;
	int len;
	void* auxElement = NULL;

	if(this != NULL &&  pFunc != NULL) {
		len = ll_len(this);
		for(int i = 0;i<len;i++) {
			auxElement = ll_get(this,i);
			if(pFunc(auxElement)) {
				controller_showPassenger(auxElement);
			}
		}

		retorno = 0;
	}
		return retorno;
}


int ll_count(LinkedList* this, int (*pFunc)(void*)) {

	int acumulador = -1;
	int len;
	int retornoFuncion;
	void* auxElement = NULL;

		if(this != NULL &&  pFunc != NULL) {

			acumulador = 0;
			len = ll_len(this);

			for(int i = 0;i<len;i++) {

				auxElement = ll_get(this,i);
				retornoFuncion = pFunc(auxElement);

				if(retornoFuncion != -1) {

					acumulador += retornoFuncion;
				}
			}

		}
	return acumulador;
}


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* element)) {

	LinkedList* filterList = NULL;
	void* auxElement = NULL;
	int len;

	if(this != NULL && pFunc != NULL) {

		filterList = ll_newLinkedList();

		if(filterList != NULL) {

			len = ll_len(this);

			for(int i = 0;i<len;i++) {

				auxElement = ll_get(this,i);

				if(pFunc(auxElement)) {

					ll_add(filterList, auxElement);
				}
			}
		}
	}
	return filterList;
}



LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*)) {

	void* auxElement = NULL;
	int len;

	if(this != NULL && pFunc != NULL ) {

		len = ll_len(this);

		for(int i = 0;i<len;i++) {

			auxElement = ll_get(this,i);

			if(auxElement != NULL) {
				pFunc(auxElement);
			}
		}
	}
	return this;
}
