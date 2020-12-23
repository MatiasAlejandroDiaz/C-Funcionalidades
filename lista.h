#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>
#include "estructuras.h"
#include "macros.h"

typedef struct snodoa {
    tinfo info;
    struct snodoa * sig;
} tnodo;

typedef tnodo * tlista;


void crear_lista(tlista * pl);
int poner_en_lista_circular(tlista * ppl,const tinfo * dato);
int poner_en_lista_ordenada(tlista * pl,const tinfo * dato , tcmp cmp);
int poner_en_lista(tlista * pl,const tinfo * dato , tcmp cmp);
int sacar_de_lista_ordenada(tlista * pl,void * clave,tinfo * dato, tcmp cmp);
int recorrer_lista(tlista * pl,taccion accion);
int recorrer_lista_circular(tlista * pl,taccion accion);
int actualizar_dato_por_clave(tlista * pl,void * clave,tcmp cmp,taccion accion);
void vaciar_lista(tlista * pl);
int ordenar_lista_seleccion(tlista * pl,tcmp cmp);
tlista * buscar_menor(tlista * pl,tcmp cmp);
#endif // LISTA_H_INCLUDED
