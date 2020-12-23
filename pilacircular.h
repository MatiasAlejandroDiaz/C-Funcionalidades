#ifndef PILACIRCULAR_H_INCLUDED
#define PILACIRCULAR_H_INCLUDED

#include "estructuras.h"
#include "macros.h"
#include <stdlib.h>

typedef struct snodo {
    tinfo info;
    struct snodo * sig;
} tnodo;

typedef tnodo * tpilac;

void crear_pila_circular(tpilac * pp);
void vaciar_pila_circular(tpilac * pp);
int poner_en_pila_circular(tpilac * pp, const tinfo * info);
int sacar_en_pila_circular(tpilac * pp, tinfo * info);
int ver_tope_de_pila(const tpilac * pp,tinfo * info);
int pila_circular_vacia(const tpilac * pp);
int pila_circular_llena(const tpilac * pp);

#endif // PILACIRCULAR_H_INCLUDED
