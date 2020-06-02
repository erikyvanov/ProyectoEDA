#include <stdio.h>

#include "monedero.c"
#include "imprimir.c"
#include "usuario.c"

 #ifndef _ESTACIONAMIENTO_C
 #define _ESTACIONAMIENTO_C 1

// Recibe la cantidad a cobrar
void cobrar(int catidad, struct Usuario *u);

void cobrar(int cantidad, struct Usuario *u) {
    // Es la cantidad que el usuario ha ingresado
    int pagado = 0;
    // Es la moneda que va a ingresar el usuario
    int ingresar;

    while(cantidad > pagado) {
        imprimirCobrar(cantidad, pagado);
        printf("Tus monedas:");
        imprimirMonedero((*u).monedero, (*u).noMondedas);
        printf("\nMoneda a ingresar: ");
        scanf("%d", &ingresar);

        if(pop(&(*u).monedero, ingresar, &(*u).noMondedas)) {
            pagado += ingresar;
            system("clear");
        }
    } 
}

#endif