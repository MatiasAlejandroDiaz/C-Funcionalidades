#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define DIS_RAIZ 5
#define DUPLICADO -1
#define TODO_OK 1
#define SIN_MEM -2
typedef int tinfo ;
typedef int (* tcmp ) (void *, void *);
typedef void (* taccion)(void *,const void *);
typedef struct snodo
{
    tinfo info;
    struct snodo * izq;
    struct snodo * der;
}tnodoa;

typedef tnodoa * tarbol;

void crear_arbol(tarbol * pa);
int insertar_en_arbol_binario(tarbol * pa , const tinfo * info, tcmp cmp);
int insertar_en_arbol_binario_iterativa(tarbol * pa , const tinfo * info, tcmp cmp);
int recorrer_arbol_binario_inorden(tarbol * pa, taccion accion);
int recorrer_arbol_binario_posorden(tarbol * pa, taccion accion);
int recorrer_arbol_binario_preorden(tarbol * pa, taccion accion);
int grabar_arbol_inorden(tarbol * pa , taccion accion, FILE * stream);
int grabar_arbol_posorden(tarbol * pa , taccion accion, FILE * stream);
int grabar_arbol_preorden(tarbol * pa , taccion accion, FILE * stream);
tnodoa * encontrar_nodo_por_clave(tarbol * pa , const tinfo * info , tcmp cmp);
void recorrer_hojas_arbol(tarbol * pa,taccion accion);
void vaciar_arbol(tarbol * pa);
tarbol * menor(tarbol * pa);
tarbol * mayor(tarbol * pa);
int insertar_arbol_con_vector(tarbol *pa , int * vec , int ce);
int insertar_arbol_con_archivo(tarbol * pa, FILE * stream);
int cargar_arbol_desde_vec_pre(tarbol * pa , const void * datos, size_t ce, tcmp cmp,int *leer (tinfo * , const void *,int,int));

// ARBOL COMPLETO
//FORMA QUE HISE YO
int insertar_vec_ordenado_en_arbol_binario_balanceadamente (tarbol * pa , int * vec , size_t ce,tcmp cmp);
int insertar_vec_balanceado(tarbol * pa,int *vec,int media,size_t ce,tcmp cmp,int li,int ls);
//TAREA
//CONTAR NODOS retorna la cantidad de nodos que tiene un arbol
int cant_nodos_arbol(tarbol * pa);
//Altura  Retorna la altura del arbol
int altura_arbol(tarbol * pa);
//PODAR ARBOL
void podar_arbol(tarbol * pa);
//CONTAR NODOS HASTA NIVEL
int cant_nodos_hasta_nivel(tarbol * pa, int n);
//PODAR DESDE NIVEL
void podar_arbol_desde_nivel(tarbol * pa , int n);
// como primitiva
int menor_arbol(tarbol * pa, tinfo * info);
int mayor_arbol(tarbol * pa, tinfo * info);
//CONTAR NODOS DESDE NIVEL
int cant_nodos_arbol_desde_nivel(tarbol * pa , int n);
//CONTAR HOJAS
int cant_hojas(tarbol * pa);
//CONTAR TODOS LOS NODOS DE UN NIVEL
int cant_nodos_de_nivel(tarbol * pa,int n);
//MOSTRAR ARBOL
void mostrar_arbol_verticalmente(tarbol * pa);
void m_arb_ver(tarbol * pa , int n);
//ACCEDO A LA DERECHA
//LOS ESPACIOS ES LA CANTIDAD DEL NIVEL
//ES INORDEN
//A HACER
int leer_arbol_binario_guardado_en_preorden(tarbol * pa , taccion accion, FILE * stream);
//////////////////////////////////////////////////////////////////////////////////////
int cmp_int(void * a, void * b);
void acc_mostrar(void * dato , const void * param);
void acc_grabar_txt(void * dato , const void * param);
void acc_leer_txt(void * dato , const void * param);
void acc_grabar_bin(void * dato , const void * param);
void acc_leer_bin(void * dato , const void * param);
//ELIMINAR
// AL ELIMINAR EL 100 COMO NODO DEBO ELEJIR UN VALOR SIGIENTE O ANTERIOR A ESTE PARA QUE EL ARBOL HAGA LAS MENORES MODIFICACIONES
// ESTO CONTRIBUYE AL DESBALANCEO DEL ARBOL POR ESO AL ELIMINAR DEBERIA ELIMINAR EL NODO DE FORMA QUE AL ELIMINAR BALANCEE EL ARBOL
// PARA AUIDARME A ELEJIR UTILIZO LA ALTURA DE ESTOS NODOS Y ELIJO EL DE MAYOR ALTURA LUEGO:
// EL MAYOR DESDE LA IZQ
// EL MENOR DE LA DERECHA
int eliminar_nodo_raiz(tarbol * pa , tinfo * dato , tcmp cmp);
int eliminar_raiz(tarbol * pa);
//CARGAR ARBOL DESDE VEC PRE
int leer_tinfo_vec(tinfo * dat, const void * vec,int pos,int ce);
int leer_tinfo_arch_bin(tinfo * dat, const void * stream,int pos,int ce);
int leer_tinfo_arch_txt(tinfo * dat, const void * stream,int pos,int ce);
//ARBOL COMPLETO : TIENE LA CANTIDAD MAXIMA DE HIJOS QUE PUEDE TENER HASTA ESE NIVEL(SALVO LAS HOJAS);
//                       ALTURA
//ARBOL COMPLETO TIENE 2        - 1 CANTIDAD DE NODOS
//HACER ARBOL COMPLETO HASTA NIVEL
int comp_hasta_nivel(const tarbol * pa,int nivel);
//ARBOL BALANCEADO LO MAS CERCA POSIBLE DE UN ARBOL COMPLETO
//DEBE ESTAR COMPLETO HASTA NIVEL DE LA ALTURA - 2
//  ALTURA-1
// 2         - 1 = COMPLETO HASTA NIVEL ( ALTURA - 2 )

//ARBOL AVL
// (ALTURA IZQ - ALTURA DER ) <= 1
// LA ALTURA DE SUS HIJOS NO DEBEN DIFERIR EN 1
int es_arbol_avl(const tarbol * pa);
int es_avl_mio(const tarbol * pa);
//CONJUNTO DE ARBOLES ( AVL ( BALANCEADO ( COMPLETOS ) BALANCEADOS ) AVL )
// UN ARBOL COMPLETO ES BALANCEADO Y AVL
// UN ARBOL BALANCEADO ES AVL
// UN ARBOL VACIO ES AVL
void obtener_dato(tinfo * dato,char * cad);
#endif // ARBOL_H_INCLUDED
