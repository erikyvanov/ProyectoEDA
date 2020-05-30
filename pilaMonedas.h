#include <stdio.h>
#include <stdlib.h>

struct NodoLista{
	char dato;
	struct NodoLista *ptrSiguiente;
};

void push(struct NodoLista **ptrS, char nuevoDato);
void pop(struct NodoLista **ptrCima);
void imprimePila(struct NodoLista *ptrAnterior);

int main(){
	struct NodoLista *ptrInicial;
    ptrInicial = NULL;
    char letra;
    int opcion=1;
    while (opcion != 0){
        printf("Ingresa la opcion deseada\n");
        printf("1.- Ingresar\n2.- Sacar\n3.- imprimir\n0.- Salir");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion) {
            case 1:
                printf("Que letra decesas ingresar?\n");
                scanf("%c", &letra);
                fflush(stdin);
                push(&ptrInicial, letra);
                break;
                
            case 2:
                pop(&ptrInicial);
                break;
                
            case 3:
                imprimePila(ptrInicial);
                break;
                
            default:
                break;
        }
    }
	return 0;
}

void push(struct NodoLista **ptrS, char nuevoDato){
    struct NodoLista *ptrNuevo;
    ptrNuevo = (struct NodoLista *)malloc(sizeof(struct NodoLista));
    if (ptrNuevo != NULL){
        ptrNuevo->dato = nuevoDato;
        ptrNuevo->ptrSiguiente = *ptrS;
        *ptrS = ptrNuevo;
        printf("se ingreso un nuevo dato\n");
    }else{
        printf("No se inserto, Memoria insuficiente\n");
    }
}

void pop(struct NodoLista **ptrCima){
    struct NodoLista *ptrTemp;
    char caracterTemporal;
    ptrTemp = *ptrCima;
    caracterTemporal = (*ptrCima)->dato;
    printf("%c\n", caracterTemporal);
    *ptrCima = (*ptrCima)->ptrSiguiente;
    free(ptrTemp);
}

void imprimePila(struct NodoLista *ptrAnterior){
    if (ptrAnterior == NULL){
        printf("La pila esta vacia\n");
        return;
    }
    printf("La pila es :\n");
    while (ptrAnterior != NULL) {
        printf("%c =-=>", ptrAnterior->dato);
        ptrAnterior = ptrAnterior -> ptrSiguiente;
    }
    printf("NULL\n");
}