#include "recursividad.h"
//Para realizar una solucion recursiva se debe conocer una condicion de salida y una modelizacion sensilla casi como una funcion
//caso base se llama a la condicion donde corta la recursividad
int factorial_de_un_numero(int n)
{
    if(n <= 1)
        return 1;

    return (n * factorial_de_un_numero(n-1));
}

int m_c_d(int a,int b)
{
    if(b == 0)
        return a;

    return m_c_d(b,a%b);
}
void imprimir_cadena_caracter_por_caracter(char * cad)
{
    if(*cad == '\0')
        return;

    printf("%c",*cad);
    imprimir_cadena_caracter_por_caracter(cad+1);
}
void imprimir_cadena_invertida_caracter_por_caracter(char * cad)
{
    if(*cad != '\0')
    {
        imprimir_cadena_invertida_caracter_por_caracter(cad+1);
    }

    printf("%c",*(cad-1));
}
void imprimir_cadena_pero_reduciendo_tam_por_vez(char * cad)
{
    if(*cad)
    {
        imprimir_cadena(cad);

        if(*(cad+1))
            printf(",");
        else
            printf(".");

        imprimir_cadena_pero_reduciendo_tam_por_vez(cad+1);
    }
}
void imprimir_cadena_pero_Aumentando_cant_a_imprimir_por_vez(char * cad)
{
    if(*cad)
    {
       imprimir_cadena_tantos_caracteres_recursivo(cad,0);
    }
}
void imprimir_cadena_pero_reduciendo_cant_a_imprimir_por_vez(char * cad)
{
    if(*cad)
    {
        imprimir_cadena_desde_tantos_caracteres_a_ninguno_recursivo(cad,strlen(cad)-1);
    }
}
//EJEMPLO DE HOLAALOH
// void ej9 (char * cad)
//{
// if(*cad == '\0')
//      return;
//  printf("%c",*cad);
//  ej9(cad+1);
//  printf("%c",*cad);
//}
void mostrar_numero_entero(int n)
{
    int res;
    if(n == 0)
        return;
    res = divisor(n);
    printf("\t%d",n / res);
    mostrar_numero_entero(n%res);
}
void mostar_numero_en_binario(int n)
{
    if(n < 1)
        return;
    mostar_numero_en_binario(n/2);
    printf("%d",n%2);

}
int divisor(int n)
{
    int div = 1;

    while(n/div > 0)
        div *= 10;

    return div/10;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int strlen(char * cad)
{
    int cont = 0;

    while(*cad)
    {
        cont++;
        cad++;
    }

    return cont;
}
void imprimir_cadena_tantos_caracteres_recursivo(char * cad, int n)
{
    char * ini = cad;
    int cont = 0;

    if(*cad == '\0')
        return;

    while(*ini && cont <= n)
    {
        printf("%c",*ini);
        ini++;
        cont++;
    }
    if(*ini)
        imprimir_cadena_tantos_caracteres_recursivo(cad,n+1);
}
void imprimir_cadena_desde_posicion(char * cad, int n)
{
    int cont = 0;

    while(*cad && cont == n)
    {
        cad++;
        cont++;
    }

    while(*cad)
    {
        printf("%c",*cad);
        cad++;
    }
    return;
}
void imprimir_cadena(char * cad)
{
    while(*cad)
    {
        printf("%c",*cad);
        cad++;
    }
    return;
}
void imprimir_cadena_desde_tantos_caracteres_a_ninguno_recursivo(char * cad , int n)
{
    char * ini = cad;
    int cont = 0;

    if(!*cad)
        return;

    while(*ini && cont <= n)
    {
        printf("%c",*ini);
        ini++;
        cont++;
    }

    if(n > 0)
        imprimir_cadena_desde_tantos_caracteres_a_ninguno_recursivo(cad,n-1);
}
