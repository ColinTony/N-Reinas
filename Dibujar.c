/*
	Libreria ? : Dibujar
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se define el funcionamiento de las funciones para dibujar el tablero
	y para dibujar una reina en el tablero
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Presentacion.h"
#include "Dibujar.h"

/*
	void DibujarTablero(Tablero *t)
	Descripción: Se dibujara el tablero de nxn
	Recibe: Recibe el numero de lado por lado que tendra el tablero y el numero de reinas
	el cual es el mismo
	Devuelve: Void
	Observaciones: solo debe permitir valores entre 4<n<10
*/
void DibujarTablero(int n)
{
	int i,j;// contadores
	setColor(DARKGRAY); // cambiamos el color
	BorrarPantalla();
	int tablero [n][n];
	// Dibujamos el tablero
	for(i=0; i<n; i++)
	{
		for(j = 0; j<n; j++)
		{
			// si el tablero es mayor a cero
			if(tablero[i][j]>0)
				printf("      |");
			else
				printf("      |");
		}
		puts(" "); // saltamos de linea
		for(int j=0; j<n; j++)
			printf("------+"); // imprimimos las lineas
        puts(" ");
	}

}

/*
	void dibujaBorraR(int fila,int columna,boolean erase)
	Descripción: Dibuja una reina o borra una reina del tablero
	Recibe:  int fila , columna de la posicion a colocar o borrar, si el parametro erase es
	TRUE encotences se borra la reina en vez de colocarla
	Devuelve: void.
	Observacion: Para pintar en el tablero debemos tomar en cuenta las distancias
	cada columna cuenta con 7 espacios , entonces para movernos en las columnas hay que multimplicar
	la columna por 7 , para centrar el numero dentro de la columna solo hay que sumar 3 o 2 , en
	nuetro caso sumaremos 3.
	PRa el caso de las columnnas caen en las lineas cada numero impar 1,3,5,7 ... lo cual solo hay que restar
	uno al numero de la posicion. Asi llegamos al centro de donde nos quiso dar la posicion
*/
void dibujaBorraR(int fila,int columna,boolean erase)
{
	fila--;
	columna--;
	// arreglo para bajar entre las columnas
	// como son numeros impares los guardaremos en el array par ano calcularlos
	// esto nos el valor dado nos dira el valor correspondiente a su casilla que quiere poner
	// con esto solo debemos sumarle 1 y estarmamos en la posicion dada
	int posY[9] = {1,3,5,7,9,11,13,15,17};
	if(!erase)
	{
		// pintamos la reina
		if(fila == 0 && columna == 0) // si la posicion que se desea es la 1,1 
		{
			// no debemos multiplicar ya que es la primera posicion
			MoverCursor(3,0);
			printf("Q");// pintamos reinas
		}else
		{
			if(fila == 0)
			{
				MoverCursor((columna*7)+3,0);
				setColor(DARKBLUE);
				printf("Q");// pintamos reinas
				return;
			}

			if(columna == 0)
			{
				MoverCursor(3,posY[fila]-1);
				setColor(DARKBLUE);
				printf("Q");// pintamos reinas
				return;
			}
			// si ya no se puede symar entonces imprimimos
			MoverCursor((columna*7)+3,posY[fila]-1);
			setColor(DARKBLUE);
			printf("Q");// pintamos reinas
		}
	}else
	{
		// Borramos la reina
		// pintamos la reina
		if(fila == 0 && columna == 0) // si la posicion que se desea es la 1,1 
		{
			// no debemos multiplicar ya que es la primera posicion
			MoverCursor(3,0);
			printf(" ");// pintamos reinas
		}else
		{
			if(fila == 0)
			{
				MoverCursor((columna*7)+3,0);
				printf(" ");
				return;
			}

			if(columna == 0)
			{
				MoverCursor(3,posY[fila]-1);
				printf(" ");
				return;
			}
			// si ya no se puede symar entonces imprimimos
			MoverCursor((columna*7)+3,posY[fila]-1);
			printf(" ");// pintamos reinas
		}
	}
}
/*
	void setColor(int valorColor)
	Descripción: Cambia el color del texto a imprimir en pantalla
	Recibe:  int con el valor del color deseado
	Devuelve: void.
	Observaciones : En este metodo se utilizan tipos de datos de la api de Windows
*/
void setColor(int valorColor)
{
	HANDLE hOut; // No tengo idea que haga el HANDLE , busque informacion y no se como funciona.

    //La función GetStdHandle devuelve un manipulador para el dispositivo estándar de entrada, salida o error.
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); // dispositivo input, output o error (hexadecimal) vmaos a manipular la salida
 	// Establece los atributos de los caracteres escritos en el búfer de la pantalla de la consola mediante la función WriteFile o WriteConsole
 	// o repetidos por la función ReadFile o ReadConsole. Esta función afecta el texto escrito después de la llamada a la función.
    SetConsoleTextAttribute(hOut,valorColor); // le mandamos el puntero hacia el valor del color
    // Descripcion los codigos para los colores
    /*
    * 0x000 son punteros para los valores de los colores
    *FOREGROUND_BLUE 0x0001  color AZUL.
	*FOREGROUND_GREEN 0x0002 color VERDE.
	*FOREGROUND_RED 0x0004	color ROJO.
	*FOREGROUND_INTENSITY 0x0008 intensidad de color.
	BACKGROUND_BLUE 0x0010	ponemos un fondo azul
	* informacion obtenida de la documentacion de Windows https://docs.microsoft.com/en-us/windows/console/char-info-str
    */
}