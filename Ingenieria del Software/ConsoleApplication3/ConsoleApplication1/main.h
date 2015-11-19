#pragma once
#include "Juego.h"
#include "Enemigo.h"
#include "Render.h"
#include "Bala.h"

int posBalaIzq = -10;
int posBalaDer = 10;
bool existeBalaDer = false;
bool existeBalaIzq = false;
const int anchuraMax = 70;
bool existeMalo = false;
int posMaloDer = -5;
int posMaloIzq = -5;
bool maloIzq = false;
bool maloDer = false;
int puntos = 0;
bool finJuego = false;
int posPlayer = anchuraMax / 2;