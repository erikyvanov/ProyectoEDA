#include <stdio.h>

 #ifndef _IMPRIMIR_C
 #define _IMPRIMIR_C 1

/*Prototipos*/

void imprimirTitulo(char *nombreAuto);

void imprimirMoneda(int moneda, int renglon);

// Imprime un auto dependiendo del tipo
void imprimirAuto(int tipo);

void imprimirCarro();
void imprimirCamioneta();
void imprimirAutobus();
void imprimirCamion();

/*Funciones*/

void imprimirTitulo(char *nombreAuto) {
    printf("\n                _               _____ \n     /\\        | |             / ____|\n    /  \\  _   _| |_ ___ ______| |     \n   / /\\ \\| | | | __/ _ \\______| |     \n  / ____ \\ |_| | || (_) |     | |____ \n /_/    \\_\\__,_|\\__\\___/       \\_____|\n");
    printf("\nAuto actual: %s\n", nombreAuto);

    printf("\n 1. Seleccionar veiculo\n 2. Ir a la cuidad\n 3. Intrucciones\n 4. Ver monedero\n 5. Salir\n\n Opcion: ");
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
    switch(tipo) {
        case 1: imprimirCarro(); break;
        case 2: imprimirCamioneta(); break;
        case 3: imprimirAutobus(); break;
        case 4: imprimirCamion(); break;
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

#endif