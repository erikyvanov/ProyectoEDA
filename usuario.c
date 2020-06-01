#include <stdlib.h>

#include "monedero.c"

 #ifndef _USUARIO_C
 #define _USUARIO_C 1

struct Usuario {
    int tipoAuto;
    char *nombreAuto;

    struct Monedero *monedero;
    int noMondedas;
};

struct Usuario crearUsuerioInicial();

// Recibe un arreglo con 4 espacios(monedas) donde se especifica cuantos monedas tiene de cada tipo
// Recibe un arreglo con 4 espacios(denomicaciones) donde se especifica las denominaciones de las monedas
struct Monedero * monederoInicial(int *monedas, int *denominaciones, int *noMonedas);


struct Usuario crearUsuerioInicial() {
    struct Usuario nuevo;
    int monedasIniciales[4] = { 3, 3, 3, 3 };
    int denominaciones[4] = { 1, 2, 5, 10 };

    nuevo.monedero = monederoInicial(monedasIniciales, denominaciones, &nuevo.noMondedas);

    nuevo.tipoAuto = 0;
    nuevo.nombreAuto = "Ninguno\0";
    return nuevo;
}

struct Monedero * monederoInicial(int *monedas, int *denominaciones, int *noMonedas) {
    struct Monedero *nuevo = NULL;
    int i, j;

    for(i=0; i<4; i++) {
        for(j=0; j<monedas[i]; j++) {
            push(&nuevo, denominaciones[i], noMonedas);
        }
    }
    
    return nuevo;
}

#endif