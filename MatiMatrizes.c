#include <stdio.h>
#include <stdlib.h>
#include "MatiMatrizes.h"

void mostrar_matriz( int ** m1,int fm1,int cml)
{
    int i = 0;
    int e = 0;
    //printf("\n La Matriz Es :");
    for(; i < fm1; i++)
    {
        printf("\n\t[\t");

        for(e=0; e < cml; e++)
        {
            printf("%i\t",(int)*(m1+(e + (i * cml))));
        }
        printf("]\n");
    }
}

void producto_de_matrizes( int m1[][TAM], int m2[][TAM],int fm1,int cm1fm2,int cm2, int m3[][TAM])
{
    int i,e,r;
    for(i = 0; i < fm1 ; i++)
    {
        for(r = 0;r < cm2;r++)
        {
            m3[i][r]= 0;
            for(e = 0; e < cm1fm2;e++)
            {
                m3[i][r] += m1[i][e] * m2[e][r];
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////-------------DIAGONAL PRINCIPAL------------////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar_diagonal_principal_matriz(int m1[][TAM],int f, int c)
{
    int i = 0;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nDiagonal Principal :\t[\t");
    for(i = 0; i < f; i++)
    {
        printf("%d\t",m1[i][i]);
    }
    printf("]\n");
}

void obtener_diagonal_principal_matriz(int * vec,int * tamVec,int ml[][TAM],int f, int c)
{
    int i = 0;

    if(*tamVec < f)
    {
        printf("\nEl tamaño del vector dado No es suficiente para guardar la diagonal requerida.");
        return;
    }
    (*tamVec) = 0;
    ES_MATRIZ_CUADRADA(f,c)

    for(i = 0; i < f; i++)
    {
        *vec = ml[i][i];
        vec++;
        (*tamVec)++;
    }

}

void mostrar_triangulo_superior_a_la_diag_principal_con_diag_principal(int m1[][TAM],int f,int c)
{
    int i = 0;
    int e;
    int g;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nTriangulo Superior a la diagonal principal con esta incluida :");

    for(; i < f; i++)
    {
        printf("\n\t\t\t[");
        for(g=0; g <= i; g++)
        {
            printf(" \t");
        }

        for(e = i; e < f; e++)
        {
            printf("%d\t",m1[i][e]);
        }
        printf("]");
    }
}
void mostrar_triangulo_superior_a_la_diag_principal(int m1[][TAM],int f,int c)
{
    int i = 0;
    int e;
    int g;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nTriangulo Superior a la diagonal principal sin esta incluida :");

    for(; i < f; i++)
    {
        printf("\n\t\t\t[");
        for(g=0; g <= i+1; g++)
        {
            printf(" \t");
        }

        for(e = i+1; e < f; e++)
        {
            printf("%d\t",m1[i][e]);
        }
        printf("]");
    }
}
void mostrar_triangulo_inferior_a_la_diag_principal_con_diag_principal(int m1[][TAM],int f,int c)
{
    int i = 0;
    int e;
    int g;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nTriangulo Inferior a la diagonal principal con esta incluida :");

    for(; i < f; i++)
    {
        printf("\n\t\t\t[\t");
        for(e = 0; e <= i; e++)
        {
            printf("%d\t",m1[i][e]);
        }
        for(g=i; g < f-1; g++)
        {
            printf(" \t");
        }
        printf("]");
    }
}
void mostrar_triangulo_inferior_a_la_diag_principal(int m1[][TAM],int f,int c)
{
    int i = 0;
    int e;
    int g;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nTriangulo Inferior a la diagonal principal sin esta incluida :");

    for(; i < f; i++)
    {
        printf("\n\t\t\t[\t");
        for(e = 0; e < i; e++)
        {
            printf("%d\t",m1[i][e]);
        }
        for(g=i; g < f; g++)
        {
            printf(" \t");
        }
        printf("]");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////-------------DIAGONAL SECUNDARIA------------////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar_diagonal_secundaria_matriz(int m1[][TAM],int f, int c)
{
    int i = f-1;
    int e = 0;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\n\nDiagonal Secundaria :\t[\t");
    for(; i>=0; i--,e++)
    {
        printf("%d\t",m1[e][i]);
    }
    printf("]\n");
}

void obtener_diagonal_secundaria_matriz(int * vec,int * tamVec,int ml[][TAM],int f, int c)
{
    int i = f-1;
    int e = 0;

    if(*tamVec < f)
    {
        printf("\nEl tamaño del vector dado No es suficiente para guardar la diagonal requerida.");
        return;
    }
    (*tamVec) = 0;
    ES_MATRIZ_CUADRADA(f,c)

    for(; i>=0; i--,e++)
    {
        *vec = ml[e][i];
        vec++;
        (*tamVec)++;
    }
}

void mostrar_triangulo_superior_a_la_diag_secundaria_con_diag_principal(int m1[][TAM],int f,int c)
{
    int i = 0;
    int e = c-1;
    int g;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nTriangulo Superior a la diagonal Secundaria con esta incluida :");

    for(; i < f ; i++)
    {
        printf("\n\t\t\t[\t");

        for(e=0; e<=(f-1)- i; e++)
        {
            printf("%d\t",m1[i][e]);
        }

        for(g=e; g < f; g++)
        {
            printf(" \t");
        }
        printf("]");
    }
}
void mostrar_triangulo_superior_a_la_diag_secundaria(int m1[][TAM],int f,int c)
{
    int i = 0;
    int e;
    int g;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nTriangulo Superior a la diagonal Secundaria sin esta incluida :");

    for(; i < f ; i++)
    {
        printf("\n\t\t\t[\t");

        for(e=0; e<(f-1)- i; e++)
        {
            printf("%d\t",m1[i][e]);
        }

        for(g=e; g < f; g++)
        {
            printf(" \t");
        }
        printf("]");
    }
}
void mostrar_triangulo_inferior_a_la_diag_secundaria_con_diag_principal(int m1[][TAM],int f,int c)
{
    int i = 0;
    int e;
    int g;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nTriangulo Inferior a la diagonal Secundaria con esta incluida :");

    for(; i < f ; i++)
    {
        printf("\n\t\t\t[\t");

        for(g=0; g < (f-1)- i; g++)
            printf(" \t");

        for(e=(f-1)- i; e < f; e++)
            printf("%d\t",m1[i][e]);

        printf("]");
    }
}
void mostrar_triangulo_inferior_a_la_diag_secundaria(int m1[][TAM],int f,int c)
{
    int i = 0;
    int e;
    int g;

    ES_MATRIZ_CUADRADA(f,c)

    printf("\nTriangulo Inferior a la diagonal Secundaria sin esta incluida :");

    for(; i < f ; i++)
    {
        printf("\n\t\t\t[\t");

        for(g=0; g <= (f-1)- i; g++)
            printf(" \t");

        for(e=f- i; e < f; e++)
            printf("%d\t",m1[i][e]);

        printf("]");
    }
}

void mostrar_delta_1_matriz(int m1 [][TAM],int f,int c)
{
    int i = 0;
    int e = i;
    int g,h;

     printf("\nDelta 1 es :\t\t");
    for(; i < (f-2)-1;i++)
    {
        printf("\n\t\t\t[\t");

        for(g = 0; g < i+1 ; g++)
            printf(" \t");
        for(e=i+1 ; e < (f-1) - i;e ++)
        {
            printf("%d\t",m1[i][e]);
        }
        for(h = e; h < f ; h++)
            printf(" \t");
        printf("]");
    }
    for(i; i < f; i++)
    {
        printf("\n\t\t\t[\t");
        for(e=0 ; e < f;e ++)
        {
            printf(" \t");
        }
        printf("]");
    }
}
void mostrar_delta_1_matriz_mas_diagonal_principal(int m1 [][TAM],int f,int c)
{
    int i = 0;
    int e = i;
    int g,h;

     printf("\nDelta 1 mas diagonales es :\t\t");
    for(; i < (f-1)-1;i++)
    {
        printf("\n\t\t\t[\t");
        for(g = 0; g < i ; g++)
            printf(" \t");
        for(e=i ; e < f - i;e ++)
        {
            printf("%d\t",m1[i][e]);
        }
        for(h = e; h < f ; h++)
            printf(" \t");
        printf("]");
    }
    for(i; i < f; i++)
    {
        printf("\n\t\t\t[\t");
        for(e=0 ; e < f;e ++)
        {
            printf(" \t");
        }
        printf("]");
    }
}

void mostrar_delta_2_matriz(int m1 [][TAM],int f,int c)
{
    int i = 0;
    int e = i;
    int g,h;

    printf("\nDelta 2 es :\t\t");



}
