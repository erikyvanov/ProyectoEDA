#include <stdio.h>
#include <stdlib.h>

#include "imprimir.c"

 #ifndef _LISTAAUTO_C
 #define _LISTAAUTO_C 1

// Auto es una lista circular doblemente ligada
struct Auto {
    int tipo;

    struct Auto *ptrAnterior;
    struct Auto *ptrSiguiente;
};

/* Prototipos */
void meter(struct Auto **ptrTalon, struct Auto **ptrCabeza, int tipo);
void sacar(struct Auto **ptrTalon, struct Auto **ptrCabeza);
void imprimirTalon(struct Auto *ptrTalon, struct Auto *ptrCabeza);
void imprimirCabeza(struct Auto *ptrTalon, struct Auto *ptrCabeza);
void recorrerAutosManualmete(struct Auto *ptr, int *tipo);
void vaciarListaAutos(struct Auto **ptrTalon, struct Auto **ptrCabeza);

void meter(struct Auto **ptrTalon, struct Auto **ptrCabeza, int tipo) {
    struct Auto *nuevo = (struct Auto *) malloc( sizeof(struct Auto) );

    //Si algo salio mal
    if(nuevo == NULL) {
        printf("\n\tERROR: No hay memoria.");
        return;
    }

    nuevo->tipo = tipo;
    
    //Insertar primer elemento
    if(*ptrTalon == NULL && *ptrCabeza == NULL) {
        nuevo->ptrAnterior = nuevo;
        nuevo->ptrSiguiente = nuevo;

        *ptrTalon = nuevo;
        *ptrCabeza = nuevo;

        return;
    }

    //Puntero que recorrera la lista
    struct Auto *actual = *ptrTalon;
    struct Auto *anterior = (*ptrTalon)->ptrAnterior;

    while(nuevo->tipo > actual->tipo && actual != *ptrCabeza) {
        anterior = actual;
        actual = actual->ptrSiguiente;
    }

    if(actual == *ptrTalon) {
        //cuando el nuevo es menor al primer elemento
        if(nuevo->tipo < (*ptrTalon)->tipo) {
            nuevo->ptrSiguiente = actual;
            nuevo->ptrAnterior = anterior;

            actual->ptrAnterior = nuevo;

            (*ptrCabeza)->ptrSiguiente = nuevo;

            *ptrTalon = nuevo;
        } else { //Caso particular para el insertar el segundo elemento
            nuevo->ptrAnterior = actual;
            nuevo->ptrSiguiente = actual->ptrSiguiente;

            actual->ptrSiguiente = nuevo;
            actual->ptrAnterior = nuevo;

            *ptrCabeza = nuevo;
        }

        return;
    }

    //Si llego al ultimo elemento se tiene que cambiar la cabeza
    if(actual == *ptrCabeza && nuevo->tipo > actual->tipo) {
        *ptrCabeza = nuevo;

        actual->ptrSiguiente = nuevo;

        nuevo->ptrAnterior = actual;
        nuevo->ptrSiguiente = *ptrTalon;

        (*ptrTalon)->ptrAnterior = (*ptrCabeza);

        return;
    }
    
    nuevo->ptrAnterior = anterior;
    nuevo->ptrSiguiente = actual;

    anterior->ptrSiguiente = nuevo;
    actual->ptrAnterior = nuevo;
}

