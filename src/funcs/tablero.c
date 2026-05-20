#include "../funcsH/tablero.h"
#include <stdio.h>

#include "../funcsH/jugador.h"

// Tablero Colores existentes
#define RESET      "\033[0m"
#define AMARILLO   "\033[43m"
#define GRANATE    "\033[41m"
#define NEGRITA    "\033[1m"

// NUEVO: Color para resaltar la combinación ganadora (Fondo Verde, Letra Negra y Negrita)
#define GANADOR    "\033[1;42;30m"

void inicializarTablero(char *espacios){
    for(int i = 0; i < 9; i++){
        *(espacios + i) = ' ';
    }
}


void dibujarTablero(char *espacios, int lineaGanadora)
{
    char *c0 = "", *c1 = "", *c2 = "", *c3 = "", *c4 = "", *c5 = "", *c6 = "", *c7 = "", *c8 = "";

    switch(lineaGanadora) {
        // Filas
        case 1: c0 = GANADOR; c1 = GANADOR; c2 = GANADOR; break;
        case 2: c3 = GANADOR; c4 = GANADOR; c5 = GANADOR; break;
        case 3: c6 = GANADOR; c7 = GANADOR; c8 = GANADOR; break;
        // Columnas
        case 4: c0 = GANADOR; c3 = GANADOR; c6 = GANADOR; break;
        case 5: c1 = GANADOR; c4 = GANADOR; c7 = GANADOR; break;
        case 6: c2 = GANADOR; c5 = GANADOR; c8 = GANADOR; break;
        // Diagonales
        case 7: c0 = GANADOR; c4 = GANADOR; c8 = GANADOR; break;
        case 8: c2 = GANADOR; c4 = GANADOR; c6 = GANADOR; break;
        default: break; // Ninguno se pinta si es 0
    }

    printf(NEGRITA "  Kattam Vilayattu\n" RESET);
    printf("\n");

    printf("     1   ");
    printf("              ");
    printf("2  ");
    printf("               ");
    printf("3\n");

    // --- Fila superior: nodos 0, 1, 2 ---
    // NOTA: Se añade %s antes de la casilla para inyectar el color dinámico
    printf("  1 %s%s(%c)%s", NEGRITA, c0, *(espacios+0), RESET);
    printf("---------------");
    printf("%s%s(%c)%s", NEGRITA, c1, *(espacios+1), RESET);
    printf("---------------");
    printf("%s%s(%c)%s\n", NEGRITA, c2, *(espacios+2), RESET);

    // Cuadros fila 0: amarillo izq | granate der
    printf("     | " AMARILLO "               " RESET " | " GRANATE "               " RESET " |\n");
    printf("     | " AMARILLO "               " RESET " | " GRANATE "               " RESET " |\n");
    printf("     | " AMARILLO "               " RESET " | " GRANATE "               " RESET " |\n");

    // --- Fila media: nodos 3, 4, 5 ---
    printf("  2 %s%s(%c)%s", NEGRITA, c3, *(espacios+3), RESET);
    printf("---------------");
    printf("%s%s(%c)%s", NEGRITA, c4, *(espacios+4), RESET);
    printf("---------------");
    printf("%s%s(%c)%s\n", NEGRITA, c5, *(espacios+5), RESET);

    // Cuadros fila 1: granate izq | amarillo der
    printf("     | " GRANATE "               " RESET " | " AMARILLO "               " RESET " |\n");
    printf("     | " GRANATE "               " RESET " | " AMARILLO "               " RESET " |\n");
    printf("     | " GRANATE "               " RESET " | " AMARILLO "               " RESET " |\n");

    // --- Fila inferior: nodos 6, 7, 8 ---
    printf("  3 %s%s(%c)%s", NEGRITA, c6, *(espacios+6), RESET);
    printf("---------------");
    printf("%s%s(%c)%s", NEGRITA, c7, *(espacios+7), RESET);
    printf("---------------");
    printf("%s%s(%c)%s\n", NEGRITA, c8, *(espacios+8), RESET);

    printf("\n");

    opPos();
}
void opPos() {
    printf("\n  -----Posiciones a elegir----- \n");
    printf("\n  _____________________________");
    printf("\n | 1,1 \033[36m= 1\033[0m | 1,2 \033[36m= 2\033[0m | 1,3 \033[36m= 3\033[0m | ");
    printf("\n | 2,1 \033[36m= 4\033[0m | 2,2 \033[36m= 5\033[0m | 2,3 \033[36m= 6\033[0m | ");
    printf("\n | 3,1 \033[36m= 7\033[0m | 3,2 \033[36m= 8\033[0m | 3,3 \033[36m= 9\033[0m | ");
    printf("\n |_____________________________|\n");}