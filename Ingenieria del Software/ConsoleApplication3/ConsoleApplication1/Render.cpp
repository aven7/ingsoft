#include "stdafx.h"
#include <stdio.h>
#include "Render.h"



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
			if (i != posMaloIzq && i != posBalaIzq)
				printf_s("_");
		}
		else
			printf_s("_");
	}
}

void pintParteDer() {
	for (int x = posPlayer + 1; x < anchuraMax; x++) {
		if (existeBalaDer || maloDer) {
			if (existeBalaDer && x == posBalaDer) {
				//x++;
				printf_s(">");
			}
			if (maloDer && x == posMaloDer) {
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
	printf_s("  %d", puntos);
	printf("\r");
}