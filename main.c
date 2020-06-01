#include <stdio.h>

#include "usuario.c"
#include "monedero.c"

int main() {
    struct Usuario usuario = crearUsuerioInicial();

    imprimirMonedero(usuario.monedero, usuario.noMondedas);
    vaciarMonedero(&usuario.monedero, &usuario.noMondedas);

    return 0;
}