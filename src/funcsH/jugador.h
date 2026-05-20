#pragma once
#include <stdlib.h>
typedef struct 
{
    char simbolo;
    int numFichas;
}Jugador;

Jugador* CrearTablaPosiciones();
void inicializarFichas(Jugador *p1, Jugador *p2);
void turnoJudador(char *espacios, Jugador p, int tipo, int org);
void moverFichaPuesta(char *espacios, Jugador p);
