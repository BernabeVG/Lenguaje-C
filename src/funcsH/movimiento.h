#pragma once
#include "jugador.h"
int movimientoValido(int pos, char *espacios, Jugador p );
int fichaValida(int pos, char *espacios, Jugador p);
int verGanador(const char *espacios);
int validarDesplazamiento(int origen, int destino, char *espacios);
char* agregarPosicion(char* historial, int* capActual, int* capacidad, const char* textoMovimiento);
void obtenerTextoPosicion(int opcionElegida, char* variableDestino);