// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

void pintParteIzq(int posPlayer, bool existeBalaIzq, int posBalaIzq) {
	for (int i = 0; i < posPlayer;i++) {
		if (existeBalaIzq) {
			if (i == posBalaIzq){
				i++;
				printf_s("<-");
			}
			else
				printf_s("_");
		}
		else
			printf_s("_");
	}
}

void pintParteDer(int posPlayer, bool existeBalaDer, int posBalaDer, int anchuraMax) {
	for (int x = posPlayer + 1; x < anchuraMax; x++) {
		if (existeBalaDer) {
			if (x == posBalaDer) {
				x++;
				printf_s("->");
			}
			else
				printf_s("_");
		}
		else
			printf_s("_");
	}
}

void pintarPantallaCompleta(int posPlayer, bool existeBalaDer, int posBalaDer, bool existeBalaIzq, int posBalaIzq, int anchuraMax) {
	pintParteIzq(posPlayer, existeBalaIzq, posBalaIzq);
	printf("X");
	pintParteDer(posPlayer, existeBalaDer, posBalaDer, anchuraMax);
	printf("\r");
}

int main()
{
	//Declaración de variables.
	bool existeBalaDer= false, existeBalaIzq = false;
	const int anchuraMax = 79;
	int posPlayer = anchuraMax/2;
	int posBalaIzq = 0, posBalaDer = 0;
	printf("\n\n\n\n\n\n\n\n\n");

	//LOOP juego
	while (true) {
		
		//Balas no salgan del mundo.
		if (posBalaDer >= anchuraMax-1)
			existeBalaDer = false;
		if (posBalaIzq <= 0)
			existeBalaIzq = false;
		
		pintarPantallaCompleta(posPlayer, existeBalaDer, posBalaDer, existeBalaIzq, posBalaIzq, anchuraMax);
		
		if (existeBalaDer)
			posBalaDer++;
		if (existeBalaIzq)
			posBalaIzq--;
		
		if (_kbhit()) {
			switch (_getch())
			{
				case 'a': case 'A':
					if (posPlayer>0)
						posPlayer--;
					break;
				case 'd': case'D':
					if (posPlayer<anchuraMax-1)
						posPlayer++;
					break;
				case 'q': case'Q':
					if(!existeBalaIzq){
						existeBalaIzq = true;
						posBalaIzq = posPlayer - 2;
					}
					break;
				case 'w': case'W':
					if (!existeBalaDer) {
						existeBalaDer = true;
						posBalaDer = posPlayer + 1;
					}
					break;
				default:
					break;
			}
		}
		Sleep(50);
	}
    return 0;
}