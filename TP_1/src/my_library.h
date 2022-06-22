#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#endif /* MY_LIBRARY_H_ */

/// @brief Solicita un numero flotante al usuario
///
/// @pre
/// @post
/// @param pResultado Variable tipo puntero, que se le copia el numero ya validado
/// @param mensaje Mensaje que se le muestra al usuario
/// @param mensajeError Mensaje que se le muestra al usuario en caso de que ingreso un numero invalido
/// @param minimo Rango MINIMO para validar el numero ingresado
/// @param maximo Rango MAXIMO para validar el numero ingresado
/// @return retorna 1 se le paso un numero correcto, y 0 para numero invalido
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo);
/// @brief Solicita un numero flotante al usuario
///
/// @pre
/// @post
/// @param pResultado Variable tipo puntero, que se le copia el numero ya validado
/// @param mensaje Mensaje que se le muestra al usuario
/// @param mensajeError Mensaje que se le muestra al usuario en caso de que ingreso un numero invalido
/// @param minimo Rango MINIMO para validar el numero ingresado
/// @return retorna 1 se le paso un numero correcto, y 0 para numero invalido
int utn_getNumeroFlotanteSoloMinimo(float* pResultado,char* mensaje,char* mensajeError,float minimo);
