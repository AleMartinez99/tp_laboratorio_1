#ifndef CALCULOS_H_
#define CALCULOS_H_


#endif /* CALCULOS_H_ */

/// @brief Permite calcular todos los costos
///
/// @pre
/// @post
/// @param km Paso por valor los kilometros
/// @param precioPasaje Paso por valor precio de alguna de las aereolineas
/// @param btc Paso por valor el precio de BTC en pesos
/// @param precioDebito Paso variable por referencia para aplicarle descuento
/// @param precioCredito Paso variable por referencia para aplicarle aumento
/// @param precioBTC Paso variable por referencia para aplicarle el precio pasado a btc
/// @param precioUnitario Paso variable por referencia para aplicarle el precio por kilometro
/// @return Retorna 1 si pudo hacer los calculos, 0 si no lo logro
int calcularCostos(float km, float precioPasaje,float btc, float* precioDebito,float* precioCredito,float* precioBTC,float* precioUnitario);
