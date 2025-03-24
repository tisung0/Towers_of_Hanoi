#ifndef BOARD_H
#define BOARD_H
#include "myStack.h"

enum BOARD_ERR{OUTSIDE_RANGE};

class Board{
public:
    Board();
    ~Board();

    bool legal(myStack&, myStack&);
    bool complete();

    void moveLeft(int);
    void moveRight(int);
    void load(int);
    void generalMove(myStack&, myStack&);
    void play();

    void autoSolve();

    friend ostream& operator << (ostream& out, const Board& b);

private:
    myStack *rods, *start, *end;
    static const int num = 3;
    int num_of_disks;
};





#endif // BOARD_H
