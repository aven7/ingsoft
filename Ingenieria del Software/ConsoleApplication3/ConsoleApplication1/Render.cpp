#include "stdafx.h"
#include <stdio.h>
#include "Render.h"
#include <Windows.h>

bool existeGota = false;
char** gotas;
int posGota;
int cuantasGotas;
const char estado1 = 'J';
const char estado2 = 'P';
const char estado3 = 'h';
int estadoGota = 0;

void crearGotas() {
	cuantasGotas = rand() % anchuraMax;
	for (int i = 0; i <= cuantasGotas; i++) {
		posGota = rand() % anchuraMax;
		gotas[i][0] = true;
		gotas[i][1] = estado1;
	}
}

void pintarGota(int i) {
	printf_s("%c", gotas[i][1]);
}

void pintParteIzq() {
	for (int i = 0; i < posPlayer; i++) {
		//if (existeBalaIzq || maloIzq) {
			if (existeBalaIzq && i == posBalaIzq) {
				printf_s("<");
			}else if(maloIzq && i == posMaloIzq) {
				printf_s("H");
			/*}else if (existeGota && i == posGota) {
				pintarGota(i);*/
			}else if(i != posMaloIzq && i != posBalaIzq){
				printf_s("_");
			}
		//}
		//else
		//	printf_s("_");
	}
}

void pintParteDer() {
	for (int x = posPlayer + 1; x < anchuraMax; x++) {
		//if (existeBalaDer || maloDer) {
			if (existeBalaDer && x == posBalaDer) {
				printf_s(">");
			}
			if (maloDer && x == posMaloDer) {
				printf_s("H");
			}
			if (x != posMaloDer && x != posBalaDer){
				printf_s("_");
			}
		//}
		//else {
		//	printf_s("_");
		//}
	}
}

void pintarPantallaCompleta() {
	pintParteIzq();
	printf_s("X");
	pintParteDer();
	printf_s("  %d", puntos);
	printf_s("\r");
}