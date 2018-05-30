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
#include <stdlib.h> // contiene la funcion abs() Obtenemos el valor absoluto
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
	// probando verficacdor
	
	// primera reina
	dibujaBorraR(2,4,FALSE);
	t->reinas[0].posX = 4;
	t->reinas[0].posY = 2;
 	
 	// segunda reina
	dibujaBorraR(2,3,FALSE);
	t->reinas[1].posX = 3;
	t->reinas[1].posY = 2;

	// TERCERA REINA 2
	dibujaBorraR(5,1,FALSE); // primero fila , luego columna
	t->reinas[2].posY = 5;
	t->reinas[2].posX = 1;

	isOk(t,2);

	MoverCursor((t->nReinas)*2,(t->nReinas)*2);	// Colocamos el titulo en la parte inferior del tablero
	system("Pause");// ingresa una tecla para continuar
}

boolean isOk(tablero *t,int reinaN)
{
	boolean ok=FALSE;

	// verificamos fila
	if(okFila(t,reinaN))
	{
		MoverCursor(80,0);
		EsperarMiliSeg(250);
		printf("VALIDA EN FILA");
	}
	else
	{
		MoverCursor(80,0);
		EsperarMiliSeg(250);
		printf("INVALIDA EN FILA");
	}

	if(okColumna(t,reinaN))
	{
		MoverCursor(80,1);
		EsperarMiliSeg(250);
		printf("VALIDA EN COLUMNA");
	}
	else
	{
		MoverCursor(80,1);
		EsperarMiliSeg(250);
		printf("INVALIDA EN COLUMNA");
	}

	if(okDiagonal(t,reinaN))
	{
		MoverCursor(80,2);
		EsperarMiliSeg(250);
		printf("VALIDA EN DIAGONAL");
	}
	else
	{
		MoverCursor(80,2);
		EsperarMiliSeg(250);
		printf("INVALIDA EN DIAGONAL");
	}

	return	ok; 
}


/*
	boolean okFila(tablero *t,int reinaN)
	Descripción: Esta funcion verifica si la posicion en la que esta
	queriendo colocar la reina es valida en las filas , si alguna de las reinas
	antes colocadas se encuentra en la fila que deseamos colocar la reina
	Recibe: tablero que contiene las reinas puestas , numero de la reina a colocar
	Devuelve : TRUE si la posicion en la que se intenta colocar es valida
*/
boolean okFila(tablero *t,int reinaN)
{
	boolean ok=TRUE;
	reina r= t->reinas[reinaN]; // colocamos la reina a revisar
	int i; // contador
	// Para validar la fila debemos comprobar que solo
	// existe una reina puesta en esa fila
	for(i = 0; i<reinaN; i++) // si alguna de las reinas se encuentra en la misma fila mandamos FALSE
	{
		// Verificando cada reina con la nueva que se poindra
		if(r.posY == t->reinas[i].posY) // revisando cada reina colocada
			ok = FALSE;// si es igual entonces no se puede poner
	}
	return ok;
}
/*
	boolean okColumna(tablero *t,int reinaN)
	Descripción: Esta funcion verifica si la posicion en la que esta
	queriendo colocar la reina es valida en las columnas
	Recibe: tablero que contiene las reinas puestas , numero de la reina a colocar
	Devuelve : TRUE si la posicion en la que se intenta colocar es valida
*/
boolean okColumna(tablero *t,int reinaN)
{
	boolean ok=TRUE;
	reina r = t->reinas[reinaN]; // colocamos la reina a revisar
	int i; // contador
	// Para validar la columna debemos comprobar que solo
	// existe una reina puesta en esa columna
	for(i = 0; i<reinaN; i++) // si alguna de las reinas se encuentra en la misma columna mandamos FALSE
	{
		// Verificando cada reina con la nueva que se poindra
		if(r.posX == t->reinas[i].posX) // revisando cada reina colocada
			ok = FALSE;// si es igual entonces no se puede poner
	}
	
	return ok;
}
/*
	boolean okDiagonal(tablero *t,int reinaN)
	Descripción: Esta funcion verfifica si la reina que se quiere poner esta en 
	posicion correcta. Verifica las diagolaes para saber si la reina esta bien colocada
	diagonalmente , tenemos la condicion de que si la diferencia entre el numero de fila
	y el numero de la columna es igual a la de otra reina , entonces se encuentran en 
	la misma diagonal y pasa lo mismo con la suma de la fila y columna 
*/
boolean okDiagonal(tablero *t,int reinaN)
{
	boolean ok = TRUE;
	int i; // contador 
	int otraReina; // valor de la resta de las demas reinas
	// reina a verficar
	reina r = t->reinas[reinaN];
	// valor de la diagonal de la reina
	int rValor = r.posX + r.posY;
	int rValorNeg = r.posY - r.posX;
	for(int i = 0; i < reinaN; i++)
	{
		otraReina = (t->reinas[i].posX + t->reinas[i].posY);
		if(rValor == otraReina)
			ok = FALSE;// si son iguales entonces estan en la misma diagonal
		otraReina = (t->reinas[i].posY - t->reinas[i].posX);
		if(rValorNeg == otraReina)
			ok=FALSE; // como la resta de la fila y la columna son lo mismo entonces
	}
	return ok;
}
