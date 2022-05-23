#ifndef LIST_H
#define LIST_H
#include<memory>

struct Data
{
    int data;
    std::shared_ptr<Data> next;
    std::weak_ptr<Data> prev;

    Data(int X) : data(X), next(), prev() { }
};

class List
{
    std::shared_ptr<Data> Head;
    std::weak_ptr<Data> Tail;
    size_t count;

public:
    List();
    ~List() = default;

    size_t GetCount();
    std::weak_ptr<Data> GetElem(int num);
    void Del(int num);
    void Insert(int num, int newData);
    void Edit(int num, int newData);;
};


#endif // LIST_H
