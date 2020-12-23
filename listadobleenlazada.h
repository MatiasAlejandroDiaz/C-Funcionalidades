#ifndef LISTADOBLEENLAZADA_H_INCLUDED
#define LISTADOBLEENLAZADA_H_INCLUDED

#include "estructuras.h"
#include "macros.h"
#include <stdlib.h>

typedef struct snodo
{
    tinfo info;
    struct snodo * sig;
    struct snodo * ant;
}tnodod;

typedef tnodod * tlisdob;

void crear_lista_doble(tlisdob * pld);
int poner_en_lista_doble_ordenada(tlisdob * pld,const tinfo * info,tcmp cmp);
int recorrer_lista_doble(tlisdob * pld,taccion accion);
#endif // LISTADOBLEENLAZADA_H_INCLUDED
