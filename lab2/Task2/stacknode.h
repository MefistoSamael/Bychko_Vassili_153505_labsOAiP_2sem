#ifndef STACKNODE_H
#define STACKNODE_H

#include <skobka.h>
#include "unique_ptr.h"

struct StackNode
{
    Skobka skobka;//значение помещаемое в стек
    unique_ptr<StackNode> next;//указатель на следующий эллемент в стеке

    StackNode(Skobka skobka, unique_ptr<StackNode> _next);

};

#endif // STACKNODE_H
