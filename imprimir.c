#include <stdio.h>

 #ifndef _IMPRIMIR_C
 #define _IMPRIMIR_C 1

/*Prototipos*/

void imprimirTitulo(int tipoAuto);
void imprimirInstrucciones();

void imprimirMoneda(int moneda, int renglon);

// Imprime un auto dependiendo del tipo
void imprimirAuto(int tipo);
void imprimirNombreAuto(int tipo);

void imprimirCarro();
void imprimirCamioneta();
void imprimirAutobus();
void imprimirCamion();

void imprimirCobrar(int cantidad, int pagado);

void imprimirMenuIrA();
void imprimirPreciosEstacionamiento();

/*Funciones*/

void imprimirTitulo(int tipoAuto) {
    printf("\n                _               _____ \n     /\\        | |             / ____|\n    /  \\  _   _| |_ ___ ______| |     \n   / /\\ \\| | | | __/ _ \\______| |     \n  / ____ \\ |_| | || (_) |     | |____ \n /_/    \\_\\__,_|\\__\\___/       \\_____|\n");
    printf("\nAuto actual: ");
    imprimirNombreAuto(tipoAuto);

    printf("\n\n 1. Seleccionar veiculo\n 2. Ir a la cuidad\n 3. Intrucciones\n 4. Ver monedero\n 5. Salir\n\n Opcion: ");
}
void imprimirInstrucciones() {
    printf("\n Instrucciones:\n\n");
    printf("\t1. Tienes que seleccionar auto.\n");
    printf("\t2. Despues ir a la cuidad.\n");
    printf("\t3. Pagar el estacionamiento.\n\n");
}

void imprimirMoneda(int moneda, int renglon) {
    switch(renglon) {
        case 1:
            printf(" /   ");
            if(moneda >= 10) {
                printf(" \\");
            } else {
                printf("\\");
            }
            break;
        case 2: printf(" | %d |", moneda); break;
        case 3:
            printf(" \\   ");
            if(moneda >= 10) {
                printf(" /");
            } else {
                printf("/");
            }
            break;
    }
}

void imprimirAuto(int tipo) {
    printf("\t");
    imprimirNombreAuto(tipo); 
    switch(tipo) {
        case 1: imprimirCarro(); break;
        case 2: imprimirCamioneta(); break;
        case 3: imprimirAutobus(); break;
        case 4: imprimirCamion(); break;
    }
}

void imprimirNombreAuto(int tipo) {
    switch(tipo) {
        case 1: printf("Carro."); break;
        case 2: printf("Camioneta."); break;
        case 3: printf("Autobus."); break;
        case 4: printf("Camion."); break;
        default: printf("Ninguno");
    }
}

void imprimirCarro() {
    printf("\n   ,-----\n,--'---:---`--,\n==(o)-----(o)==J\n");
}
void imprimirCamioneta() {
    printf("\n         _____   \n _______/__|__\\_ \n|  _    |       `|\n`(o)---------(o)== \n");
}
void imprimirAutobus() {
    printf("\n _________________________   \n|   |     |     |    | |  \\  \n|___|_____|_____|____|_|___\\ \n|                    | |    \\\n`--(o)(o)--------------(o)--'\n");
}
void imprimirCamion() {
    printf("\n _______________      ____   \n|         |     |    | |  \\  \n|_________|_____|____|_|___\\ \n|                    | |    \\\n`--(o)(o)--------------(o)--'\n");
}

void imprimirCobrar(int cantidad, int pagado) {
    printf("  __________________________\n");
    printf(" |                          |\n");
    printf(" |   Cantidad a pagar: $%d", cantidad);
    // Casos para que se imprima bien
    if(cantidad < 10) {
        printf(" ");
    }
    printf("  |\n");
    printf(" |   Pagado: $%d", pagado);
    if(cantidad < 10) {
        printf(" ");
    }
    printf("            |\n");
    printf(" |__________________________|\n\n");
}

void imprimirMenuIrA() {
    printf("\n\nQue vas a hacer?\n");
    printf(" 1. Comprar comida (1 hora)\n 2. Salir al parque (2 horas)\n 3. Ir al cine (3 horas)\n 4. Ver precios del estacionamiento\n 5. Regresar\n");
    printf("\nOpcion: ");
}

void imprimirPreciosEstacionamiento() {
    printf(" _______________________\n");
    printf("|                       |\n");
    printf("| Autos $2 la hora      |\n");
    printf("| Camionetas $4 la hora |\n");
    printf("| Autobuses $6 la hora  |\n");
    printf("|_______________________|\n");
}

#endif