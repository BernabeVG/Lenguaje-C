# Lenguaje-C Compilar
gcc -std=c99 src\main.c src\funcs\*.c -o main
./main.exe

El juego se llama: Kattam Vilayattu

Reglas basicas:

Solo pueden jugar 2 jugadores
Cada jugador tiene el mismo número de fichas
Se juega por turnos
Durante la fase inicial: Solo se colocan piezas, no se mueven 
No se puede colocar una pieza en un espacio ocupado
Una línea válida se forma con 3 piezas propias alineadas
Se conecta conectando en vertical, horizontal o diagonal
En la fase de movimiento: Solo se puede mover a posiciones conectadas
Un jugador pierde si: El jugador contrario conecta las 3 fichas


