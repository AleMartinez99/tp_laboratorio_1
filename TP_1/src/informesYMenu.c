#include <stdio.h>
#include <stdlib.h>
#include "informesYMenu.h"

int menu(float km,float precioAereoLinea, float precioLatam) {

	int opcion;

	printf("**** AGENCIA DE VUELO ****\n");
	printf("1 - Ingresar Kilometros: (km = %.2f)\n", km);
	printf("2 - Ingresar Precio de Vuelos: (Aereolineas = %.2f, Latam = %.2f)\n",precioAereoLinea,precioLatam);
	printf("3 - Calcular todos los costos\n");
	printf("4 - Informar Resultados\n");
	printf("5 - Carga forzada de datos\n");
	printf("6 - SALIR\n");
	printf("Ingrese Opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

float diferenciaDePrecio(float precio1, float precio2) {
	return precio1 - precio2;
}

void InformarResultados(float km, float precioAereolineas, float precioLatam,float precioDebitoAereoL,float precioCreditoAereoL,float precioBTCAereoL,float precioUnitarioAereoL,float precioDebitoLatam,float precioCreditoLatam,float precioBTCLatam,float precioUnitarioLatam,float diferenciaPrecio) {

	printf("KMs Ingresados: %.2f km\n\n",km);

	printf("Precio Aereolineas: $%.2f\n",precioAereolineas);
	printf("a) Precio con tarjeta de debito: $%.2f\n",precioDebitoAereoL);
	printf("b) Precio con tarjeta de credito: $%.2f\n",precioCreditoAereoL);
	printf("c) Precio pagando con bitcoin: %.8f BTC\n",precioBTCAereoL);
	printf("d) Mostrar precio unitario: $%.3f\n\n",precioUnitarioAereoL);

	printf("Precio Latam: $%.2f\n",precioLatam);
	printf("a) Precio con tarjeta de debito: $%.2f\n",precioDebitoLatam);
	printf("b) Precio con tarjeta de credito: $%.2f\n",precioCreditoLatam);
	printf("c) Precio pagando con bitcoin: %.8f BTC\n",precioBTCLatam);
	printf("d) Mostrar precio unitario: $%.3f\n\n",precioUnitarioLatam);

	printf("La diferencia de precio es : $%.2f (precio LATAM - precio AEREOLINEAS)\n\n",diferenciaPrecio);
}
