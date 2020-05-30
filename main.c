#include <stdio.h>
#include "imprimir.h"

int main() {
    int i;

    for(i=1; i<=4; i++) {
        imprimirAuto(i);
    }

    imprimirTitulo();
    return 0;
}