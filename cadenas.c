#include "cadenas.h"

int cadena_lengt(const char * cad)
{
    int sum = 0;
    while(*cad != '\0')
    {
        sum++;
        cad++;
    }
    return sum;
}
int copiar_cadena(char * cad_a_cop,char * cad_a_esc)
{
    while(*cad_a_cop)
    {
        *cad_a_esc = *cad_a_cop;
        cad_a_cop++;
        cad_a_esc++;
    }
    *cad_a_esc = '\0';
    return 1;
}
char * sacar_espacios_innecesarios(char * cadObj)
{
    char * cadIni = cadObj;
    char * cadRet = (char *)malloc(sizeof(char) * cadena_lengt(cadObj));
    if(!cadRet){return 0;}

    char ant = cadObj[0];
    cadObj++;

    while(*cadObj != '\0')
    {
        if(ant == ' ' && *cadObj == ' ')
            *cadObj = '\0';
        else
        {
            ant = *cadObj;
            cadObj++;
        }
    }
    copiar_cadena(cadIni,cadRet);
    return cadRet;
}
char * buscar_caracter_en_cadena(char * cad_a_bus,char caracter)
{
    char * cadret = cad_a_bus;

    while(*cad_a_bus != caracter)
        if(!*cad_a_bus)
            return 0;
        else
            cad_a_bus++;

    cadret = cad_a_bus;
    return cadret;
}
char * buscar_caracter_en_cadena_desde_el_final(char * cad_a_bus,char caracter)
{
    char * cadret = 0;

    while(*cad_a_bus)
    {
        if(*cad_a_bus == caracter)
            cadret = cad_a_bus;
        cad_a_bus++;
    }
    return cadret;
}
char * copiar_cadenas(char * cad_dest ,const char * cad_a_cop)
{
    char * cadret = cad_dest;

    while(*cad_a_cop)
    {
        *cad_dest = *cad_a_cop;
        cad_a_cop++;
        cad_dest++;
    }

    return cadret;
}
int comparar_cadenas(const char * a,const char * b)
{
    while(*a && (*a == *b))
        a++,b++;
    return *(const unsigned char *)a - *(const unsigned char *)b;
}
char * copiar_cadena_nomas_de_n(char * cad_dest,const char * cad_a_cop,int n)
{
    char * cadret = cad_dest;
    do
    {
        if(!n)
            return 0;
        *cad_dest = *cad_a_cop;
        n--;
        cad_dest++;
        cad_a_cop++;
    }
    while(*cad_dest);

    while(n)
    {
        *cad_dest = 0;
        n--;
        cad_dest++;
    }

    return cadret;
}
int es_alphanumerico(const char c)
{
    return ( (c >= '0') && (c <= '9'));
}
int es_letra(const char c)
{
    return(((c >= 'A') && (c <= 'Z') )||( (c >= 'a') && (c <= 'z')));
}
int es_mayuscula(const char c)
{
    return((c>='A')&& (c <= 'Z'));
}
int es_minuscula(const char c)
{
    return((c>='a')&&(c<='z'));
}
char caracter_a_mayuscula( char  c )
{
    if(es_letra(c))
        c -= 32;
    return c;
}
char caracter_a_minuscula( char  c )
{
    if(es_letra(c))
        c += 32;
    return c;
}
char * convertir_cadena_a_mayuscula( char * cad )
{
    char * cadret = cad;
    int index = 0;
    while(cad[index])
    {
        if(es_letra(cad[index]) && es_minuscula(cad[index]))
            cad[index] = caracter_a_mayuscula(cad[index]);

        index++;
    }

    return cadret;
}
char * convertir_cadena_a_minuscula ( char * cad )
{
    char * cadret = cad;
    while(*cad)
    {
        if(es_letra(*cad)&& es_mayuscula(*cad))
            *cad = caracter_a_minuscula(*cad);
        cad++;
    }
    return cadret;
}
int de_aschi_a_entero(const char * cad)
{
    int int_ret = 0;
    long int factor = (long int)obtener_factor(cadena_lengt(cad));

    while(*cad)
    {
        if(!es_alphanumerico(*cad))
            return 0;

        int_ret += alphanumerico_a_entero(*cad) * factor;
        factor /= 10;
        cad++;
    }

    return int_ret;
}
int alphanumerico_a_entero(const char c)
{
    return c - '0';
}
int obtener_factor(int length)
{
    int i;
    int intret = 1;

    if(length == 0)
        return 1;

    for(i = 0; i < length - 1 ; i++)
        intret *= 10;

    return intret;
}
