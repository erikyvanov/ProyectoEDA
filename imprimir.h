#include <stdio.h>


void imprimirAuto(int tipo);
void imprimirCarro();
void imprimirCamioneta();
void imprimirAutobus();
void imprimirCamion();

void imprimirTitulo();


// Imprime un auto dependiendo del tipo
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

void imprimirTitulo() {
    printf("\n                _               _____ \n     /\\        | |             / ____|\n    /  \\  _   _| |_ ___ ______| |     \n   / /\\ \\| | | | __/ _ \\______| |     \n  / ____ \\ |_| | || (_) |     | |____ \n /_/    \\_\\__,_|\\__\\___/       \\_____|\n");
}