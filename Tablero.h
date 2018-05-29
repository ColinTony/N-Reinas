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
	unsigned int posX;
	unsigned int posY;
	boolean valido; 
}reina;

// Estructura del tablero , contiene las reinas en el
typedef struct tablero
{
	int nReinas;	// numero de reinas
	unsigned int tablero[TAM_MAX][TAM_MAX];	// fila y columna
	reina reinas[TAM_MAX];
	boolean isResuleto;	// Bandera

}tablero;

void initTablero(tablero *t);	// funcion para iniciar el tablero
void Resolver(tablero *t);		// inicia a Resolver el tablero