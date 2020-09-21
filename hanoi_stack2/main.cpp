#include <iostream>
#include <time.h>
#include "board.h"

using namespace std;

void ins(int& x);

int main(){
    clock_t t = clock();
    board b1;
    int x = 0;
    ins(x);
    b1.load(x);
    do{
        b1.play();
    }while(!b1.complete());

    t = clock() - t;
    cout << "time elapsed: " << ((float)t)/CLOCKS_PER_SEC << "seconds" << endl;

    return 0;
}

void ins(int& x){
    cout << "TOWER OF HANOI __ STACK IMPLEMENTED\n\n";
    cout << "Please enter the number of disks you would like: ";
    cin >> x;
}
