#ifndef STACK_H
#define STACK_H
#include "stacknode.h"
#include <QWidget>

struct Stack
{
    unique_ptr<StackNode> head;//указатель на верхний эллемент стэка
    int curSize;

    //конструктор вызывается при создании объекта структуры. И выполняет указанные ему действия
    //используется как правило для инициализации переменных
    Stack();

    ~Stack();

};

//добавление элемента в стек
void push(Skobka skobka, Stack* mStack, QWidget *parent);

//удаление элемента из стека
QString pop(Stack* mStack,int curSize);

//просмотр верхнегоо элемента стека
QString top(Stack* mStack,int curSize,  QWidget *parent);

//чистка стека
void clean(Stack* mStack,int curSize);

#endif // STACK_H
