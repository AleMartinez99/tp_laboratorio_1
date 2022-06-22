#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "my_library.h"

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct {

	int id;
	char name[19];
	char lastName[19];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

} ePassenger;

#endif /* ARRAYPASSENGER_H_ */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int initPassengers(ePassenger list[], int len);

/** \brief add in a existing list of passengers the values received as parameters
 * in the first empty position
 * \param list passenger*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param price float
 * \param flycode[] char
 * \param typePassenger int
 * \return int Return (0) if Error [Invalid length or NULL pointer or without
 free space] - (1) if Ok
*/
int addPassenger(ePassenger list[], int id, char name[], char lastName[], float price,  char flyCode[],int typePassenger,int statusFlight, int len);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(ePassenger list[], int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (0) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (1) if Ok
*
*/
int removePassenger(ePassenger list[], int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int sortPassengers(ePassenger list[], int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengers(ePassenger list[], int len);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int sortPassengersByCode(ePassenger list[], int order, int len);

