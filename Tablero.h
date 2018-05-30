/*
	Libreria  : Tablero
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Este cabercera es el tablero principal el cual contiene sus dimensiones
	el numero de reinas que tendra y tendra las funciones para determinar si se encuentra
	resuleto el problema de las nReinas. Contendra la funcion que resolvera el problema.

*/

//DEFINICIONES DE CONSTANTES
#define TRUE	1
#define FALSE	0
#define TAM_MAX 10 //Tamaño maximo del tablero

//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

// Estructura de la reina. contiene la posicion de cada reina y validacion
typedef struct reina
{
	int posX;
	int posY; 
	int numReina;
}reina;

// Estructura del tablero , contiene las reinas en el
typedef struct tablero
{
	int nReinas;	// numero de reinas
	reina reinas[TAM_MAX];
	boolean isResuelto;	// Bandera
	int reinaID;	// identificar las reinas colocadas
}tablero;

void initTablero(tablero *t);	// funcion para iniciar el tablero
boolean Resolver(tablero *t);		// inicia a Resolver el tablero
boolean isOk(tablero *t,int reinaN);		// validar la posicion de la reina
boolean okFila(tablero *t,int reinaN);		// validamos posicion en la fila
boolean okColumna(tablero *t,int reinaN);	// validamos la posicion en columna
boolean okDiagonal(tablero *t, int reinaN);	// validamos la diagonal