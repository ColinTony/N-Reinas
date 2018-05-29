/*
	EQUIPO: Colin
	DESCRIPCION: Este archivo contiene la funcion principal main , Se solucionara el problema de las n reinas
	de manera "Grafica" usando los caracteres. 

	OBSERVACIONES: Se le pedira al usuario un tamaño de tablero de 4<n<10 esto es por cuestiones de diseño

	Compilacion : ejecutar el compilar.bat o hacerlo desde consola con gcc Practicas.c Dibujar.c Presentacion.c -o Practica05 
*/
// Esta funcion solo nos dira si el usuario quiere continuar en el menu o ya no
#include <stdio.h>
#include <stdlib.h>
#include "Tablero.h"
#include "Dibujar.h"

boolean isContinue()
{
	boolean isContinue = FALSE; // saber si quiere continuar en el menu 
	int opc;
	puts("\n \n \n Teclea la opcion que desees");
	printf("Deseas regresar al menu de recursividad? \n 1-.SI \n 2-.NO \n");
	scanf("%i",&opc);
	// si quisi continuar se cambia a verdaero
	if(opc == 1)
		isContinue=TRUE; // si es 1 entonces quiere continuar , si no se mantiene en FASLE

	return isContinue; // regresamos
}
int main()
{
	tablero tablero;

	/* code */
	puts("----------------------BIENVENIDO AL PROBLEMA DE LAS N-REINAS---------------------");
	puts("Ingrese el numero de reinas : ");
	scanf("%i",&tablero.nReinas);
	initTablero(&tablero);
	return 0;
}