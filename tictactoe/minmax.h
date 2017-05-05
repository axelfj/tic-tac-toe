#ifndef MINMAX_H
#define MINMAX_H


class minMax
{
public:
    minMax();
    virtual ~minMax();

    // methods //
    int checkWin(char matrix[]); // return +1 if max wins
    bool checkDraw(char matrix[]); // return 0 if
    int algorithmMinMax(int player, char matrix[], int depth);

    void Game();
private:
    char* matrix;
    int max, min, posMax, posMin, depth;
};

#endif // MINMAX_H
