#include "../funcsH/jugador.h"
#include "../funcsH/movimiento.h"
#include <stdio.h>

void inicializarFichas(Jugador *p1, Jugador *p2) {
    p1->simbolo = '$';
    p2->simbolo = '+';
    p1->numFichas = 3;
    p2->numFichas = 3;
}
void turnoJudador(char *espacios, Jugador p, int tipo, int org)
{
    int numero, valido = 0;
    do {
        if (p.simbolo == '$') {
            printf("\nTurno: Player 1($)");
        }else {
            printf("\nTurno: Player 2(+)");
        }
        printf("\nIngresa un numero de la casilla para colocar tu ficha (1-9): ");
        scanf("%d", &numero);
        numero--;
        if (tipo == 1) valido = movimientoValido(numero, espacios, p);
        if (tipo == 2) valido = validarDesplazamiento(org,numero, espacios);
        if (!valido) {
            printf("Movimiento invalido o casilla ocupada. Intenta de nuevo.\n");
        }else {
            *(espacios+numero) = p.simbolo;
        }
    } while (numero < 0 || numero > 8 || !valido);
}
void moverFichaPuesta(char *espacios, Jugador p)
{
    int numero, valida = 0;
    do{
        if (p.simbolo == '$') {
            printf("\nTurno: Player 1");
        }else {
            printf("\nTurno: Player 2");
        }
        printf("\nIngresa un numero de la casilla de tu ficha a mover (1-9): ");
        scanf("%d", &numero);
        numero--;
        valida = fichaValida(numero, espacios, p);

        if (!valida) {
            printf("Ahi no hay una ficha tuya. Intenta de nuevo.\n");
        }

    }while(numero < 0 || numero > 8 || !valida);
    turnoJudador(espacios, p, 2, numero);
    *(espacios+numero) = ' ';
}
Jugador* CrearTablaPosiciones() {
    Jugador *ptr=NULL;
    ptr = (Jugador *) calloc(2, sizeof(Jugador));

    if (ptr == NULL) {
        printf("\nError: no fue posible asignar memoria a la tabla");
        return NULL;
    }

    ptr[0].simbolo = '$';
    ptr[1].simbolo = '+';

    printf("\n----------Direcciones---------");
    printf("\nDireccion de Jugador 1 ($): %p", (void*)&ptr[0]);
    printf("\nDireccion de Jugador 2 (+): %p", (void*)&ptr[1]);
    printf("\n----------------------------------------\n");

    return ptr;
}