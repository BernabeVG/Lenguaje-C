#include "../funcsH/jugador.h"
#include <stdio.h>

void turnoJudador(char *espacios, char jugador)
{
    int numero;
    do{
        printf("Ingresa un numero de la casilla para colocar tu ficha (1-9)");
         scanf("%d", &numero);
         numero--;
          if(*(espacios+numero)=='O'){
         *(espacios+numero) = jugador;
          break;
       }
    }while(numero > 0 || !numero < 8);
}

int verificarGanador(char *espacios, char jugador, char jugador2)
{

    if((*(espacios+0) != 'O') && (*(espacios+0) == *(espacios+1) && (*(espacios+1) == *(espacios+2))))
    {
            printf("Ganaste\n");
    }
     else if((*(espacios+3) != 'O') && (*(espacios+3) == *(espacios+4) && (*(espacios+4) == *(espacios+5))))
    {
            printf("Ganaste\n");
    }
     else if((*(espacios+6) != 'O') && (*(espacios+6) == *(espacios+7) && (*(espacios+7) == *(espacios+5))))
    {
            printf("Ganaste\n");
    }
     else if((*(espacios+0) != 'O') && (*(espacios+0) == *(espacios+3) && (*(espacios+3) == *(espacios+6))))
    {
            printf("Ganaste\n");
    }
     else if((*(espacios+1) != 'O') && (*(espacios+1) == *(espacios+4) && (*(espacios+4) == *(espacios+7))))
    {
            printf("Ganaste\n");
    }
      else if((*(espacios+2) != 'O') && (*(espacios+2) == *(espacios+5) && (*(espacios+5) == *(espacios+8))))
    {
            printf("Ganaste\n");
    }
      else if((*(espacios+0) != 'O') && (*(espacios+0) == *(espacios+4) && (*(espacios+4) == *(espacios+8))))
    {
            printf("Ganaste\n");
    }
      else if((*(espacios+2) != 'O') && (*(espacios+2) == *(espacios+4) && (*(espacios+4) == *(espacios+6))))
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
        if(*(espacios+i) == 'O')
        {
            return 0;
        }
    }
    printf("Empate\n");
    return 1;
}