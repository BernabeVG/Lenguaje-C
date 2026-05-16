#pragma once
#include <stdlib.h>
typedef struct 
{
    char simbol;
    int numFichas;
}Jugador;

void turnoJugador(char *espacios, char jugador);
int verificarGanador(char *espacios, char jugador, char jugador2);
int verificarEmpate(char *espacios);
int verificarBloqueo(char *espacios, char simboloActual);