#include <stdio.h>
#include <stdlib.h>

#include "imprimir.c"

 #ifndef _MONEDERO_C
 #define _MONEDERO_C 1

// Monedero es una lista
struct Monedero {
	int moneda;
    
	struct Monedero *ptrSiguiente;
};

void push(struct Monedero **ptrS, int moneda, int *noMonedas);
// Regresa un 1 si se elimino la moneda y un 0 si no se elimino
int pop(struct Monedero **ptrS, int moneda, int *noMonedas);
void imprimirMonedero(struct Monedero *ptrS, int noMonedas);
void vaciarMonedero(struct Monedero **ptrS, int *noMonedas);

void push(struct Monedero **ptrS, int moneda, int *noMonedas) {
    struct Monedero *ptrActual;
    struct Monedero *ptrAnterior;
    struct Monedero *ptrNuevo;

    ptrNuevo = (struct Monedero *) malloc( sizeof(struct Monedero) );

    if (ptrNuevo != NULL){
        ptrNuevo->moneda = moneda;

        ptrAnterior = NULL;
        ptrActual = *ptrS;
        
        while (ptrActual != NULL && moneda > ptrActual->moneda){
            ptrAnterior = ptrActual;
            ptrActual = ptrActual->ptrSiguiente;
        }
        if(ptrAnterior == NULL){
            ptrNuevo->ptrSiguiente = *ptrS;
            *ptrS = ptrNuevo;
        }else{
            ptrAnterior->ptrSiguiente = ptrNuevo;
            ptrNuevo->ptrSiguiente = ptrActual;
        }
        // Se agrego una moneda
        *noMonedas = *noMonedas + 1;
    }else{
        printf("No hay espacio en memoria\n");
    }
}

int pop(struct Monedero **ptrS, int moneda, int *noMonedas) {
    struct Monedero *ptrActual;
    struct Monedero *ptrAnterior;
    struct Monedero *ptrTemp;

    // Caso para el primer elemento
    if (moneda == (*ptrS)->moneda) {
        ptrTemp = *ptrS;
        *ptrS = (*ptrS)->ptrSiguiente;
        free(ptrTemp);

        // Se quito una moneda
        *noMonedas = *noMonedas - 1;
        return 1;
    }

    ptrAnterior = *ptrS;
    ptrActual = (*ptrS)->ptrSiguiente;
    
    while (ptrActual != NULL && ptrActual->moneda != moneda) {
        ptrAnterior = ptrActual;
        ptrActual = ptrActual->ptrSiguiente;
    }
    
    if (ptrActual != NULL){
        ptrTemp = ptrActual;
        ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
        free(ptrTemp);

        // Se quito una moneda
        *noMonedas = *noMonedas - 1;
        return 1;
    }

    // Si la moneda no existe
    printf("\nNo tienes esa moneda \n");
    return 0;
}

void imprimirMonedero(struct Monedero *ptrS, int noMonedas) {
    printf("\n");
    if(ptrS == NULL) {
        printf("\nNo tienes monedas\n");
    } else {
        int renglon, j;
        struct Monedero *f = ptrS;

        for(renglon=1; renglon<=3; renglon++) {
            // Recorre la lista
            if(renglon == 2) {
                for(j=0; j<noMonedas; j++) {
                    imprimirMoneda(ptrS->moneda, renglon);
                    ptrS = ptrS->ptrSiguiente;
                }
            } else {
                for(j=0; j<noMonedas; j++) {
                    imprimirMoneda(ptrS->moneda, renglon);
                    ptrS = ptrS->ptrSiguiente;
                }
            }
            printf("\n");
            ptrS = f;
        }
    }
}

void vaciarMonedero(struct Monedero **ptrS, int *noMonedas) {
    struct Monedero *actual;

    while(*ptrS != NULL) {
        actual = *ptrS;
        *ptrS = (*ptrS)->ptrSiguiente;

        free(actual);
    }

    *ptrS = NULL;
    *noMonedas = 0;
}

#endif