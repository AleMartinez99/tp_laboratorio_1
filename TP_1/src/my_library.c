#include <stdio.h>
#include <stdlib.h>
#include "my_library.h"

int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo) {

    int retorno = 0;
    float auxFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo) {

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%f", &auxFloat);

            if(auxFloat >= minimo && auxFloat <= maximo) {
                *pResultado = auxFloat;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);

            }
        }while(retorno != 1);
    }
    return retorno;
}

int utn_getNumeroFlotanteSoloMinimo(float* pResultado,char* mensaje,char* mensajeError,float minimo) {

    int retorno = 0;
    float auxFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL) {

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%f", &auxFloat);

            if(auxFloat >= minimo ) {
                *pResultado = auxFloat;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);

            }
        }while(retorno != 1);
    }
    return retorno;
}


