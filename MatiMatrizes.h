#ifndef MATIMATRIZES_H_INCLUDED
#define MATIMATRIZES_H_INCLUDED

#define TAM 5
#define ES_MATRIZ_CUADRADA(a,b) if(a != b){ printf("\nLa matriz Ingresada no es cuadrada por lo que no se puede realizar la accion requerida."); return;}

void producto_de_matrizes(int m1[][TAM],int m2[][TAM],int fm1,int cm1fm2,int cm2, int m3[][TAM]);// m3 debe ser de tamaño fm1 x cm2
void mostrar_matriz( int ** m1,int fm1,int cml);
//--------------------------------DIAGONAL PRINCIPAL-----------------------------------------------//
void mostrar_diagonal_principal_matriz(int m1[][TAM],int f,int c);
void obtener_diagonal_principal_matriz(int * vec,int * tamVec,int ml[][TAM],int f, int c);
void mostrar_triangulo_superior_a_la_diag_principal_con_diag_principal(int m1[][TAM],int f,int c);
void mostrar_triangulo_superior_a_la_diag_principal(int m1[][TAM],int f,int c);
void mostrar_triangulo_inferior_a_la_diag_principal_con_diag_principal(int m1[][TAM],int f,int c);
void mostrar_triangulo_inferior_a_la_diag_principal(int m1[][TAM],int f,int c);
//--------------------------------DIAGONAL SECUNDARIA----------------------------------------------//
void mostrar_diagonal_secundaria_matriz(int m1[][TAM],int f,int c);
void obtener_diagonal_secundaria_matriz(int * vec,int * tamVec,int ml[][TAM],int f, int c);
void mostrar_triangulo_superior_a_la_diag_secundaria_con_diag_principal(int m1[][TAM],int f,int c);
void mostrar_triangulo_superior_a_la_diag_secundaria(int m1[][TAM],int f,int c);
void mostrar_triangulo_inferior_a_la_diag_secundaria_con_diag_principal(int m1[][TAM],int f,int c);
void mostrar_triangulo_inferior_a_la_diag_secundaria(int m1[][TAM],int f,int c);
//-------------------------------TRIANGULOS DE LA MATRIZ------------------------------------------//
void mostrar_delta_1_matriz(int m1 [][TAM],int f,int c);
void mostrar_delta_1_matriz_mas_diagonal_principal(int m1 [][TAM],int f,int c);
void mostrar_delta_2_matriz(int m1 [][TAM],int f,int c);
void mostrar_delta_2_matriz_mas_diagonal_principal(int m1 [][TAM],int f,int c);
void mostrar_delta_3_matriz(int m1 [][TAM],int f,int c);
void mostrar_delta_3_matriz_mas_diagonal_principal(int m1 [][TAM],int f,int c);
void mostrar_delta_4_matriz(int m1 [][TAM],int f,int c);
void mostrar_delta_4_matriz_mas_diagonal_principal(int m1 [][TAM],int f,int c);
#endif // MATIMATRIZES_H_INCLUDED
