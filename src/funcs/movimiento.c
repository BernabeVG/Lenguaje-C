#include "../funcsH/movimiento.h"
#include "../funcsH/jugador.h"
#include <string.h>
#include <stdio.h>

int movimientoValido(int pos, char *espacios, Jugador p) {
    if (*(espacios + pos) == ' ')
    {
        return 1;
    }
    return 0;
}
int fichaValida(int pos, char *espacios, Jugador p) {
    if (*(espacios + pos) == p.simbolo)
    {
        return 1;
    }
    return 0;
}
int verGanador(const char *espacios) {
    // 1. Verificar Filas (Retornan 1, 2 o 3)
    if ((*(espacios + 0) != ' ') && (*(espacios + 0) == *(espacios + 1) && *(espacios + 1) == *(espacios + 2))) return 1;
    if ((*(espacios + 3) != ' ') && (*(espacios + 3) == *(espacios + 4) && *(espacios + 4) == *(espacios + 5))) return 2;
    if ((*(espacios + 6) != ' ') && (*(espacios + 6) == *(espacios + 7) && *(espacios + 7) == *(espacios + 8))) return 3;

    // 2. Verificar Columnas (Retornan 4, 5 o 6)
    if ((*(espacios + 0) != ' ') && (*(espacios + 0) == *(espacios + 3) && *(espacios + 3) == *(espacios + 6))) return 4;
    if ((*(espacios + 1) != ' ') && (*(espacios + 1) == *(espacios + 4) && *(espacios + 4) == *(espacios + 7))) return 5;
    if ((*(espacios + 2) != ' ') && (*(espacios + 2) == *(espacios + 5) && *(espacios + 5) == *(espacios + 8))) return 6;

    // 3. Verificar Diagonales (Retornan 7 u 8)
    if ((*(espacios + 0) != ' ') && (*(espacios + 0) == *(espacios + 4) && *(espacios + 4) == *(espacios + 8))) return 7;
    if ((*(espacios + 2) != ' ') && (*(espacios + 2) == *(espacios + 4) && *(espacios + 4) == *(espacios + 6))) return 8;

    // Si nadie ha ganado, devolvemos 0
    return 0;
}

int validarDesplazamiento(int origen, int destino, char *espacios) {

    if (destino < 0 || destino > 8) return 0;
    if (*(espacios + destino) != ' ') return 0;
    switch (origen) {
        case 0:
            if (destino == 1 || destino == 3) return 1;
            break;
        case 1:
            if (destino == 0 || destino == 2 || destino == 4) return 1;
            break;
        case 2:
            if (destino == 1 || destino == 5) return 1;
            break;
        case 3:
            if (destino == 0 || destino == 4 || destino == 6) return 1;
            break;
        case 4:
            if (destino == 1 || destino == 3 || destino == 5 || destino == 7) return 1;
            break;
        case 5:
            if (destino == 2 || destino == 4 || destino == 8) return 1;
            break;
        case 6:
            if (destino == 3 || destino == 7) return 1;
            break;
        case 7:
            if (destino == 4 || destino == 6 || destino == 8) return 1;
            break;
        case 8:
            if (destino == 5 || destino == 7) return 1;
            break;

        default:

            break;
    }

    return 0;
}
char* agregarPosicion(char* historial, int* actual, int* capacidad, const char* text)
{
    historial = gestionHistorial(historial, actual, capacidad );
    char* destino = historial + (*actual * 16);
    strncpy(destino, text, 15);
    destino[15] = '\0';
    (*actual)++;
    return historial;
}
void obtenerTextoPosicion(int opcionElegida, char* variableDestino) {

    switch (opcionElegida) {
    case 1:
        // snprintf copia el texto exacto dentro de tu variable
        snprintf(variableDestino, 16, "1 , 1 = 1");
        break;
    case 2:
        snprintf(variableDestino, 16, "1 , 2 = 2");
        break;
    case 3:
        snprintf(variableDestino, 16, "1 , 3 = 3");
        break;
    case 4:
        snprintf(variableDestino, 16, "2 , 1 = 4");
        break;
    case 5:
        snprintf(variableDestino, 16, "2 , 2 = 5");
        break;
    case 6:
        snprintf(variableDestino, 16, "2 , 3 = 6");
        break;
    case 7:
        snprintf(variableDestino, 16, "3 , 1 = 7");
        break;
    case 8:
        snprintf(variableDestino, 16, "3 , 2 = 8");
        break;
    case 9:
        snprintf(variableDestino, 16, "3 , 3 = 9");
        break;
    default:
        // Por si eligen un número que no está en el tablero
        snprintf(variableDestino, 16, "0 , 0 = 0");
        break;
    }
}