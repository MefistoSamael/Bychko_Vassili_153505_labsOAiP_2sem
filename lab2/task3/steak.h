#ifndef STEAK_H
#define STEAK_H
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <conio.h>
#include <stack>

struct Digit
{
    double x;
    Digit *prev;
};

class Stack  //хуетайцкцукнкгаптсммычвфауеркнопатбзддл()
{
    Digit* top;

    int Length;

public:

    Stack();

    ~Stack();

    int GetLength();

    double Top();

    void Clean();

    void Pop();

    void Push(double n);

    bool IsEmpty();
};

#endif // STEAK_H
