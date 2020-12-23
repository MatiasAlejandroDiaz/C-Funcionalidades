#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED
#include <stdio.h>
int factorial_de_un_numero(int n);
int m_c_d(int a,int b);
void imprimir_cadena_caracter_por_caracter(char * cad);
void imprimir_cadena_invertida_caracter_por_caracter(char * cad);
void imprimir_cadena_pero_reduciendo_tam_por_vez(char * cad);
void imprimir_cadena_pero_Aumentando_cant_a_imprimir_por_vez(char * cad);
void imprimir_cadena_pero_reduciendo_cant_a_imprimir_por_vez(char * cad);
//NUMEROS
void mostrar_numero_entero(int n);
void mostar_numero_en_binario(int n);
//UTILS
void imprimir_cadena_tantos_caracteres_recursivo(char * cad , int n);
void imprimir_cadena_desde_tantos_caracteres_a_ninguno_recursivo(char * cad , int n);
void imprimir_cadena_desde_posicion(char * cad , int n);
void imprimir_cadena(char * cad);
int strlen(char * cad);
int divisor(int n);
#endif // RECURSIVIDAD_H_INCLUDED
