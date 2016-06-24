#include "staque.h"

#include <iostream>
using namespace std;

#define RAND (rand()%100+1)
int function(int n);
int main(int argc, char *argv[])
{
//    cout << function(5) << '\n';
//    return 0;

    int StaqueSize = 100;
    Staque staque(StaqueSize);

    staque.print();

    for(int i = 0; i < 51; i++) {
        staque.push(i /* * RAND */);
        staque.enqueue(i /* * RAND */);
    }

    staque.print(/*true*/);
    cout << endl;
    while(!staque.empty()) {
        if(!staque.empty()) cout << staque.count() << " - " << staque.pop()    << endl;
        if(!staque.empty()) cout << staque.count() << " - " << staque.dequeue() << endl;
    }

    return 0;
}

//--------------------------------------------------------
int function(int n)
{
    int intArray[n];
    int arraySum = 0;

    for (int i = 0; i < n; i++)
    {
        intArray[i] = i;
        for(int j = 1; j < n; j++)
        {
            intArray[i] *= j;                       // 1
            cout << intArray[i] << '\t';
        }
        arraySum += intArray[i];                    // 2
        cout << endl;
    }
    return arraySum;
}

//--------------------------------------------------------
int function_Orginal(int n)
{
    int intArray[n];
    int arraySum = 0;

    for (int i = 0;i< n;i++)
    {
        intArray[i] = i;
        for(int j = 1;j<n;j++)
        {
            intArray[i] = j * intArray[i];          // 1
        }
    }

    // 2
    for(int k = 0;k<n;k++)
    {
        arraySum += intArray[k];
    }

    return arraySum;
}
