#ifndef INFORMESYMENU_H_
#define INFORMESYMENU_H_



#endif /* INFORMESYMENU_H_ */
/// @brief Muestra el menu
///
/// @pre
/// @post
/// @param km Paso por valor los kilometros
/// @param precioAereoLinea Paso por valor el precio de AereoLinea
/// @param precioLatam Paso por valor el precio de Latam
/// @return Retorna la opcion seleccionada por el usuario
int menu(float km,float precioAereoLinea, float precioLatam);
/// @brief Muestra los resultados
///
/// @pre
/// @post
/// @param km Paso por valor los kilometros
/// @param precioAereolineas Paso por valor precio de alguna AereoLineas
/// @param precioLatam Paso por valor precio de alguna Latam
/// @param precioDebitoAereoL Paso variable por valor para INFORMAR el precio
/// @param precioCreditoAereoL Paso variable por valor para INFORMAR el precio
/// @param precioBTCAereoL Paso variable por valor para INFORMAR el precio
/// @param precioUnitarioAereoL  Paso variable por valor para INFORMAR el precio por kilometro
/// @param precioDebitoLatam Paso variable por valor para INFORMAR el precio
/// @param precioCreditoLatam Paso variable por valor para INFORMAR el precio
/// @param precioBTCLatam Paso variable por valor para INFORMAR el precio
/// @param precioUnitarioLatam Paso variable por valor para INFORMAR el precio por kilometro
/// @param diferenciaPrecio Paso variable por valor para INFORMAR el precio
void InformarResultados(float km, float precioAereolineas, float precioLatam,float precioDebitoAereoL,float precioCreditoAereoL,float precioBTCAereoL,float precioUnitarioAereoL,float precioDebitoLatam,float precioCreditoLatam,float precioBTCLatam,float precioUnitarioLatam,float diferenciaPrecio);
/// @brief Resta dos numeros flotantes
///
/// @pre
/// @post
/// @param precio1
/// @param precio2
/// @return retorna la resta del primer parametro, menos el segundo parametro
float diferenciaDePrecio(float precio1, float precio2);
