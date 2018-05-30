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
	t->reinas[0].posY = 1;
	t->reinas[0].posX = 1;
	t->reinaID = 0; // con este valor identificamos las reinas colocadas
	Resolver(t); // mandamos la primer reina
}
/*
	void resolver(Tablero *t)
	Descripción: Se empiezan a dibujar las reinas y a solucionar el problema
	REcibe : Tablero y la reina en la cual se quedo
	Devuelve: Void
	Observaciones: solo debe permitir valores entre 4<n<10
*/
boolean Resolver(tablero *t)
{
	int i; // contador
	boolean correcto=FALSE;
	int fila,colum;
	colum = t->reinaID+1; // la columna en donde vamos
	t->isResuelto = FALSE; // no se ha isResuelto
	// probando verficacdor
	while(t->isResuelto == FALSE)
	{
		if((t->reinaID)+1 == t->nReinas)
			t->isResuelto = TRUE; // ya no quedan reinas que coloca
		else{

			for(fila = 1; fila<=t->nReinas; fila++)
			{
				// si se puede colocar entonces la ponemos
				if(isOk(t, t->reinaID))
				{
					//MoverCursor(80,10+fila);
					//printf("contador : %i fila : %i , columna : %i , reina %i ",fila-1 ,fila,colum,t->reinaID);
					t->reinas[t->reinaID].posY = fila;
					t->reinas[t->reinaID].posX = colum;
					dibujaBorraR(fila,colum,FALSE);

					// reina siguiente
					t->reinaID++;
					t->reinas[t->reinaID].posY = 1;
					t->reinas[t->reinaID].posX = colum+1; // siguiente columna
					break;
				}
				else
				{
					MoverCursor(80,5+fila);
					printf("contador : %i fila : %i , columna : %i , reina %i ",fila-1 ,fila,colum,t->reinaID);
					// si  no es correcto el movimiento , entonces avanzamos en la fila
					dibujaBorraR(fila,colum,FALSE);
					EsperarMiliSeg(250);
					dibujaBorraR(fila,colum,TRUE);
					t->reinas[t->reinaID].posY = fila+1; // avanzamos en la fila
					t->reinas[t->reinaID].posX = colum;  // siguiente columna
				
				}
			}
			//MoverCursor(80,5+fila);
			//printf("finite incantatem ", fila,colum,t->reinaID);
			Resolver(t);
			t->isResuelto=TRUE;
		}
	}
	/*
		// primera reina 0
		dibujaBorraR(2,4,FALSE);
		t->reinas[0].posX = 4;
		t->reinas[0].posY = 2;
	 	
	 	// segunda reina 1
		dibujaBorraR(2,3,FALSE);
		t->reinas[1].posX = 3;
		t->reinas[1].posY = 2;

		// TERCERA REINA 2
		dibujaBorraR(5,6,FALSE); // primero fila , luego columna
		t->reinas[2].posY = 5;
		t->reinas[2].posX = 6;

		isOk(t,2);
	*/

	MoverCursor((t->nReinas)*2,(t->nReinas)*2);	// Colocamos el titulo en la parte inferior del tablero
	system("Pause");// ingresa una tecla para continuar
}
/*
	boolean isOk(tablero *t,int reinaN)
	Descripción: Verifica de en la fila , columna y la diagonal. Devuelve TRUE si es que 
	es valida la posicion
	Recibe: tablero que contiene las reinas puestas , numero de la reina a colocar
	Devuelve : TRUE si la posicion en la que se intenta colocar es valida
*/
boolean isOk(tablero *t,int reinaN)
{
	boolean ok=TRUE;

	// verificamos fila
	if(okFila(t,reinaN))
	{
		setColor(MAGENTA);
		MoverCursor(80,0);
		EsperarMiliSeg(250);
		printf("VALIDA EN FILA");
	}
	else
	{
		setColor(MAGENTA);
		MoverCursor(80,0);
		EsperarMiliSeg(250);
		printf("INVALIDA EN FILA");
		ok = FALSE;
	}

	if(okColumna(t,reinaN))
	{
		setColor(MAGENTA);
		MoverCursor(80,1);
		EsperarMiliSeg(250);
		printf("VALIDA EN COLUMNA");
	}
	else
	{
		setColor(MAGENTA);
		MoverCursor(80,1);
		EsperarMiliSeg(250);
		printf("INVALIDA EN COLUMNA");
		ok = FALSE;
	}

	if(okDiagonal(t,reinaN))
	{
		setColor(MAGENTA);
		MoverCursor(80,2);
		EsperarMiliSeg(250);
		printf("VALIDA EN DIAGONAL");
	}
	else
	{
		setColor(MAGENTA);
		MoverCursor(80,2);
		EsperarMiliSeg(250);
		printf("INVALIDA EN DIAGONAL");
		ok = FALSE;
	}
	setColor(CYAN);
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
	la misma diagonal y pasa lo mismo con la suma de la fila y columna. 
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
