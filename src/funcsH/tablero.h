#pragma once

typedef struct
{
    char espacios[9];
}Tablero;

void inicializarTablero(char *espacios);
void dibujarTablero(char *espacios, int lineaGanadora);
void opPos();
