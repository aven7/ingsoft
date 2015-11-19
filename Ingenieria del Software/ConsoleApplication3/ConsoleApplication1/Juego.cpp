
#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include "Juego.h"


void muerte() {
	/*if (existeMalo) {
		if (posMaloDer == posPlayer + 1 || posMaloDer == posPlayer)
			finJuego = true;

		if (posMaloIzq == posPlayer - 1 || posMaloIzq == posPlayer)
			finJuego = true;
	}*/
}

void movimientoMaloBala(){
	if (existeBalaDer){
		posBalaDer++;
	}
	if (existeBalaIzq){
		posBalaIzq--;
	}
	if (maloDer){
		posMaloDer--;
	}
	if (maloIzq) {
		posMaloIzq++;
	}
}

void botones() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a': case 'A':
			if (posPlayer>0){
				posPlayer--;
			}
			break;
		case 'd': case'D':
			if (posPlayer<anchuraMax - 1){
				posPlayer++;
			}
			break;
		case 'q': case'Q':
			if (!existeBalaIzq && !existeBalaDer) {
				existeBalaIzq = true;
				posBalaIzq = posPlayer -1;
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
}
