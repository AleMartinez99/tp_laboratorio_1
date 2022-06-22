#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int calcularCostos(float km, float precioPasaje,float btc, float* precioDebito,float* precioCredito,float* precioBTC,float* precioUnitario) {
	int ok = 0;

	if(precioDebito != NULL && precioCredito != NULL &&  precioBTC!= NULL && precioUnitario != NULL) {

		*precioDebito = precioPasaje / 1.10;
		*precioCredito = precioPasaje * 1.25;
		*precioBTC = precioPasaje / btc;
		*precioUnitario = precioPasaje / km;
		ok = 1;
	}
	return ok;
}

