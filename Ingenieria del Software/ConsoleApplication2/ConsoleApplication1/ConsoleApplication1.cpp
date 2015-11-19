// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

bool existeBalaDer = false, existeBalaIzq = false;
const int anchuraMax = 70;
int posPlayer = anchuraMax / 2;
int posBalaIzq = -10, posBalaDer = 10;
int posMaloDer = -5, posMaloIzq = -5;
bool maloDer = false, maloIzq = false;
bool finJuego = false;
bool existeMalo = false;
int puntos=0;

void pintParteIzq() {
	for (int i = 0; i < posPlayer; i++) {
		if (existeBalaIzq || maloIzq) {
			if (existeBalaIzq && i == posBalaIzq) {
				//i++; POR SI TIENE 2 CARACTERES la bala
				printf_s("<");
			}
			if (maloIzq && i == posMaloIzq) {
				printf_s("H");
			}
			if(i != posMaloIzq && i != posBalaIzq)
				printf_s("_");
		}
		else
			printf_s("_");
	}
}

void pintParteDer() {
	for (int x = posPlayer + 1; x < anchuraMax; x++) {
		if (existeBalaDer||maloDer) {
			if (existeBalaDer && x == posBalaDer) {
				//x++;
				printf_s(">");
			}
			if(maloDer && x== posMaloDer){
				printf_s("H");
			} 
			if (x != posMaloDer && x != posBalaDer)
				printf_s("_");
		}
		else
			printf_s("_");
	}
}

void pintarPantallaCompleta() {
	pintParteIzq();
	printf("X");
	pintParteDer();
	printf_s("  %d",puntos);
	printf("\r");
}

int main()
{
	printf("\n\n\n\n\n\n\n\n\n");
	//LOOP juego
	while (!finJuego) {
		
		//Sale malo y elige lugar
		int randomMalo= rand() % 5 +1;

			if (randomMalo == 1 && !maloDer) {
				posMaloDer = anchuraMax - 1;
				maloDer = true;
				existeMalo = true;
			}
			else if (randomMalo == 2 && !maloIzq){
				posMaloIzq = 1;
				maloIzq = true;
				existeMalo = true;
			}
		//Muerto
		if (existeMalo){
			if (posMaloDer == posPlayer+1|| posMaloDer == posPlayer)
				finJuego =true;

			if (posMaloIzq == posPlayer-1 || posMaloIzq == posPlayer)
				finJuego =true;
		}
		
		//Malo muerto
		if (posBalaDer == posMaloDer || posBalaDer == posMaloDer+1) {
			existeBalaDer = false;
			posBalaDer = -1;
			posMaloDer = -5;
			puntos += 5;
			maloDer = false;
		}
		if (posBalaIzq == posMaloIzq || posBalaIzq == posMaloIzq-1) {
			existeBalaIzq = false;
			posMaloIzq = -5;
			posBalaIzq = -1;
			puntos += 5;
			maloIzq = false;
		}
		if (!maloIzq && !maloDer)
			existeMalo = false;
		
		//Balas no salgan de mundo
		if (posBalaDer >= anchuraMax-1)
			existeBalaDer = false;
		if (posBalaIzq <= 0)
			existeBalaIzq = false;
		


		pintarPantallaCompleta();
		
		if (existeBalaDer)
			posBalaDer++;
		if (existeBalaIzq)
			posBalaIzq--;
		if (maloDer)
			posMaloDer--;
		if (maloIzq)
			posMaloIzq++;
		
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
					if(!existeBalaIzq && !existeBalaDer){
						existeBalaIzq = true;
						posBalaIzq = posPlayer - 1;
					}
					break;
				case 'w': case'W':
					if (!existeBalaDer && !existeBalaIzq) {
						existeBalaDer = true;
						posBalaDer = posPlayer + 1;
					}
					break;
				default:
					break;
			}
		}
		Sleep(100);
	}
	printf_s("||||||||||||||||||||||||||||||| GAME OVER |||||||||||||||||||||||||||||||");
	getchar();
    return 0;
}