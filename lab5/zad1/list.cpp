#include "list.h"
//Создать двухсвязанный список из случайных целых чисел. Удалить из
//списка все элементы, находящиеся между максимальным и
//минимальным.

List::List() : count(0) {}

size_t List::GetCount() { return count; }

std::weak_ptr<Data> List::GetElem(int num)
{
    std::weak_ptr<Data> temp;
    if (num < count / 2)
    {
        temp = Head;
        int i = 1;
        while (i != num)
        {
            temp = temp.lock()->next;
            i++;
        }
    }
    else
    {
        temp = Tail;
        int i = count;
        while (i != num)
        {
            temp = temp.lock()->prev;
            i--;
        }
    }
    return temp;
}

void List::Del(int num)
{
    std::weak_ptr<Data> Del;

    if (count == 1)
    {
        Head.reset();
        Tail.reset();
        count--;
        return;
    }

    if (num == 1)
    {
        Head = Head->next;
        Head->prev.reset();
        count--;
        return;
    }

    if (num == count)
    {
        Tail = Tail.lock()->prev;
        Tail.lock()->next.reset();
        count--;
        return;
    }


    Del = GetElem(num);

    Del.lock()->next->prev = Del.lock()->prev;
    Del.lock()->prev.lock()->next = Del.lock()->next;

    count--;
}

void List::Insert(int num, int newData)
{
    if (count == 0)
    {
        std::shared_ptr<Data> temp(new Data(newData));
        Tail = Head = temp;
        count++;
        return;
    }

    if (num == 1)
    {
        std::shared_ptr<Data> temp(new Data(newData));
        Head->prev = temp;
        temp->next = Head;
        Head = temp;
        count++;
        return;
    }

    if (num == count+1)
    {
        std::shared_ptr<Data> temp(new Data(newData));
        Tail.lock()->next = temp;
        temp->prev = Tail;
        Tail = temp;
        count++;
        return;
    }

    std::shared_ptr<Data> NewElem(new Data(newData));

    std::weak_ptr<Data> temp = GetElem(num);

    NewElem->next = temp.lock()->next;
    NewElem->prev = temp;

    temp.lock()->next = NewElem;

    NewElem->next->prev = NewElem;

    count++;
}

void List::Edit(int num, int newData)
{
    GetElem(num).lock()->data = newData;
}
