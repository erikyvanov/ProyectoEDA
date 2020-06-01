#include <stdio.h>

#include "usuario.c"
#include "auto.c"
#include "imprimir.c"
#include "listaAuto.c"

int main() {
    struct Usuario usuario = crearUsuerioInicial();
    struct PunterosAutos autos = generarAutosBase();
    int opcion = 0;

    while(opcion != 5) {
        imprimirTitulo(usuario.tipoAuto);
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: recorrerAutosManualmete(autos.talon, &usuario.tipoAuto); break;
            case 2: break;
            case 3: imprimirInstrucciones(); break;
            case 4: imprimirMonedero(usuario.monedero, usuario.noMondedas); break;
            default: printf("\nOpcion invalida.\n");
        }
    }


    // Limpiar memoria
    vaciarMonedero(&usuario.monedero, &usuario.noMondedas);
    vaciarListaAutos(&autos.talon, &autos.cabeza);

    return 0;
}