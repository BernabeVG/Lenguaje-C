#include "tablero.h"
#include <stdio.h>

const char* COLOR_RESET   = "\x1b[0m";
const char* COLOR_TABLERO = "\x1b[36m";

void inicializarTablero(char *espacios){
    for(int i = 0; i < 9; i++){
        *(espacios +i) = 'O';
    }
}

void dibujarTablero(char *espacios)
{
    
    printf("%s -------------TABLERO-----------%s\n", COLOR_TABLERO, COLOR_RESET);
    printf("%s ______________________________ %s\n", COLOR_TABLERO, COLOR_RESET);
    printf("%s|%s %c %s__________%s %c %s__________%s %c %s|%s\n", 
           COLOR_TABLERO, COLOR_RESET, *(espacios+0), COLOR_TABLERO, COLOR_RESET, *(espacios+1), COLOR_TABLERO, COLOR_RESET, *(espacios+2), COLOR_TABLERO, COLOR_RESET);
    printf("%s|  |          |  |          |  |%s\n", COLOR_TABLERO, COLOR_RESET);
    printf("%s|  |          |  |          |  |%s\n", COLOR_TABLERO, COLOR_RESET);
    printf("%s|  |__________|  |__________|  |%s\n", COLOR_TABLERO, COLOR_RESET);
    printf("%s|%s %c %s            %s %c %s            %s %c %s|%s\n", 
           COLOR_TABLERO, COLOR_RESET, *(espacios+3), COLOR_TABLERO, COLOR_RESET, *(espacios+4), COLOR_TABLERO, COLOR_RESET, *(espacios+5), COLOR_TABLERO, COLOR_RESET);
    printf("%s|   __________    __________   |%s\n", COLOR_TABLERO, COLOR_RESET);
    printf("%s|  |          |  |          |  |%s\n", COLOR_TABLERO, COLOR_RESET);
    printf("%s|  |__________|  |__________|  |%s\n", COLOR_TABLERO, COLOR_RESET);
    printf("%s|%s %c %s            %s %c %s            %s %c %s|%s\n", 
           COLOR_TABLERO, COLOR_RESET, *(espacios+6), COLOR_TABLERO, COLOR_RESET, *(espacios+7), COLOR_TABLERO, COLOR_RESET, *(espacios+8), COLOR_TABLERO, COLOR_RESET);
    printf("%s|______________________________|%s\n\n", COLOR_TABLERO, COLOR_RESET);
}