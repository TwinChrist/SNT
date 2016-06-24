#ifndef STAQUE_H
#define STAQUE_H


class Staque
{
    int _size;
    int _top;
    int _front;
    int *staque;
public:
   ~Staque();
    Staque();
    Staque(int size);

    int  size();        // maximim size of the array
    int  count();       // count of the element(s) in array

    bool empty();       // isEmpty
    bool full();        // isFull

    void push(int e);   // push
    int  top();         // get the recent appended element value
    int  pop();         // get top element and remove the top element

    int rear();         // get the recent appended element value
    void enqueue(int e);
    int dequeue();

    void print(bool horizontal = false);
};

#endif // STAQUE_H
