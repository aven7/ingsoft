// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

#include "main.h"

int main()
{
	printf("\n\n\n\n\n\n\n\n\n");
	//LOOP juego
	while (!finJuego) {

		//Sale malo y elige lugar
		saleMalo();
		//Muerto
		muerte();
		//Malo muerto
		muerteMalo();
		//Balas no salgan de mundo
		saleBalaMundo();
		//pintamos mundo
		pintarPantallaCompleta();
		//movimientos
		movimientoMaloBala();
		//bubleJuego
		botones();
		
		Sleep(100);
	}
	printf_s("||||||||||||||||||||||||||||||||| GAME OVER |||||||||||||||||||||||||||||||");
	getchar();
	return 0;
}