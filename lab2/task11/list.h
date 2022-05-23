#ifndef LIST_H
#define LIST_H

#include <abitura.h>
#include <QMessageBox>
#include <QDebug>
#include <stdlib.h>
#include <iostream>

struct Node
{
    abitura abiturient;
    Node *next, *prev;
};

class List
{
public:
    List();
    List(QWidget* parent);
    ~List();

    int GetSize();
    Node *GetNode(int i);
    void DelAll();
    void Del(int pos);
    void Insert(int pos, abitura abiturient);
    void AddTail(abitura abiturient);
    void AddHead(abitura abiturient);
    void sortNum(int left, int right);
    void swap(abitura &abit1, abitura &abit2);
    //функция определяет откуда начинать поиск -
    //с головы или с хвоста
    //1  - хвост
    //0 - голова
    Node* HeadOrEnd(int i);

private:
    int size;
    Node *Head, *Tail;
    QWidget *parent;
};



#endif // LIST_H
