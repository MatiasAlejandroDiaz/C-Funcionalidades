#include "arbol.h"

void crear_arbol(tarbol * pa)
{
    *pa = NULL;
}
int insertar_en_arbol_binario(tarbol * pa, const tinfo * info, tcmp cmp)
{
    int res;

    if(!(*pa))
    {
        *pa = (tnodoa *)malloc(sizeof(tnodoa));
        if(!*pa)
        {
            return SIN_MEM;
        }
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
        (*pa)->info = *info;
        return TODO_OK;
    }
    res = cmp(&(*pa)->info, (tinfo *)info);

    if(res == 0)
        return DUPLICADO;

    return (res > 0)? insertar_en_arbol_binario(&(*pa)->izq,info,cmp):insertar_en_arbol_binario(&(*pa)->der,info,cmp);
}
int insertar_en_arbol_binario_iterativa(tarbol * pa, const tinfo * info, tcmp cmp)
{
    int res;
    while(*pa)
    {
        res = cmp(&(*pa)->info, (tinfo *)info);

        if(res == 0)
            return DUPLICADO;

        if(res > 0)
            pa = &(*pa)->izq;
        else
            pa = &(*pa)->der;

    }

    *pa = (tnodoa *)malloc(sizeof(tnodoa));

    if(*pa == NULL)
        return SIN_MEM;

    (*pa)->der = NULL;
    (*pa)->izq = NULL;
    (*pa)->info = *info;

    return TODO_OK;
}
int recorrer_arbol_binario_inorden(tarbol * pa, taccion accion)
{
    if(*pa == NULL)
        return TODO_OK;

    recorrer_arbol_binario_inorden(&(*pa)->izq,accion);
    accion(&(*pa)->info,NULL);
    recorrer_arbol_binario_inorden(&(*pa)->der,accion);

    return TODO_OK;
}
int recorrer_arbol_binario_posorden(tarbol * pa, taccion accion)
{
    if(*pa == NULL)
        return TODO_OK;

    recorrer_arbol_binario_posorden(&(*pa)->izq,accion);
    recorrer_arbol_binario_posorden(&(*pa)->der,accion);
    accion(&(*pa)->info,NULL);

    return TODO_OK;
}
int recorrer_arbol_binario_preorden(tarbol * pa, taccion accion)
{
    if(*pa == NULL)
        return TODO_OK;

    accion(&(*pa)->info,NULL);
    recorrer_arbol_binario_preorden(&(*pa)->izq,accion);
    recorrer_arbol_binario_preorden(&(*pa)->der,accion);

    return TODO_OK;
}
int grabar_arbol_inorden(tarbol * pa, taccion accion, FILE * stream)
{
    if(*pa == NULL)
        return TODO_OK;

    grabar_arbol_inorden(&(*pa)->izq,accion,stream);
    accion(&(*pa)->info,stream);
    grabar_arbol_inorden(&(*pa)->der,accion,stream);

    return TODO_OK;
}
int grabar_arbol_preorden(tarbol * pa, taccion accion, FILE * stream)
{
    if(*pa == NULL)
        return TODO_OK;

    accion(&(*pa)->info,stream);
    grabar_arbol_preorden(&(*pa)->izq,accion,stream);
    grabar_arbol_preorden(&(*pa)->der,accion,stream);

    return TODO_OK;
}
int grabar_arbol_posorden(tarbol * pa, taccion accion, FILE * stream)
{
    if(*pa == NULL)
        return TODO_OK;

    grabar_arbol_posorden(&(*pa)->izq,accion,stream);
    grabar_arbol_posorden(&(*pa)->der,accion,stream);
    accion(&(*pa)->info,stream);

    return TODO_OK;
}
//A HACER
int leer_arbol_binario_guardado_en_preorden(tarbol * pa, taccion accion, FILE * stream)
{
    tinfo * dat = (tinfo *)malloc(sizeof(tinfo));
    if(!dat)
        return SIN_MEM;

    if(*pa == NULL)
        return TODO_OK;

    accion(dat,stream);

    return TODO_OK;
}
tnodoa * encontrar_nodo_por_clave(tarbol * pa , const tinfo * info , tcmp cmp)
{
    int res;
    if(!(*pa))
        return NULL;

    res = cmp(&(*pa)->info,(tinfo *)info);

    if(res == 0)
        return *pa;

    if(res > 0)
     return encontrar_nodo_por_clave(&(*pa)->izq,info,cmp);
    else
        return encontrar_nodo_por_clave(&(*pa)->der,info,cmp);


}
int insertar_arbol_con_vector(tarbol *pa , int * vec , int ce)
{
    int i = 0;
    tinfo inf;

    if(!pa)
        return 0;

    while( i < ce)
    {
        inf = vec[i];
        insertar_en_arbol_binario(pa,&inf,cmp_int);
        i++;
    }
    return TODO_OK;

}
//TERMINAR
int insertar_arbol_con_archivo(tarbol * pa, FILE * stream)
{
    char buff[5000];
    tinfo dato;

    fgets(buff,5000,stream);
    obtener_dato(&dato,buff);
    return TODO_OK;
}
void recorrer_hojas_arbol(tarbol * pa,taccion accion)
{
    if(!(*pa)->izq && !(*pa)->der)
    {
        accion(pa,NULL);
        return;
    }

    recorrer_hojas_arbol(&(*pa)->izq,accion);
    recorrer_hojas_arbol(&(*pa)->der,accion);

}
void vaciar_arbol(tarbol * pa)
{
    if(!*pa)
        return;

    vaciar_arbol(&(*pa)->izq);
    vaciar_arbol(&(*pa)->der);
    free(*pa);
    *pa = NULL;
}
tarbol * menor(tarbol * pa)
{
    if(!(*pa))
        return NULL;

    while((*pa)->izq)
        pa = &(*pa)->izq;

    return (tarbol *)pa;
}
tarbol * mayor(tarbol * pa)
{
    if(!(*pa))
        return NULL;

    while((*pa)->der)
        pa=&(*pa)->der;
    return (tarbol *)pa;
}
int cargar_arbol_desde_vec_pre(tarbol * pa , const void * datos, size_t ce, tcmp cmp,int * leer (tinfo * , const void *,int,int))
{
    tinfo info;
    int i = 0;
    int r;

    while(leer(&info,datos,i,ce))
    {
        r = insertar_en_arbol_binario(pa,&info,cmp);
        if(r != TODO_OK)
            return r;
        i++;
    }
    return TODO_OK;
}
///////////////////////////////////////////////////////////////////////////////////////////
int cmp_int(void * a, void * b)
{
    int * inta = (int *)a;
    int * intb = (int *)b;
    return(*inta - *intb);
}
void acc_mostrar(void * dato, const void * param)
{
    int * dat = (int *)dato;
    printf(" %d ",*dat);
}
void acc_grabar_txt(void * dato, const void * param)
{
    fprintf((FILE *)param,"%d\n",(int)*(tinfo*)dato);
}
void acc_leer_txt(void * dato, const void * param)
{
    fscanf((FILE *)param,"%d",(int *)dato);
}
void acc_grabar_bin(void * dato, const void * param)
{
    fwrite((tinfo*)dato,sizeof(tinfo),1,(FILE *)param);
}
void acc_leer_bin(void * dato, const void * param)
{
    fread((int *)dato,sizeof(tinfo),1,(FILE *)param);
}
void obtener_dato(tinfo * dato,char * cad)
{
    if((*cad) == '\0')
        return;

}
int leer_tinfo(tinfo * dat, const void * vec,int pos,int ce)
{
    if(pos >= ce)
        return 0;

    *dat = ((tinfo *)vec)[pos];
    return 1;
}
int leer_tinfo_arch_bin(tinfo * dat, const void * stream,int pos,int ce)
{
    //fseek((FILE*)stream,pos * sizeof(tinfo),SEEK_SET);

    fread(dat,sizeof(tinfo),1,(FILE *)stream);

    if(feof((FILE*)stream))
        return 0;
    return 1;
}
int leer_tinfo_arch_txt(tinfo * dat, const void * stream,int pos,int ce)
{
    //fseek((FILE*)stream,pos * sizeof(tinfo),SEEK_SET);

    if(fscanf((FILE *)stream,"%d",(int *)dat) != 1)
        return 0;
    return 1;
}
///////////////////////////////COMPLETAR ARBOL///////////////////////////////////////////////
//      0       1       2       3       4       5       6       7       8   /////////////////
//      25      50      60      75      100     125     130     150     175 /////////////////
////////////////////////////media = (lim inf + lim sup) / 2;/////////////////////////////////
// lim inf izq = lim inf       ////////    lim sup izq = media - 1          /////////////////
// lim inf der = media + 1     ////////    lim sup´der = lim sup            /////////////////
///////////////////////////caso base = lim inf > lim sup/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
int insertar_vec_ordenado_en_arbol_binario_balanceadamente (tarbol * pa , int * vec , size_t ce,tcmp cmp)
{
    return insertar_vec_balanceado(pa,vec,ce-1,ce,cmp,0,ce-1);
}
int insertar_vec_balanceado(tarbol * pa,int *vec,int media,size_t ce,tcmp cmp,int li,int ls)
{
    int med = (li + ls)/2;
    int res = cmp(&vec[media],&vec[med]);
    int der,izq,inserRes;
    tinfo dato = vec[med];

    if(li > ls)
        return TODO_OK;

    if(res == 0)
        return DUPLICADO;

    inserRes = insertar_en_arbol_binario(pa,&dato,cmp);

    if(inserRes != TODO_OK)
        return inserRes;

    izq = insertar_vec_balanceado(pa,vec,med,ce,cmp,li,med - 1);

    if(izq == TODO_OK)
        der = insertar_vec_balanceado(pa,vec,med,ce,cmp,med + 1,ls);
    else
        return izq;

    return der;
}
int cant_nodos_arbol(tarbol * pa)
{
    if(!*pa)
        return 0;

    return cant_nodos_arbol(&(*pa)->izq) + cant_nodos_arbol(&(*pa)->der) + 1;
}

