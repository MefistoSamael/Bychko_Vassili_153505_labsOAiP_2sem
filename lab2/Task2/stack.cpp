#include "stack.h"
#include "stacknode.h"
#include <QWidget>
#include <QMessageBox>
#include "unique_ptr.cpp"

Stack::Stack()
{
    curSize = 0;
}

Stack::~Stack()
{
    clean(this, curSize);
}




void push(Skobka skobka, Stack* mStack, QWidget *parent)
{
    unique_ptr<StackNode> tempNode (new StackNode(skobka, mStack->head.release()));//создается объект структуры StackNode который указывает на верхний элемент
    mStack->head = Move(tempNode);//перемещаем указатель верхнего эллемента в стеке на новый элемент
    mStack->curSize++;//увеличиваем размер
}



//функция возвращает QString для уобства установки строки и столбца в лейблы
QString pop(Stack* mStack,int curSize)//функция удаления элемента из стека. Возвращает значение удаленного элемента
{
    //если размер равен нулю

    unique_ptr<StackNode> tempNode;
    tempNode = Move(mStack->head);//создаем объект stacknode указывающий на верхний эллемент в стеке
    Skobka skobka = tempNode->skobka;//получаем значение верхнего элемента
    mStack->head = Move(tempNode->next);//в верхний элемент передаем значение следующего элемента
    mStack->curSize--;//уменьшаем размер

    return QString::number(skobka.row) + " " + QString::number(skobka.column);//возвращаем значение
}



QString top(Stack *mStack, int curSize, QWidget *parent)
{
    //если размер равен нулю
    if (!curSize)
    {
        QMessageBox::information(parent, "","Стек пуст top");
        return "";
    }

    //возвращаем значение верхнего элемента
    return mStack->head->skobka.symb;
}

void clean(Stack *mStack, int curSize)
{
    //если размер равен нулю

    //в цикле полностью чистим стек
    for(int i = 0; i<curSize;i++)
        pop(mStack, curSize);
}
