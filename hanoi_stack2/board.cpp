#include "board.h"
#include <iostream>
#include <math.h>

using namespace std;

board::board(){
    rods = new stack[num];
    start = end = NULL;
    num_of_disks = 0;
}

board::~board(){
    for(int i = 0;  i < num; ++i)
        rods[i] = stack();
    delete[] rods;
    start = end = NULL;
}

bool board::complete(){
    return(rods[0].empty() && rods[2].full());
}

bool board::legal(stack& a, stack& b){
    if(a.peek() == NULL)
        return false;
    return((b.peek() == NULL)|| (a.peek()->getSize() < b.peek()->getSize()));
}

void board::load(int s){
    rods[0].inStack(s);
    num_of_disks = s;
    for(int i = 0; i < num; ++i)
        rods[i].setDisks(num_of_disks);
}

void board::moveLeft(int s){
    disk *temp = new disk(*rods[s].pop());
    --s;
    if(s < 0)
        s = 2;
    rods[s].push(temp);
}

void board::moveRight(int s){
    disk *temp = rods[s].pop();
    ++s;
    if(s > 2)
        s = 0;
    rods[s].push(temp);
}

void board::generalMove(stack& s1, stack& s2){
    disk *temp = new disk;
//    if(s1.peek() == NULL)
//        s1.top = new disk;
    if(legal(s1,s2)){
//        cout << "THIS IS LEGAL\n";
        temp = s1.pop();
        s2.push(temp);
    }
    else if(legal(s2, s1)){
//        cout << "THIS IS ALSO LEGAL\n";
        temp = s2.pop();
        s1.push(temp);
    }
}

void board::autoSolve(){
    int moves = pow(2,num_of_disks) - 1 ;
    cout << "This should take "<< moves << " moves.\n";
    if(num_of_disks % 2 == 1){
        for(int i = 1; i <= moves; ++i){
            cout << "MOVE: " << i << " ";
            if(i % 3 == 1)
                generalMove(rods[0], rods[2]);
            if(i % 3 == 2)
                generalMove(rods[0], rods[1]);
            if(i % 3 == 0)
                generalMove(rods[1], rods[2]);
            cout << *this <<  endl;
        }
    }
    else if(num_of_disks % 2 == 0)
        for(int i = 1; i <= moves; ++i){
            cout << "MOVE: " << i << " ";
            if(i % 3 == 1)
                generalMove(rods[0], rods[1]);
            if(i % 3 == 2)
                generalMove(rods[0], rods[2]);
            if(i % 3 == 0)
                generalMove(rods[2],rods[1]);
            cout << *this;

            cout << endl;
        }
}

void board::play(){
    cout << "NOW PLAYING:\n";
    int c1 = -1, c2 = -1;
    char ans;
    cout << *this;
    cout << "Would you like to run AutoSolver (y or n): ";
    cin >> ans;
    if(ans != 'n')
        autoSolve();
    cout << "Woudl you like to play(y or n): ";
    cin >> ans;
    if(ans != 'y')
        exit(1);
        while(c1 < 0 || c1 > 2){
            cout << "Enter stack number you wish to move FROM: ";
            cin >> c1;
            if(c1 < 0 || c1 > 2)
                cout << "OUT OF RANGE: select again\n";
        }
        while(c2 < 0 || c2 > 2){
            cout << "Select stack number you wish to move TO: ";
            cin >> c2;
            if(c2 < 0 || c2 > 2)
                cout << "OUT OF RANGE: select again\n";
        }
        generalMove(rods[c1], rods[c2]);
        cout << *this;
//    }while(complete());

}

ostream& operator<<(ostream& out, const board& b){
    if(&out == &cout){
        out <<  " \n ///////////////////// STACKS_BOARD ///////////////////// \n";
        for(int i = 0; i < b.num; ++i)
            out << "STACK NUMBER: " << i << "::" <<  b.rods[i] << endl;
    }
    out << endl;
    return out;
}
