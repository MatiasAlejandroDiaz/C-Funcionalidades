#include "lista.h"

void crear_lista(tlista * pl)
{
    *pl = NULL;
}
int poner_en_lista_ordenada(tlista * pl,const tinfo * dato, tcmp cmp)
{
    int res = 1;
    tnodo * nue;

    while(*pl && (res=cmp(dato,&(*pl)->info))>0)
        pl = &(*pl)->sig;

    if(!res)
        return DUPLICADO;

    nue = (tnodo *)malloc(sizeof(tnodo));
    if(!nue)
        return SIN_MEMORIA;

    nue->info = *dato;
    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}
int sacar_de_lista_ordenada(tlista * pl,void * clave, tinfo * dato, tcmp cmp)
{
    int res = 1;
    tnodo * aux;

    while(*pl && (res = cmp(clave,&(*pl)->info)) > 0)
        pl=&(*pl)->sig;

    if(res < 0 || (*pl)== NULL)
        return DATO_NO_ENCONTRADO;

    aux = *pl;
    *dato = aux->info;
    *pl = aux->sig;
    free(aux);

    return TODO_OK;

}
int recorrer_lista(tlista * pl,taccion accion)
{
    while(*pl) {
        accion(&(*pl)->info,NULL);
        pl = &(*pl)->sig;
    }

    return TODO_OK;
}
int actualizar_dato_por_clave(tlista * pl,void * clave,tcmp cmp,taccion accion)
{
    int res = 1;

    while(*pl && (res = cmp(clave,&(*pl)->info)) > 0)
        pl = &(*pl)->sig;

    if(*pl == NULL || res < 0)
        return DATO_NO_ENCONTRADO;

    accion(&(*pl)->info,NULL);

    return TODO_OK;
}
void vaciar_lista(tlista * pl)
{
    tnodo * aux;

    while(*pl != NULL) {
        aux = *pl;
        *pl = (aux)->sig;
        free(aux);
    }
}
int ordenar_lista_seleccion(tlista * pl,tcmp cmp)
{
    tlista * menor;
    tnodo * aux;

    if(*pl == NULL)
        return LISTA_VACIA;

    while(*pl) {
        menor = buscar_menor(pl,cmp);
        aux = *menor;
        *menor = (*menor)->sig;
        aux->sig = *pl;
        *pl = aux;
        pl = &(*pl)->sig;
    }

    return TODO_OK;

}
tlista * buscar_menor(tlista * pl,tcmp cmp)
{
    tlista * menor = pl;
    int res;
    tinfo * menorinfo = &(*pl)->info;

    while((*pl)->sig != NULL)
    {
        res = cmp(menorinfo,&(*pl)->sig->info);
        if(res > 0)
        {
            menor = &(*pl)->sig;
            menorinfo = &(*menor)->info;
        }

        pl = &(*pl)->sig;
    }

    return menor;
}

int poner_en_lista(tlista * pl,const tinfo * dato , tcmp cmp)
{
    tnodo * nue = (tnodo *)malloc(sizeof(tnodo));
    if(!nue)
        return SIN_MEMORIA;

    while(*pl)
        pl = &(*pl)->sig;

    nue->info = *dato;
    nue->sig = *pl;
    *pl = nue;
    return TODO_OK;
}
int poner_en_lista_circular(tlista * ppl,const tinfo * dato)
{
    tnodo * nue = (tnodo *)malloc(sizeof(tnodo));

    if(nue == NULL)
        return SIN_MEMORIA;

    nue->info = *dato;

    if(*ppl == NULL)
    {
        nue->sig = nue;
        *ppl = nue;
        return TODO_OK;
    }

    //Inserto en la posicion menos costosa o sea al lado del primero

    nue->sig = (*ppl)->sig;
    (*ppl)->sig = nue;

    return TODO_OK;

}
int recorrer_lista_circular(tlista * pl,taccion accion)
{
    tnodo * pri = *pl;
    if(*pl == NULL)
        return LISTA_VACIA;
    do
    {
        accion(&(*pl)->info,NULL);
        pl = &(*pl)->sig;
    }
    while(pri != *pl);

    return TODO_OK;
}
