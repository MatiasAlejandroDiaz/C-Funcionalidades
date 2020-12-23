#include "pilacircular.h"

void crear_pila_circular(tpilac * pp)
{
    *pp = NULL;
}
void vaciar_pila_circular(tpilac * pp)
{
    tnodo * aux;
    tnodo * pri = *pp;
    do
    {
        aux = *pp;
        *pp = aux->sig;
        free(aux);
    }
    while(pri != *pp);

}
int poner_en_pila_circular(tpilac * pp, const tinfo * info)
{
    tnodo * nue = (tnodo *)malloc(sizeof(tnodo));
    if(nue == NULL)
        return SIN_MEMORIA;

    nue->info = *info;
    if(*pp == NULL)
    {
        nue->sig = nue;
        *pp=nue;
        return TODO_OK;
    }

    nue->sig = (*pp)->sig;
    (*pp)->sig = nue;
    *pp = nue;

    return TODO_OK;
}
int sacar_en_pila_circular(tpilac * pp, tinfo * info)
{
    tnodo * aux;

    if(*pp == NULL)
        return LISTA_VACIA;

    aux = *pp;
    *info = aux->info;
    *pp = aux->sig;
    free(aux);
    return TODO_OK;
}
int ver_tope_de_pila(const tpilac * pp,tinfo * info)
{
    if(*pp == NULL)
        return LISTA_VACIA;
    *info = (*pp)->info;
    return TODO_OK;
}
int pila_circular_vacia(const tpilac * pp)
{
    return (*pp == NULL);
}
int pila_circular_llena(const tpilac * pp)
{
    tnodo * nue = (tnodo *)malloc(sizeof(tnodo));
    free(nue);
    return (nue == NULL);
}