void sacar(struct Auto **ptrTalon, struct Auto **ptrCabeza) {
    if(*ptrTalon != NULL) {
        int eliminar;
        printf(" | Eliminar dato |\n");
        printf("Dato a eliminar: ");
        scanf("%d", &eliminar);

        //Caso para cuando hay un solo elemento
        if(*ptrTalon == *ptrCabeza) {
            if((*ptrTalon)->tipo == eliminar) {
                free(*ptrCabeza);

                *ptrCabeza = NULL;
                *ptrTalon = NULL;

                printf("\n%d se elimino de la lista.\n\n", eliminar);
            } else {
                printf("\n%d no esta en la lista.\n\n", eliminar);
            }
            return;
        }

        //Caso para el primer elemento
        if((*ptrTalon)->tipo == eliminar) {
            *ptrTalon = (*ptrTalon)->ptrSiguiente;
            free((*ptrTalon)->ptrAnterior);

            (*ptrTalon)->ptrAnterior = *ptrCabeza;
            (*ptrCabeza)->ptrSiguiente = *ptrTalon;

            printf("\n%d se elimino de la lista.\n\n", eliminar);
            return;
        }

        //Caso para el ultimo elemento
        if((*ptrCabeza)->tipo == eliminar) {
            *ptrCabeza = (*ptrCabeza)->ptrAnterior;
            free((*ptrCabeza)->ptrSiguiente);

            (*ptrCabeza)->ptrSiguiente = *ptrTalon;
            (*ptrTalon)->ptrAnterior = *ptrCabeza;

            printf("\n%d se elimino de la lista.", eliminar);
            return;
        }

        //Puntero que recorrera la lista
        struct Auto *actual = *ptrTalon;    
        struct Auto *anterior = (*ptrTalon)->ptrAnterior;   

        while(actual != *ptrCabeza) {
            if(eliminar == actual->tipo){
                anterior->ptrSiguiente = actual->ptrSiguiente;
                actual->ptrSiguiente->ptrAnterior = anterior;

                free(actual);
                printf("\n%d se elimino de la lista.\n\n", eliminar);
                return;
            }

            anterior = actual;
            actual = actual->ptrSiguiente;
        }

        printf("\n%d no esta en la lista.\n\n", eliminar);
        
    } else {
        printf("\nLa lista esta vacia.\n\n");
    }
}

void imprimirTalon(struct Auto *ptrTalon, struct Auto *ptrCabeza) {
    printf("\n\n| Imprimir desde talon |\n");
    if(ptrTalon == NULL) {
        printf("La lista esta vacia.\n\n");
        return;
    }

    while(ptrTalon != ptrCabeza) {
        printf(" %d", ptrTalon->tipo);
        ptrTalon = ptrTalon->ptrSiguiente;
    }
    printf(" %d", ptrTalon->tipo);
    printf("\n\n");
}

void imprimirCabeza(struct Auto *ptrTalon, struct Auto *ptrCabeza) {
    printf("\n\n| Imprimir desde Cabeza |\n");
    if(ptrTalon == NULL) {
        printf("La lista esta vacia.\n\n");
        return;
    }

    while(ptrTalon != ptrCabeza) {
        printf(" %d", ptrCabeza->tipo);
        ptrCabeza = ptrCabeza->ptrAnterior;
    }
    printf(" %d", ptrCabeza->tipo);

    printf("\n\n");
}

void recorrerAutosManualmete(struct Auto *ptr, int *tipo) {
    if(ptr != NULL) {
        int opcion = 0;

        while(opcion != 3) {
            system("clear");
            printf("Selecciona tu veiculo\n\n");
            imprimirAuto(ptr->tipo);

            printf("\n1. Anterior    2. Siguiente    3. Seleccionar\n\t Opcion: ");
            scanf("%d", &opcion);

            switch(opcion) {
                case 1: ptr = ptr->ptrAnterior; break;
                case 2: ptr = ptr->ptrSiguiente; break;
                case 3: *tipo = ptr->tipo; break;
                default: printf("Opcion no valida\n"); break;
            }
        }
    } else {
        printf("La lista esta vacia.\n\n");
    }
} 

void vaciarListaAutos(struct Auto **ptrTalon, struct Auto **ptrCabeza) {
    printf("Vaciando autos...\n");

    if(*ptrTalon != NULL) { 
        //Puntero para recorrer la lista
        struct Auto *actual;

        while(*ptrTalon != *ptrCabeza) {
            actual = *ptrTalon;
            *ptrTalon = (*ptrTalon)->ptrSiguiente;

            free(actual);
        }

        free(*ptrCabeza);

        *ptrTalon = NULL;
        *ptrCabeza = NULL;
    }
}

#endif