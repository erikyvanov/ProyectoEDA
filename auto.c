#include <stdlib.h>
#include "listaAuto.c"

 #ifndef _AUTO_C
 #define _AUTP_C 1

struct PunterosAutos {
    struct Auto *cabeza;
    struct Auto *talon;
};

// Genera los 4 autos base (carro, camionetam, autobus, camion)
struct PunterosAutos generarAutosBase();

struct PunterosAutos generarAutosBase() {
    struct PunterosAutos base;

    base.cabeza = NULL;
    base.talon =  NULL;

    meter(&base.talon, &base.cabeza, 1);
    meter(&base.talon, &base.cabeza, 2);
    meter(&base.talon, &base.cabeza, 3);
    meter(&base.talon, &base.cabeza, 4);

    return base;
}

#endif