#ifndef FECHA_H_
#define FECHA_H_

#include <stdio.h>

#define AN_MIN 1
#define AN_MAX 500
#define esBisiesto(x) (((x)%4 == 0 && (x)%100 != 0 ) || \
                       (x) % 400 == 0 )
#define DOMINGO 0
#define LUNES 1
#define MARTES 2
#define MIERCOLES 3
#define JUEVES 4
#define VIERNES 5
#define SABADO 6

typedef struct
{
    int day,
        month,
        year;
}t_fecha;

/**
*Libreria de fecha.
**/

int ingresar_fecha(t_fecha * fec, const char * mensajeOpcional);
void mostrar_fecha_dma(const t_fecha * fec);
int esFechaValida(const t_fecha * fec);
/**
*Muestra si una fecha es Valida.
**/
int ingresar_fecha_Valida_DMA(t_fecha * fec, const char * mensajeOpcional);
int comparar_fecha(const t_fecha * fec1,const t_fecha * fec2);
int a_Juliano(const t_fecha * fec);
int nro_de_dia_de_la_semana(const t_fecha * fec);
long dias_entre_fechas(const t_fecha * fecha_desde, const t_fecha * fecha_hasta);

#endif // FECHA_H_INCLUDED
