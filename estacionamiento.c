#include <stdio.h>

#include "monedero.c"
#include "imprimir.c"
#include "usuario.c"

 #ifndef _ESTACIONAMIENTO_C
 #define _ESTACIONAMIENTO_C 1

// Recibe la cantidad a cobrar
void cobrar(int catidad, struct Usuario *u);

// Es un algoritmo avido que da cambio
void darCambio(int cobrar, int pagado, struct Usuario *u);

void cobrar(int cobrar, struct Usuario *u) {
    // Es la cantidad que el usuario ha ingresado
    int pagado = 0;
    // Es la moneda que va a ingresar el usuario
    int ingresar;

    while(cobrar > pagado) {
        // si el usuario no tiene para pagar encontara dinero en el auto
        if(&(*u).monedero == NULL) {
            printf("Te has quedando sin dinero...\n");
            printf("Pero encontraste $10 en el auto\n");

            push(&(*u).monedero, 10, &(*u).noMondedas);
        }

        imprimirCobrar(cobrar, pagado);
        printf("Tus monedas:");
        imprimirMonedero((*u).monedero, (*u).noMondedas);
        printf("\nMoneda a ingresar: ");
        scanf("%d", &ingresar);

        if(pop(&(*u).monedero, ingresar, &(*u).noMondedas)) {
            pagado += ingresar;
            system("clear");
        }
    } 

    darCambio(cobrar, pagado, u);
}

void darCambio(int cobrar, int pagado, struct Usuario *u) {
    // Guarda las denominaciones de las monedas
    int denominaciones[4] = { 10, 5, 2, 1 };
    // Guarda la cantidad de cambio
    int cambio[4] = { 0, 0, 0, 0 };
    int i, j, bandera, total;
    int suma = 0;
    
    // Calcular cuanto cambio se va a dar
    total = pagado - cobrar;

    if(total != 0) {
        //Lista para mostar el cambio devuelto
        struct Monedero *cambioLista = NULL;
        int noMonedasCambio = 0;


        for(i=0; i<4; i++) {
            bandera = 1;
            while(bandera) {
                if (suma + denominaciones[i] <= total){
                    suma += denominaciones[i];
                    cambio[i]++;
                }else{
                    bandera = 0;
                }
            }
        }

        // Dar cambio
        for(i=0; i<4; i++) {
            for(j=0; j<cambio[i]; j++) {
                // Se agrega a la lista de cambio
                push(&cambioLista, denominaciones[i], &noMonedasCambio);
                // Se agrega al monedero del usuario
                push(&(*u).monedero, denominaciones[i], &(*u).noMondedas);
            }
        }

        printf("\nTu cambio:\n");
        imprimirMonedero(cambioLista, noMonedasCambio);
        vaciarMonedero(&cambioLista, &noMonedasCambio);
    } else {
        printf("\nPagaste exacto.\n");
    }
}

#endif