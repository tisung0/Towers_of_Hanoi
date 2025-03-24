#include <iostream>

#include "disk.h"

using namespace std;

disk::disk(){
    size = 0;
    next = prev = NULL;
}

disk::disk(const disk& d){
    size = d.size;
    next = prev = NULL;
}

disk::~disk(){
    size = 0;
    next = prev = NULL;
}

bool disk::isBigger(disk *other){
    return size > other->size;
}

disk* disk::getNext(){
    return next;
}

int disk::getSize(){
    return size;
}

int disk::getNextSize(){
    return next->size;
}

int disk::getPrevSize(){
    return prev->size;
}

void disk::setSize(int s){
    size = s;
}

void disk::setNext(disk*other){
    next = other;
    other->prev = this;
}

