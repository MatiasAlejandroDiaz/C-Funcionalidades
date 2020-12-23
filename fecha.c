#include "fecha.h"

int ingresar_fecha(t_fecha * fec, const char * mensajeOpcional)
{
    if(mensajeOpcional)
    {
        printf("%s",mensajeOpcional);
    }
    else
        printf("Introdusca la fecha(DIA/MES/AÑO):\n 0-Dejar de Ingresar. ");
    fflush(stdin);
    fec->day = 0;
    fec->month = 0;
    fec->year = 0;
    scanf("%d/%d/%d",&fec->day,&fec->month,&fec->year);
    return fec->day && fec->month && fec->year;
}

void mostrar_fecha_dma(const t_fecha * fec)
{
    printf("La fecha es : %d\t/\t%d\t/\t%d",fec->day,fec->month,fec->year);
}

int ingresar_fecha_Valida_DMA(t_fecha * fec, const char * mensajeOpcional)
{
    do
    {
        if(!ingresar_fecha(fec,mensajeOpcional))
            return 0;
    }while(!esFechaValida(fec));
    return 1;
}
int esFechaValida(const t_fecha * fec)
{
    static const char dias[][12] =
    {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };

    return fec->month > 0 && fec->month <= 12 && fec->year >= AN_MIN && fec->year <= AN_MAX && fec->day > 0 && fec->day <= dias[esBisiesto(fec->day)][fec->month - 1];
}
int comparar_fecha(const t_fecha * fec1,const t_fecha * fec2)
{
    int cmp = fec1->year - fec2->year;

    if(cmp)
        return cmp;

    cmp = fec1->month - fec2->month;

    if(cmp)
        return cmp;
    return fec1->day - fec2->day;
}
int a_Juliano(const t_fecha * fec)
{
    int dia [][12] =
    {
        {0,31,59,90,120,151,181,212,243,273,304,334},
        {0,32,60,91,121,152,182,213,244,274,305,335},
    };
    return (dia[esBisiesto(fec->year)][fec->month - 1] + fec->day);
}
int nro_de_dia_de_la_semana(const t_fecha * fec)
{
    int distBase = fec->year % 400;

    return (SABADO - 1 + distBase + distBase / 4 - distBase / 100 + ( distBase != 0) + a_Juliano(fec)) % 7;
}
long dias_entre_fechas(const t_fecha * fecha_desde, const t_fecha * fecha_hasta)
{

}
