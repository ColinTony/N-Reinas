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
	setColor(GREEN);
	printf("PROBELMA DE LAS N-REINAS CON N = %i",t->nReinas);
	setColor(WHITE);
	puts(" "); // salto de linea
	system("Pause");// ingresa una tecla para continuar
	
	MoverCursor((t->nReinas)*2,(t->nReinas)*2);	// Colocamos el titulo en la parte inferior del tablero
}