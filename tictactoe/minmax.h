#ifndef MINMAX_H
#define MINMAX_H
#include <string>
#include <iostream>

using namespace std;

class minMax
{
    public:
        minMax();
        virtual ~minMax();

        char matrixPlays(int place);
        void toString(int matrix[9]);
        int checkWin(const int matrix[9]);
        int miniMax(int matrix[9], int player);
        int IAplay(int matrix[9]);
        void playerPlay(int matrix[9]);
        int control();

    protected:
        int matrix[], turn, move, score, player;
};

#endif // MINMAX_H
