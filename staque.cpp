#include "staque.h"

#include <iostream>
using namespace std;

/*
Basic Rules :
    Stack : LIFO
    Queue : FIFO
------------------------------------------
            rear = top    front
                 |        |
IN :             9876543210   : OUT
            ---------------
enqueue ->       0000000000   -> dequeue
push    ->
pop     <-
            ---------------
------------------------------------------
*/

Staque::~Staque() { delete[] staque; }
Staque::Staque() : Staque(100) {}
Staque::Staque(int size)
{
    _size   = size;
    _top    = -1;
    _front  = -1;
    staque  = new int[_size];
}

int Staque::size()
{ return _size; }

int Staque::count()
{
    return _top - _front + 1;
}

bool Staque::empty()
{
    return  _top == -1 || _top == _front;
}

bool Staque::full()
{
    return _top - _front == _size;
}

int Staque::top()
{
    if(!empty())
        return staque[_top];
    else
        return 0;
}

void Staque::push(int e)
{
    if(!full()) {
        staque[++_top] = e;
    } else {
        cout << "staque is full." << endl;
    }
}

int Staque::pop()
{
    int m = 0;
    if(!empty()) {
        m = staque[_top--];
    } else {
        cout << "staque is empty." << endl;
    }
    return m;
}

int Staque::rear()
{ return top(); }

void Staque::enqueue(int e)
{ push(e); }

int Staque::dequeue()
{
    int m = 0;
    if(!empty()) {
        m = staque[++_front];
    } else {
        cout << "staque is empty." << endl;
    }
    return m;
}

void Staque::print(bool horizontal)
{
    if(empty()) {
        cout << "staque is empty." << endl;
        return;
    }
    for(int i = (_front == -1 ? 0 : _front); i <= _top; i++) {
        if(horizontal)
            cout << staque[i] << ' ';
        else
            cout << i << '-' << staque[i] << endl;
    }
    cout << (horizontal ? "\n" : "");
}
