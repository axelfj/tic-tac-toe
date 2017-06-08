#include "minMax.h"
#include <stdio.h>

// Needed to make a object out of it.
// @author azzefj
// 27/05/17
minMax::minMax(){}

// empty dtor
// @author azzefj
// 27/05/17
minMax::~minMax(){}

// Retorna cada posibilidad en la matriz con un char (esencial para el print)
// @author azzefj
// 27/05/17
char minMax::matrixPlays(int place)
{
    switch(place)
    {
        case -1:
            return 'x';
        case 0:
            return ' ';
        case 1:
            return 'o';
    }
}

// Hace un print de la matriz a la consola.
// @author azzefj
// 27/05/17
void minMax::toString(int matrix[9])
{
    printf(" %c | %c | %c\n",matrixPlays(matrix[0]),matrixPlays(matrix[1]),matrixPlays(matrix[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",matrixPlays(matrix[3]),matrixPlays(matrix[4]),matrixPlays(matrix[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",matrixPlays(matrix[6]),matrixPlays(matrix[7]),matrixPlays(matrix[8]));
}

// Chequea la matriz para retornar si algún jugador ya gano la partida.
// @author azzefj
// 27/05/17
int minMax::checkWin(const int matrix[9]) {
    unsigned waysToWin[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(int i = 0; i < 8; i++)
    {
        if(     matrix[waysToWin[i][0]] != 0 &&
                matrix[waysToWin[i][0]] == matrix[waysToWin[i][1]] &&
                matrix[waysToWin[i][0]] == matrix[waysToWin[i][2]])
                return matrix[waysToWin[i][2]];
    }
    return 0;
}

// Algoritmo minimax, es un árbol que se expande a todas las posibles jugadas del oponente.
// @author azzefj
// 27/05/17
int minMax::miniMax(int matrix[9], int player) {
    int winner = checkWin(matrix);
    if(winner != 0)
        return winner*player;
    move = -1;
    score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(matrix[i] == 0) {
            matrix[i] = player;
            int thisScore = -miniMax(matrix, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
            matrix[i] = 0;
        }
    }
    if(move == -1) return 0;
    return score;
}

// Es la jugada de la inteligencia artificial.
// @author azzefj
// 27/05/17
int minMax::IAplay(int matrix[9]) {
    move = -1;
    score = -2;
    for(int i = 1; i <= 9; i++) {
        if(matrix[i] == 0) {
            matrix[i] = 1;
            int tempScore = -miniMax(matrix, -1);
            matrix[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    matrix[move] = 1;
    return move;
}

// Jugada del jugador.
// @author azzefj
// 27/05/17
void minMax::playerPlay(int matrix[9])
{
    move = 0;
    do {
        printf("\nInput move ([0..8]): ");
        scanf("%d", &move);
        printf("\n");
    } while (move >= 9 || move < 0 && matrix[move] == 0);
    matrix[move] = -1;
}

// Control del juego, lleva la lógica de turnos y aplica minmax a la IA.
// @author azzefj
// 27/05/17
int minMax::control()
{
    int matrix[9] = {0,0,0,0,0,0,0,0,0};
    printf("IA: O, You: X\nPlay (1)st or (2)nd? ");
    int player=0;
    scanf("%d",&player);
    printf("\n");
    unsigned turn;
    for(turn = 0; turn < 9 && checkWin(matrix) == 0; ++turn)
    {
        if((turn+player) % 2 == 0)
            IAplay(matrix);
        else {
            toString(matrix);
            playerPlay(matrix);
        }
    }
    switch(checkWin(matrix)) {
        case 0:
            printf("That's a draw, well played hooman..\n");
            break;
        case 1:
            toString(matrix);
            printf("I'm the best, you lose..\n");
            break;
        case -1:
            printf("How did you? You win.\n");
            break;
    }
}
