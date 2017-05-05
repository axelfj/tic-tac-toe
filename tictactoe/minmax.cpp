#include "minmax.h"
#include <iostream>
using namespace std;
minMax::minMax()
{
    char* matrix = new char[9];
    max = 1; // # player
    min = 2;
    depth = 0;
}

minMax::~minMax()
{

}

// methods //
int minMax::checkWin(char matrix[]) // return +1 if max wins
{
    if (    // horizontal //
            (matrix[0] == 'x' && matrix[1] == 'x' && matrix[2] == 'x')
            || (matrix[3] == 'x' && matrix[4] == 'x' && matrix[5] == 'x)')
            || (matrix[6] == 'x' && matrix[7] == 'x' && matrix[8] == 'x')
            //vertical//
            || (matrix[0] == 'x' && matrix[3] == 'x' && matrix[6] == 'x')
            || (matrix[1] == 'x' && matrix[4] == 'x' && matrix[7] == 'x')
            || (matrix[2] == 'x' && matrix[5] == 'x' && matrix[8] == 'x')
            // diagonal //
            || (matrix[0] == 'x' && matrix[4] == 'x' && matrix[8] == 'x')
            || (matrix[2] == 'x' && matrix[4] == 'x' && matrix[6] == 'x')
            )
            {
                return 1; // max wins
            }
    else if(    // horizontal //
               (matrix[0] == 'o' && matrix[1] == 'o' && matrix[2] == 'o')
                || (matrix[3] == 'o' && matrix[4] == 'o' && matrix[5] == 'o')
                || (matrix[6] == 'o' && matrix[7] == 'o' && matrix[8] == 'o')
                //vertical//
                || (matrix[0] == 'o' && matrix[3] == 'o' && matrix[6] == 'o')
                || (matrix[1] == 'o' && matrix[4] == 'o' && matrix[7] == 'o')
                || (matrix[2] == 'o' && matrix[5] == 'o' && matrix[8] == 'o')
                // diagonal //
                || (matrix[0] == 'o' && matrix[4] == 'o' && matrix[8] == 'o')
                || (matrix[2] == 'o' && matrix[4] == 'o' && matrix[6] == 'o')
                )
                {
                    return -1; // max losses
                }
    else
    {
        return 0;  // draw
    }
}

bool minMax::checkDraw(char matrix[])
{
    if (checkWin(matrix) == 0)
    {
        for (int i = 0; i < 9; i++)
        {
           // char toCompare = '-';//
            if (matrix[i] == '-'){return false;}
        }
    }
    else{return true;}
}
int minMax::algorithmMinMax(int player, char matrix[], int depth)
{
    max = 1;
    min = -1;

    int checkIt = checkWin(matrix); // check the matrix
    if (checkIt == 1){return 1;}
    else if (checkIt == -1){return -1;}
    else if(checkDraw(matrix) == true){return 0;}

    for(int i = 0; i < 9; i++)
    {
        if (player == 1)
        {
            matrix[i] = 'x'; // it fills the space with the x option and go to the best option recursively
            int bestChoice = algorithmMinMax(2,matrix,depth+1);

            matrix[i] = '-';
            if(bestChoice>max)
            {
                max = bestChoice;
                if (depth == 0)
                {
                    posMax = i;
                }
            }
        }
        if (player == 2)
        {
            matrix[i] = 'o'; // it fills the space with the o option and go to the best option recursively
            int bestChoice = algorithmMinMax(1,matrix,depth+1);

            matrix[i] = '-';
            if(bestChoice<min)
            {
                min = bestChoice;
                if (depth == 0)
                {
                    posMin = i;
                }
            }
        }
    }
    if (player == 1)
    {
        return max;
    }
    else{
        return min;
    }
}

void minMax::Game()
{
    int i,j, place, winCondition;

    char* matrix = new char[9]; // create the matrix and fill the spaces
    for(j = 0; j < 9; j++)
    {
        matrix[j] = '-';
    }

    for (i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            cout << "Player 1: Please give your place.\n"; // place in the matrix between 0 and 8 //
            cin >> place;
        }
        else
        {
            cout << "Player 2: Please give your place.\n";
            cin >> place;
        }
        if (i%2 == 0)
        {
            matrix[place] = 'x';
        }
        if(i%2 != 0)
        {
            matrix[place] = 'o';
        }

        int checkIt = checkWin(matrix);
        if (checkIt == 1)
        {
            cout << "Player 1 wins\n;";
            break;
        }
        if (checkIt == -1)
        {
            cout << "Player 2 wins\n";
            break;
        }
        if ((checkIt == 0) && (i != 9))
        {
            posMax = -1;
            posMin = -1;
            if (i%2 == 0)
            {
                winCondition = algorithmMinMax(1,matrix,0);
                cout << "Best play for X is:" << posMax << endl;
            }
            else
            {
                winCondition = algorithmMinMax(2,matrix,0);
                cout << "Best play for O is:"<< posMin << endl;
            }
        }
        else{
            cout << "Draw.\n";
        }
    }
}