int altura_arbol(tarbol * pa)
{
    int alti;
    int altd;

    if(!*pa)
        return 0;

    alti = altura_arbol(&(*pa)->izq);
    altd = altura_arbol(&(*pa)->der);
    return (alti > altd)?alti + 1:altd + 1;

}
void podar_arbol(tarbol * pa)
{
    if(!(*pa))
        return;

    if(!(*pa)->izq && !(*pa)->der)
    {
        free((*pa));
        *pa = NULL;
        return;
    }

    podar_arbol(&(*pa)->izq);
    podar_arbol(&(*pa)->der);
}
int cant_nodos_hasta_nivel(tarbol * pa, int n)
{
    if(!*pa)
        return 0;
    if( n < 0 )
        return 0;

    return cant_nodos_hasta_nivel(&(*pa)->izq, n - 1) + cant_nodos_hasta_nivel(&(*pa)->der,n - 1) + 1;
}
void podar_arbol_desde_nivel(tarbol * pa , int n)
{
    if((*pa) && !(*pa)->der && !(*pa)->izq && n == 0)
    {
        free(*pa);
        *pa = NULL;
        return;
    }

    podar_arbol_desde_nivel(&(*pa)->izq, n - 1);
    podar_arbol_desde_nivel(&(*pa)->der, n - 1);
}
int menor_arbol(tarbol * pa, tinfo * info)
{
    if(!(*pa))
        return 0;
    if((*pa)->izq)
    {
        *info = (*pa)->info;
        return 1;
    }
    return menor_arbol(&(*pa)->izq,info);
}
int mayor_arbol(tarbol * pa, tinfo * info)
{
    if(!(*pa))
        return 0;
    if(!(*pa)->der)
    {
        *info = (*pa)->info;
        return 1;
    }
    return mayor_arbol(&(*pa)->der,info);
}
int cant_nodos_arbol_desde_nivel(tarbol * pa , int n)
{
    if(!*pa)
        return 0;
    if(n <= 0)
    {
        return cant_nodos_arbol_desde_nivel(&(*pa)->izq,n-1) + cant_nodos_arbol_desde_nivel(&(*pa)->der, n - 1) + 1;
    }
    return cant_nodos_arbol_desde_nivel(&(*pa)-> izq, n - 1) + cant_nodos_arbol_desde_nivel(&(*pa)->der,n-1);
}
int cant_hojas(tarbol * pa)
{
    if(!(*pa))
        return 0;
    if(!(*pa)->der && !(*pa)->izq)
        return 1;

    return cant_hojas(&(*pa)->izq) + cant_hojas(&(*pa)->der);
}
int cant_nodos_de_nivel(tarbol * pa,int n)
{
    if(!(*pa))
        return 0;
    if(!(*pa)->der && !(*pa)->izq && n == 0)
        return 1;

    return cant_nodos_de_nivel(&(*pa)->izq, n - 1) + cant_nodos_de_nivel(&(*pa)->der, n - 1);
}
void mostrar_arbol_verticalmente(tarbol * pa)
{
    m_arb_ver(pa,0);
}
void m_arb_ver(tarbol * pa , int n)
{
    if(*pa)
    {
        int i = 0 ;
        m_arb_ver(&(*pa)->der, n + 1);
        for(;i<n;i++)
            printf("\t");
        printf("%d\n",(int)(*pa)->info);
        m_arb_ver(&(*pa)->izq, n + 1);

    }
}
int eliminar_nodo_raiz(tarbol * pa , tinfo * dato , tcmp cmp)
{
    tnodoa * nodo = encontrar_nodo_por_clave(pa,dato,cmp);

    if(!nodo){return 0;}

    eliminar_raiz(&nodo);

    return 1;
}
int eliminar_raiz(tarbol * pa)
{
    int Hizq,Hder;

    if(!(*pa))
        return 0;

    if(!(*pa)->der && !(*pa)->izq)
    {
        free(*pa);
        *pa = NULL;
        return TODO_OK;
    }

    Hizq = altura_arbol(&(*pa)->izq);
    Hder = altura_arbol(&(*pa)->der);

    tarbol * ArbNrem = (Hizq > Hder)? mayor(&(*pa)->izq): menor(&(*pa)->der);

    (*pa)->info = (*ArbNrem)->info;

    return eliminar_raiz(ArbNrem);

}
int comp_hasta_nivel(const tarbol * pa,int nivel)
{
    if(nivel == 0)
        return (int)(*pa); // ESTOY EN UNA SUPUESTA HOJA DEBUELVO SI ES NULO O NO;
    if(!(*pa))
        return 0;

    return comp_hasta_nivel(&(*pa)->izq,nivel-1) && comp_hasta_nivel(&(*pa)->der,nivel - 1);
}
int es_arbol_avl(const tarbol * pa)
{
    int h1,hd;

    //UN ARBOL VACIO ES AVL
    if(!(*pa))
        return 1;

    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);

    if(abs(hi - hd) > 1)
        return 0;

    return es_arbol_avl(&(*pa)->izq) && es_arbol_avl(&(*pa)->der);
}
int es_avl_mio(const tarbol * pa)
{

}
