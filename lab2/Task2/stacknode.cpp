#include <stacknode.h>


StackNode::StackNode(Skobka skobka, unique_ptr<StackNode> _next)
    {
        this->skobka = skobka;
        next = Move(_next);
    }
