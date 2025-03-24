#include <iostream>

#include "myStack.h"

using namespace std;


myStack::myStack(){
    top = NULL;
    currSize = 0;
    tot_disks = 0;
    cap = 1 << 29;
}

myStack::~myStack(){
    nukem();
}

void myStack::setDisks(int s){
    tot_disks = s;
}

void myStack::inmyStack(int s){
    disk* putIn = NULL;
    currSize = 0;
    tot_disks = s;
    for(int i = s-1; i > -1; --i){
        putIn = new disk;
        putIn->setSize(i+1);
        push(putIn);
    }
}

void myStack::push(disk *d){
//    if(full())
//        throw FULL;
    disk* temp = new disk;
    temp = d;
    if(!empty()){
        temp->setNext(top);
        if(d->isBigger(top))
            throw IS_BIGGER;
    }
    top = temp;
    ++currSize;
}

disk* myStack::pop(){
    if(empty())
        throw EMPTY;
    disk *temp = new disk(*top);
    top = top->getNext();
    --currSize;
    return temp;
}

disk* myStack::peek(){
    return top;
}

bool myStack::empty(){
    return top == NULL;
}

bool myStack::full(){
    return currSize == tot_disks;
}

int myStack::sizeOf(){
    return currSize;
}

ostream& operator<<(ostream &out, const myStack& s){
    if(&out == &cout){
        out << "Size: " << s.currSize << endl
            << "Number of Disks: " << s.tot_disks << endl
            << "myStack capacity: " << s.tot_disks << endl
            << "myStack Contents: \n";
        int i = 0;
        for(disk* temp = s.top; temp != NULL; temp = temp->getNext()){
            out << "index " << i << " : data " << temp->getSize() << endl;
            ++i;
            if(temp->getNext() == NULL)
                break;
        }
    }
    out << endl << endl;
    return out;
}

void myStack::nukem(){
    currSize = 0;
    top = NULL;
    while(!empty())
        pop();
}





















