#include <stdio.h>
#include <stdlib.h>

//Prototipos del juego
void instruccionesJuego();
void dibujar_tablero(char *espacios);
void turnoJugador(char *espacios, char jugador);
void turnoJugador2(char *espacios, char jugador2);
int verificarGanador(char *espacios, char jugador, char jugador2);
int verificarEmpate(char *espacios);

//Inicio del main
int main() 
{
    char espacios[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char jugador1 = 'X';
    char jugador2 = 'O';
    int ejecutando = 1;
    int opc;

    do
    {
    printf("\n _____________________________________ ");
    printf("\n|  X Bienvenido a Tic Tac Toe Bolt O  |");
    printf("\n|   [1] Instrucciones del Juego       |");
    printf("\n|   [2] Empezar a Jugar               |");
    printf("\n|   [3] Salir del Juego               |");
    printf("\n|_____________________________________|\n");
    printf("\n    Seleccione una Opcion:");
    scanf("%d", &opc);

    
    //Inicio del Switch Case para que el/los usuarios escogan que quieren hacer
    switch(opc)
    {
        case 1:
            instruccionesJuego();
        break;

        case 2:
            system("clear");
            dibujar_tablero(espacios);
            
            while(ejecutando)
            {
                turnoJugador(espacios, jugador1);
                dibujar_tablero(espacios);
                if(verificarGanador(espacios, jugador1, jugador2)){
                    ejecutando = 0;
                    break;
                }
                if(verificarEmpate(espacios))
                {
                    ejecutando=0;
                    break;
                }
                turnoJugador2(espacios, jugador2);
                dibujar_tablero(espacios);
                 if(verificarGanador(espacios, jugador1, jugador2)){
                    ejecutando = 0;
                    break;
                }
                if(verificarEmpate(espacios))
                {
                    ejecutando=0;
                    break;
                }
                
            }

        break;

        case 3:
            goto salir;
        break;

        default:
            printf("Opcion Invalida.");
        break;
    }
    printf("Quieres volver al inicio? si = 1 / no = 0:" );
    scanf("%d", &opc);
    
    }
    while(opc == 1);

    salir:
        printf("    Saliendo del juego...\n");

    return 0;
}

//funciones del juego
void instruccionesJuego()
{
    printf("\n            ---Instrucciones del Juego---                 ");
    printf("\n1. Se cuenta con un tablero de 3 x 3");
    printf("\n2. se debe ingresar una 'X' el jugador [1] y una 'O' el jugador [2]");
    printf("\n3. El ganador es aquel que logre alinear 3 fichas de manera vertical,horizontal o diagonal");
    printf("\nNota: El jugador puede bloquear a su oponente para evitar que gane, \nsi nadie alinea 3 fichas, se acaba el juego");

    printf("\n\n    ---Como jugar?---   ");
    printf("\nEl tablero es el siguiente: ");
    printf("     -------------   \n");
    printf("     | . | . | . |   \n");
    printf("     | . | . | . |   \n");
    printf("     | . | . | . |   \n");
    printf("     -------------   \n"); 

    printf("\n   ---Ejemplo---");
    printf("\n1.El jugador debera ingresar calumna: 2.");
    printf("\n2.El jugador debera ingresar la fila: 2.");
    printf("\nCon estos se colocara la ficha en el punto exacto del tablero.\n");
    printf("\nTablero actualizado: \n");
    printf("Ingresa la posicion (1 - 9)\n");
    printf("     -------------   \n");
    printf("     | . | . | . |   \n");
    printf("     | . | X | . |   \n");
    printf("     | . | . | . |   \n");
    printf("     -------------   \n"); 
}

void dibujar_tablero(char *espacios)
{
    printf("\n        Tablero        \n");
    printf("        %c | %c  | %c     \n", *(espacios+0), *(espacios+1), *(espacios+2));
    printf("     _____|____|_____   \n");
    printf("        %c | %c  | %c     \n", *(espacios+3), *(espacios+4), *(espacios+5));
    printf("     _____|____|_____   \n");
    printf("        %c | %c  | %c     \n", *(espacios+6), *(espacios+7), *(espacios+8));
    printf("          |    |        \n"); 
}

void turnoJugador(char *espacios, char jugador1)
{
    int numero;
    do
    {
        printf("Ingresa un numero en la casilla para jugar (1-9): ");
        scanf("%d", &numero);
        numero--; //Posicion del arreglo casilla 9-1 = 8 del tablero
        if(*(espacios+numero) == ' '){    //Si la posicion ingresada tiene caracter espacio,
            *(espacios+numero) = jugador1; // sobreescribe posicion jugador 'X'
            break;
        }
    }
    while (!numero > 0 || !numero <8);
}

void turnoJugador2(char *espacios, char jugador2)
{
    int numero;
    do
    {
        printf("Ingresa un numero en la casilla para jugar (1-9): ");
        scanf("%d", &numero);
        numero--; //Posicion del arreglo casilla 9-1 = 8 del tablero
        if(*(espacios+numero) == ' '){    //Si la posicion ingresada tiene caracter espacio,
            *(espacios+numero) = jugador2; // sobreescribe posicion jugador 'X'
            break;
        }
    }
    while (!numero > 0 || !numero <8);
}

int verificarGanador(char *espacios, char jugador, char jugador2)
{

    if((*(espacios+0) != ' ') && (*(espacios+0) == *(espacios+1) && (*(espacios+1) == *(espacios+2))))
    {
            printf("Ganaste\n");
    }
     else if((*(espacios+3) != ' ') && (*(espacios+3) == *(espacios+4) && (*(espacios+4) == *(espacios+5))))
    {
            printf("Ganaste\n");
    }
     else if((*(espacios+6) != ' ') && (*(espacios+6) == *(espacios+7) && (*(espacios+7) == *(espacios+5))))
    {
            printf("Ganaste\n");
    }
     else if((*(espacios+0) != ' ') && (*(espacios+0) == *(espacios+3) && (*(espacios+3) == *(espacios+6))))
    {
            printf("Ganaste\n");
    }
     else if((*(espacios+1) != ' ') && (*(espacios+1) == *(espacios+4) && (*(espacios+4) == *(espacios+7))))
    {
            printf("Ganaste\n");
    }
      else if((*(espacios+2) != ' ') && (*(espacios+2) == *(espacios+5) && (*(espacios+5) == *(espacios+8))))
    {
            printf("Ganaste\n");
    }
      else if((*(espacios+0) != ' ') && (*(espacios+0) == *(espacios+4) && (*(espacios+4) == *(espacios+8))))
    {
            printf("Ganaste\n");
    }
      else if((*(espacios+2) != ' ') && (*(espacios+2) == *(espacios+4) && (*(espacios+4) == *(espacios+6))))
    {
            printf("Ganaste\n");
    }
    else 
    {
        return 0;
    }
    return 1;
}

int verificarEmpate(char *espacios)
{
    for(int i = 0; i < 9; i++)
    {
        if(*(espacios+i) == ' ')
        {
            return 0;
        }
    }
    printf("Empate\n");
    return 1;
}