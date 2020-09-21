#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "disk.h"
using namespace std;

enum STACK_ERR {FULL, EMPTY};

class stack{
public:
    stack();
    ~stack();

    void setDisks(int);
    void inStack(int);
    void push(disk*);
    disk *pop();
    disk *peek();

    bool empty();
    bool full();

    int sizeOf();
    int quant();

    friend ostream& operator<<(ostream& out, const stack& other);

private:
    disk *top;
    int currSize, cap, tot_disks;

    void nukem();
};

#endif // STACK_H
