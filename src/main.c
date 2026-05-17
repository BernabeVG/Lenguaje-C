#include <stdio.h>
#include <stdlib.h>
#include "funcsH/tablero.h"
#include "funcsH/jugador.h"
#include "funcsH/movimiento.h"
#include "funcsH/jugador.h"
#include "funcsH/tablero.h"

//Prototipos de funciones
void instruccionesJuego();

int main() 
{
    int opcion, linea = 0, t = 0;
    char espacios[9];
    Jugador p1;
    Jugador p2;
    inicializarFichas(&p1, &p2);

    do
    {
        inicializarTablero(espacios);
        t = 0;
        printf("\n---Kattam Vilayattu---\n");
        printf("1. Instrucciones: \n");
        printf("2. Iniciar Juego\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
    
         switch(opcion){
             case 1:
                 instruccionesJuego();
                 break;
             case 2:
                 do {
                     system("cls");
                     printf("%d", t);
                     linea = verGanador(espacios);
                     dibujarTablero(espacios, linea);
                     if (linea != 0) {
                         break;
                     }

                     // 1. Determinar el turno actual usando la variable 't'
                     if (t % 2 == 0) {
                         // --- TURNO DEL PLAYER 1 ---
                         if (p1.numFichas > 0) {
                             turnoJudador(espacios, p1, 1, 0);
                             p1.numFichas--;
                         } else {
                             moverFichaPuesta(espacios, p1);
                         }
                     }
                     else {
                         // --- TURNO DEL PLAYER 2 ---
                         if (p2.numFichas > 0) {
                             turnoJudador(espacios, p2, 1, 0);
                             p2.numFichas--; // Restamos una ficha en main
                         } else {
                             moverFichaPuesta(espacios, p2);
                         }
                     }
                     t+=1;
                 }while (linea == 0 );
                 break;
             case 3:
                 printf("Saliendo del juego...\n");
                 break;

                default:
                 printf("Opcion invalida.\n");
                break;
             }
        printf("\nQuieres volver al inicio? Si = 1 / No = 0: ");
        scanf("%d", &opcion);
    }while(opcion == 1);

    return 0;
}

//funciones
void instruccionesJuego()
{
    printf("\n     ----- Instrucciones del Juego -----     ");
    printf("\nSolo pueden jugar 2 jugadores.");
    printf("\nCada jugador tiene el mismo número de fichas.");
    printf("\nSe juega por turnos.");
    printf("\nDurante la fase inicial: Solo se colocan piezas, no se mueven.");
    printf("\nNo se puede colocar una pieza en un espacio ocupado.");
    printf("\nUna línea válida se forma con 3 piezas propias alineadas.");
    printf("\nSe conecta conectando en vertical, horizontal o diagonal.");
    printf("\nEn la fase de movimiento: Solo se puede mover a posiciones conectadas.");
    printf("\nUn jugador pierde si: El jugador contrario conecta las 3 fichas");
}