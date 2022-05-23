#include "steak.h"

using namespace std;

Stack::Stack()
{
    top = 0;
    Length = 0;
}

Stack::~Stack()
{
    Clean();
}

bool Stack::IsEmpty()
{
    return (Length == 0);
}

void Stack::Push(double n)
{
    Digit* temp = new Digit;

    temp->x = n;
    temp->prev = top;

    if (Length == 0)
        top = temp;
    else
        top = temp;

    Length++;
}

void Stack::Pop()
{
    if (IsEmpty())
        return;

    Digit* Del = top;

    Digit* PrevDel = Del->prev;

    top = PrevDel;

    delete Del;

    Length--;
}

void Stack::Clean()
{
    while (!IsEmpty())
        Pop();
}

int Stack::GetLength()
{
    return Length;
}

double Stack::Top()
{
    return top->x;
}
