#include "listadobleenlazada.h"

void crear_lista_doble(tlisdob * pld)
{
    *pld = NULL;
}
int poner_en_lista_doble_ordenada(tlisdob * pld,const tinfo * info,tcmp cmp)
{
    tnodod * pauxant;
    tnodod * pauxsig;
    tnodod * pactual;
    int res;

    if(*pld != NULL)
    {
        pactual = *pld;

        while(pactual->ant != NULL && (res = cmp(&pactual->info,info)) > 0 )
            pactual = pactual->ant;
        while(pactual->sig != NULL && (res = cmp(&pactual->info,info)) < 0 )
            pactual = pactual->sig;

        pauxant = pactual->ant;
        pauxsig = pactual->sig;
    }
    else
    {
        pauxant = NULL;
        pauxsig = NULL;
    }

    tnodod * nue = (tnodod *)malloc(sizeof(tnodod));
    if(nue == NULL)
        return SIN_MEMORIA;
    nue->info = *info;

    nue->ant = pauxant;
    nue->sig = pauxsig;

    if(pauxant != NULL)
        pauxant = nue;
    if(pauxsig != NULL)
        pauxsig = nue;

    *pld = nue;

    return TODO_OK;
}
int recorrer_lista_doble(tlisdob * pld,taccion accion)
{
    tnodod * pactual = *pld;

    while(pactual->ant != NULL)
    {
        accion(pactual,NULL);
        pactual = pactual->ant;
    }

    if((*pld)->sig != NULL)
    {
        pactual = (*pld)->sig;
        while(pactual->sig != NULL)
        {
            accion(pactual,NULL);
            pactual = pactual->sig;
        }
    }

    return TODO_OK;
}
