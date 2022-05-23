#ifndef LISTHUINI_H
#define LISTHUINI_H
#include "player.h"
#include "team.h"
#include <QString>
#include <QWidget>
#include <QDebug>

struct NodeHuini
{
    Player play;
    int next, prev;
};

class ListHuini
{
public:
    ListHuini();
    ~ListHuini();
    int GetSize();
    NodeHuini GetNodeHuini(int i);
    void SetPlayerInNodeHuini(int i, Player play);
    void DelAll();
    void Del(int pos);
    void Insert(int pos, Player play);
    void AddTail(Player play);
    void AddHead(Player play);
    void sortNum(int left, int right);
    void swap(int play, int play2);
    void QSort(int begin, int end);
    //функция определяет откуда начинать поиск -
    //с головы или с хвоста
    //1  - хвост
    //0 - голова
    int HeadOrEnd(int pos);

private:
    int size;
    int Head, Tail;
    NodeHuini *L;
};

#endif // LISTHUINI_H
