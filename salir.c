#include <stdio.h>

#include "estacionamiento.c"
#include "imprimir.c"

void irA(struct Usuario *u);
// Calcula cuanto se va a pagar de estacimiento
int calcularPagoEstacionamiento(int horas, int tipoAuto);

void irA(struct Usuario *u) {
    if((*u).tipoAuto == 0) {
        system("clear");
        printf("\nTienes que seleccionar un auto\n");
    } else {
        int opcion = 0;

        // La opcion 5 es regresar al menu principal
        while(opcion != 5) {
            imprimirMenuIrA();
            scanf("%d", &opcion);

            if(opcion > 0 && opcion < 5) {
                if(opcion == 4) {
                    imprimirPreciosEstacionamiento();
                } else {
                    printf("Has realizado tu actividad\n");
                    printf("Ahora toca pagar el estacionamiento\n");

                    cobrar(calcularPagoEstacionamiento(opcion, (*u).tipoAuto), u);
                    }
            }
        }
    }
}

int calcularPagoEstacionamiento(int horas, int tipoAuto) {
    return (tipoAuto*2*horas);
}