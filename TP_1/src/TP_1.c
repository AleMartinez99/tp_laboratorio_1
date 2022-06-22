#include <stdio.h>
#include <stdlib.h>
#include "my_library.h"
#include "calculos.h"
#include "informesYMenu.h"

#define BTC 4606954.55

int main(void) {

	setbuf(stdout, NULL);

	float kilometros = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	float precioDebitoAereoL;
	float precioCreditoAereoL;
	float precioBTCAereoL;
	float precioUnitarioAereoL;

	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBTCLatam;
	float precioUnitarioLatam;

	float diferenciaPrecio;

	int seguir = 1;
	int flagPrecios = 1;
	int flagCase4 = 1;

	do {

		switch(menu(kilometros,precioAerolineas,precioLatam)){
			case 1:
				utn_getNumeroFlotante(&kilometros,"Ingrese kilometros: ","ERROR...Los kilometros tiene que ir de 1 a 46000.",1,46000);
				break;
			case 2:
				printf("Ingresar precio de vuelos.\n");
				utn_getNumeroFlotanteSoloMinimo(&precioAerolineas,"Ingrese precio vuelo Aereolineas: ","ERROR...El precio tiene que ser mayor a 0.",0.1);
				utn_getNumeroFlotanteSoloMinimo(&precioLatam,"Ingrese precio vuelo Latam: ","ERROR...El precio tiene que ser mayor a 0.",0.1);
				flagPrecios = 0;
				break;
			case 3:
				if(!kilometros || flagPrecios) {
					printf("Primero debe ingresar kilometros y precios para calcular los costos\n");
					system("pause");
				}else {
					if(calcularCostos(kilometros,precioAerolineas,BTC,&precioDebitoAereoL,&precioCreditoAereoL,&precioBTCAereoL,&precioUnitarioAereoL)
							&& calcularCostos(kilometros, precioLatam,BTC,&precioDebitoLatam ,&precioCreditoLatam ,&precioBTCLatam ,&precioUnitarioLatam)) {
						diferenciaPrecio = diferenciaDePrecio(precioLatam,precioAerolineas);
						printf("Costos calculados con exito\n");
						flagCase4 = 0;
					} else {
						printf("No se pudieron calcular los costos\n");
					}
				}
				break;
			case 4:
				if(!flagCase4){
					InformarResultados(kilometros,precioAerolineas,precioLatam,precioDebitoAereoL,precioCreditoAereoL,precioBTCAereoL,
									precioUnitarioAereoL,precioDebitoLatam,precioCreditoLatam,precioBTCLatam,precioUnitarioLatam,diferenciaPrecio);
				} else {
					printf("Primero debe calcular los costos con la opcion 3\n");
					system("pause");
				}
				break;
			case 5:
				calcularCostos(7090,162965,BTC,&precioDebitoAereoL,&precioCreditoAereoL,&precioBTCAereoL,&precioUnitarioAereoL);
				calcularCostos(7090, 159339,BTC,&precioDebitoLatam ,&precioCreditoLatam ,&precioBTCLatam ,&precioUnitarioLatam);
				diferenciaPrecio = diferenciaDePrecio(162965 , 159339);
				InformarResultados(7090,162965,159339,precioDebitoAereoL,precioCreditoAereoL,precioBTCAereoL,
								precioUnitarioAereoL,precioDebitoLatam,precioCreditoLatam,precioBTCLatam,precioUnitarioLatam,diferenciaPrecio);
				break;
			case 6:
				printf("Ha salido con exito\n");
				seguir = 0;
				break;
			default:
				printf("OPCION INVALIDA\n");
		}
	}while(seguir);
	system("pause");
	return EXIT_SUCCESS;
}







