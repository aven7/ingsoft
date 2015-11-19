#pragma once
#include "Juego.h"
#include "Enemigo.h"
#include "Render.h"
#include "Bala.h"

int posBalaIzq = 0;
int posBalaDer = 0;
bool existeBalaDer = false;
bool existeBalaIzq = false;
const int anchuraMax = 70;
bool existeMalo = false;
int posMaloDer = 0;
int posMaloIzq = 0;
bool maloIzq = false;
bool maloDer = false;
int puntos = 0;
bool finJuego = false;
int posPlayer = anchuraMax / 2;