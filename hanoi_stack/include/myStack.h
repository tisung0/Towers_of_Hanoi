#ifndef myStack_H
#define myStack_H

#include <iostream>
#include "disk.h"

using namespace std;

enum myStack_ERR {FULL, EMPTY};

class myStack{
public:
    myStack();
    ~myStack();

    void setDisks(int);
    void inmyStack(int);
    void push(disk*);
    disk *pop();
    disk *peek();

    bool empty();
    bool full();

    int sizeOf();
    int quant();

    friend ostream& operator<<(ostream& out, const myStack& other);

private:
    disk *top;
    int currSize, cap, tot_disks;

    void nukem();
};

#endif // myStack_H
