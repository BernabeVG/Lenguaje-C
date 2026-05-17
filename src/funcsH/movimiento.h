#pragma once
#include "../funcsH/Jugador.h"
int movimientoValido(int pos, char *espacios, Jugador p );
int fichaValida(int pos, char *espacios, Jugador p);
int verGanador(const char *espacios);
int validarDesplazamiento(int origen, int destino, char *espacios);