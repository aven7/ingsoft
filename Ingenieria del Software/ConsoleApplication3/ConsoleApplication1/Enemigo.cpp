#include "stdafx.h"
#include "Enemigo.h"
#include <Windows.h>


void muerteMalo() {
	if (posBalaDer == posMaloDer || posBalaDer == posMaloDer + 1) {
		existeBalaDer = false;
		posBalaDer = -1;
		posMaloDer = -5;
		puntos += 5;
		maloDer = false;
	}
	if (posBalaIzq == posMaloIzq || posBalaIzq == posMaloIzq - 1) {
		existeBalaIzq = false;
		posMaloIzq = -5;
		posBalaIzq = -1;
		puntos += 5;
		maloIzq = false;
	}
	if (!maloIzq && !maloDer)
		existeMalo = false;
}

void saleMalo() {
	int randomMalo = rand() % 5 + 1;

	if (randomMalo == 1 && !maloDer) {
		posMaloDer = anchuraMax - 1;
		maloDer = true;
		existeMalo = true;
	}
	else if (randomMalo == 2 && !maloIzq) {
		posMaloIzq = 1;
		maloIzq = true;
		existeMalo = true;
	}
}