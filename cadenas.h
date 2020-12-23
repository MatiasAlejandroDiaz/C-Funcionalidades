#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int cadena_lengt(const char * cad);
char * sacar_espacios_innecesarios(char * cadObj);
int copiar_cadena(char * cad_a_cop,char * cad_a_esc);
char * buscar_caracter_en_cadena(char * cad_a_bus,char caracter);
char * buscar_caracter_en_cadena_desde_el_final(char * cad_a_bus,char caracter);
char * copiar_cadenas(char * cad_dest ,const char * cad_a_cop);
char * copiar_cadena_nomas_de_n(char * cad_dest,const char * cad_a_cop,int n);
int comparar_cadenas(const char * a,const char * b);
int es_alphanumerico(const char c);
int es_letra(const char c);
int es_mayuscula(const char c);
int es_minuscula(const char c);
char caracter_a_mayuscula( char  c );
char caracter_a_minuscula( char  c );
char * convertir_cadena_a_mayuscula( char * cad );
char * convertir_cadena_a_minuscula ( char * cad );
int de_aschi_a_entero(const char * cad);


///UTILS
int obtener_factor(int lengt);
int alphanumerico_a_entero(const char c);
#endif // CADENAS_H_INCLUDED
