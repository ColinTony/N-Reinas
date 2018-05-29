/*
IMPLEMENTACIONES DE TABLERO
AUTOR: COLIN HEREDIA LUIS ANTONIO
VERSIÓN: 1.3

DESCRIPCIÓN: en esta parte vamos a definir las funciones que tendra el tablero
verificar las posiciones , el tamaño del tablero , todo lo relacionado 
al juego de las nReinas

OBSERVACIONES: El tablero se generara de 4<n<10

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // para los calculos de restas con valores absolutos
#include "Tablero.h"
#include "Presentacion.h"
#include "Dibujar.h"

/*
	void initTablero(Tablero *t)
	Descripción: Se dibujara el tablero de nxn
	Devuelve: Void
	Observaciones: solo debe permitir valores entre 4<n<10
*/
void initTablero(tablero *t)
{
	if(t->nReinas < 4 || t->nReinas > 10){
		puts("DEBES ELEGIR UN VALOR DE 4 < N < 10");
		exit(0);
	}
	DibujarTablero(t->nReinas); // dibujamos al tablero
	MoverCursor((t->nReinas)*2,(t->nReinas)*2);	// Colocamos el titulo en la parte inferior del tablero
	printf("PROBELMA DE LAS N-REINAS CON N = %i",t->nReinas);
	setColor(CYAN);
	dibujaBorraR(1,1,FALSE);
	puts(" "); // salto de linea
	MoverCursor((t->nReinas)*2,(t->nReinas)*2);	// Colocamos el titulo en la parte inferior del tablero
	system("Pause");// ingresa una tecla para continuar
	Resolver(t);
}
/*
	void resolver(Tablero *t)
	Descripción: Se empiezan a dibujar las reinas y a solucionar el problema
	Devuelve: Void
	Observaciones: solo debe permitir valores entre 4<n<10
*/
void Resolver(tablero *t)
{
	int i; // contador
	int j; // contador 
	int columP=1; // columna donde se empieza
	// probando 
	MoverCursor((t->nReinas)*2,(t->nReinas)*2);	// Colocamos el titulo en la parte inferior del tablero
	system("Pause");// ingresa una tecla para continuar
}

boolean isOk(tablero *t,int reinaN)
{
	boolean ok=FALSE;
	// verificamos fila

	return	ok; 
}

boolean okFila(tablero *t,int reinaN)
{
	boolean ok=FALSE;
	reina r= t->reinas[reinaN]; // colocamos la reina a revisar
	int i; // contador
	// Para validar la fila debemos comprobar que solo
	// existe una reina puesta en esa fila
	for(i = 0; i<=t->nReinas; i++) // si alguna de las reinas se encuentra en la misma fila mandamos FALSE
	{
		// Verificando cada reina con la nueva que se poindra
		if(r.posY == t->reinas[i].posY) // revisando cada reina colocada
			ok = FALSE;// si es igual entonces no se puede poner
		else
			ok = TRUE;	// si no es igual entonces la posicion es valida
	}
	return ok;
}

boolean okColumna(tablero *t,int reinaN)
{
	boolean ok=FALSE;
	reina r = t->reinas[reinaN]; // colocamos la reina a revisar
	int i; // contador
	// Para validar la columna debemos comprobar que solo
	// existe una reina puesta en esa columna
	for(i = 0; i<=t->nReinas; i++) // si alguna de las reinas se encuentra en la misma columna mandamos FALSE
	{
		// Verificando cada reina con la nueva que se poindra
		if(r.posX == t->reinas[i].posX) // revisando cada reina colocada
			ok = FALSE;// si es igual entonces no se puede poner
		else
			ok = TRUE;	// si no es igual entonces la posicion es valida
	}
	
	return ok;
}
/*
	boolean okDiagonal(tablero *t,int reinaN)
	Descripción: Esta funcion verfifica si la reina que se quiere poner esta en 
	posicion correcta. Verifica las diagolaes para saber si la reina esta bien colocada
	diagonalmente , tenemos la condicion de que si la diferencia entre el numero de fila
	y el numero de la columna es igual a la de otra reina , entonces se encuentran en 
	la misma diagonal
*/
boolean okDiagonal(tablero *t,int reinaN)
{
	boolean ok;
	int i; // contador 
	// reina a verficar
	reina r = t->reina[reinaN];
	// valor de la diagonal de la reina
	int rValor = r. 
	return ok;
}
