#include <stdio.h>
#include <stdlib.h>
#include "funcsH/tablero.h"
//#include "funcsH/jugador.h"
//#include "funcsH/movimiento.h"

//Prototipos de funciones
void intruccionesJuego();

int main() 
{
    int opcion;
    char espacios[9];
    inicializarTablero(espacios);
    dibujarTablero(espacios);
    /*do
    {

        printf("\n---Kattam Vilayattu---\n");
        printf("1. Instrucciones: \n");
        printf("2. Iniciar Juego\n");
        print("3. Salir\n");
        printf("Seleccione una opción: \n");
        scanf("%d", &opcion);
    
     switch(opcion)
         {
         case 1:
              instruccionesJuego();
          break;
          case 2:
              system("clear");
              dibujarTablero(espacios);
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
    */
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