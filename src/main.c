#include <stdio.h>
#include <stdlib.h>
#include "funcsH/tablero.h"
#include "funcsH/jugador.h"
#include "funcsH/movimiento.h"

// Prototipos de funciones
void instruccionesJuego();

int main()
{
    int opcion, linea = 0, t = 0, capacidad = 0, actual = 0;
    char espacios[9];

    // 1. Reservar memoria dinámica para la tabla de posiciones en el Heap
    Jugador *tablaDinamica = CrearTablaPosiciones();

    // Validación obligatoria para el examen a papel
    if (tablaDinamica == NULL) {
        printf("Error crítico: No se pudo asignar memoria dinámica. Saliendo...\n");
        return 1;
    }

    // Mapeo por macros para mantener tus variables p1 y p2 apuntando al Heap
    #define p1 (tablaDinamica[0])
    #define p2 (tablaDinamica[1])
    char text[16];
    char* historial;
    inicializarFichas(&p1, &p2);

    do
    {
        historial = (char*)calloc(capacidad, 16);// reiniciar historial cada que se inicie una partida, capacidad = 0

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
                     system("cls"); // Limpia pantalla antes de redibujar
                     printf("%d", t);
                     historial = gestionHistorial(historial, &actual, &capacidad );
                     linea = verGanador(espacios);
                     dibujarTablero(espacios, linea);

                     // =======================================================
                     // ADICIONADO: Impresión de direcciones de memoria en el Heap
                     // Se muestra dinámicamente justo abajo del tablero en cada turno
                     // =======================================================
                     printf("\n[DEBUG MEMORIA HEAP (Tabla Posiciones)]");
                     printf("\nDireccion de memoria Player 1 ($)");
                     printf("\nDireccion de memoria Player 2 (+)");
                     printf("-------------------------------------------------------\n");
                     // =======================================================

                     if (linea != 0) {
                         break;
                     }

                     // --- TU LÓGICA ORIGINAL DE MOVIMIENTOS COMPLETA ---
                     if (t % 2 == 0) {
                         // --- TURNO DEL PLAYER 1 ---
                         if (p1.numFichas > 0) {
                             turnoJudador(espacios, p1, 1, 0, historial, &actual, &capacidad, text);
                             p1.numFichas--;
                         } else {
                             moverFichaPuesta(espacios, p1, historial, &actual, &capacidad, text);
                         }

                     }
                     else {
                         // --- TURNO DEL PLAYER 2 ---
                         if (p2.numFichas > 0) {
                             turnoJudador(espacios, p2, 1, 0, historial, &actual, &capacidad, text);
                             p2.numFichas--;
                         } else {
                             moverFichaPuesta(espacios, p2, historial, &actual, &capacidad, text);
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
        capacidad = 0;
    }while(opcion == 1);

    // 2. Liberación obligatoria del bloque del Heap antes de terminar el programa
    free(historial);

    return 0;
}

// funciones
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
    printf("\nUn jugador pierde si: El jugador contrario conecta las 3 fichas\n");
} //como yo soy naco

