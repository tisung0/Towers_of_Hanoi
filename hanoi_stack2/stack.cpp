#include <iostream>
#include "stack.h"

using namespace std;


stack::stack(){
    top = NULL;
    currSize = 0;
    tot_disks = 0;
    cap = 1 << 29;
}

stack::~stack(){
    nukem();
}

void stack::setDisks(int s){
    tot_disks = s;
}

void stack::inStack(int s){
    disk* putIn = NULL;
    currSize = 0;
    tot_disks = s;
    for(int i = s-1; i > -1; --i){
        putIn = new disk;
        putIn->setSize(i+1);
        push(putIn);
    }
}

void stack::push(disk *d){
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

disk* stack::pop(){
    if(empty())
        throw EMPTY;
    disk *temp = new disk(*top);
    top = top->getNext();
    --currSize;
    return temp;
}

disk* stack::peek(){
    return top;
}

bool stack::empty(){
    return top == NULL;
}

bool stack::full(){
    return currSize == tot_disks;
}

int stack::sizeOf(){
    return currSize;
}

ostream& operator<<(ostream &out, const stack& s){
    if(&out == &cout){
        out << "Size: " << s.currSize << endl
            << "Number of Disks: " << s.tot_disks << endl
            << "Stack capacity: " << s.tot_disks << endl
            << "Stack Contents: \n";
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

void stack::nukem(){
    currSize = 0;
    top = NULL;
    while(!empty())
        pop();
}





















