#include "listhuini.h"

ListHuini::ListHuini()
{
    Head = Tail = -1;
    L = new NodeHuini[0];
    size = 0;
}

ListHuini::~ListHuini()
{
    DelAll();
 delete[] L;
}

int ListHuini::GetSize()
{
    return size;
}

NodeHuini ListHuini::GetNodeHuini(int pos)
{
    int search;
    NodeHuini temp;
    if (pos < size/2)
    {
        search = Head;
        for (int i = 1; i<pos;i++)
           search = L[search].next;
        return L[search];
    }
    else
    {
        search = Tail;
        for (int i = size; i>pos; i--)
            search = L[search].prev;
        return L[search];
    }


}

void ListHuini::SetPlayerInNodeHuini(int pos, Player play)
{
    int search = Head;
    for (int i = 1; i< pos; i++)
        search = L[search].next;

    L[search].play = play;
}

void ListHuini::DelAll()
{
    if (size == 0) return;

    for (int i = 1; i<=size; i++)
        Del(i);
}

void ListHuini::Del(int pos)
{
    //индекс удаляемого элемента в массиве
    int indexOfDelElem;
    if (pos < 1 || pos > size) return;
    qDebug() <<"Head1 " <<Head;
    int Del;


    Del = Head;
    for (int i = 1; i< pos; i++)
        Del = L[Del].next;
    qDebug() <<"Head2 " <<Head;

    int PrevDel = L[Del].prev;
    indexOfDelElem = Del;
    int AfterDel = L[Del].next;

    if (PrevDel != -1 && size != 1)
        L[PrevDel].next = AfterDel;

    if (AfterDel != -1 && size != 1)
        L[AfterDel].prev = PrevDel;

    if (pos == 1)
        Head = AfterDel;
    qDebug() <<"Head3 " <<Head;

    if (pos == size)
        Tail = PrevDel;


    NodeHuini* tempHuini = new NodeHuini[size-1];

    if (Tail> indexOfDelElem)
    {
        Tail--;
    }
    if (Head> indexOfDelElem)
    {
        Head--;
    }

    for (int i = 0, j = 0; i<size; i++)
    {
        if (i == indexOfDelElem)
        {
            continue;
        }
        tempHuini[j] = L[i];
        if (tempHuini[j].prev > indexOfDelElem)
        {
            tempHuini[j].prev--;
        }
        if (tempHuini[j].next > indexOfDelElem)
        {
            tempHuini[j].next--;
        }
        j++;
    }
    qDebug() <<"Head4 " <<Head;


    delete[] L;
    L = tempHuini;
    size--;

}

void ListHuini::Insert(int pos, Player play)
{

    //индекс поиска
    int search;

    //если добавление в конец или в нчало
    if (pos == 1)
    {
        AddHead(play);
        return;
    }
    if (pos == size+1)
    {
        AddTail(play);
        return;
    }
    NodeHuini* tempHuini = new NodeHuini[size+1];
    for (int i = 0; i<size;i++)
        tempHuini[i]=L[i];
    delete [] L;
    L = tempHuini;


    search = Head;
    for (int i = 1; i < pos; i++)
        search = L[search].next;

    NodeHuini temp;
    temp.play = play;


    int prevIns = L[search].prev;


    if (prevIns != -1 && size != 1)
        L[prevIns].next = size;

    temp.next = search;
    temp.prev = prevIns;
    L[search].prev = size;

    L[size] = temp;
    size++;


}

void ListHuini::AddTail(Player play)
{
    //увеличиваем размер списка и переносим все значения
    NodeHuini *temp = new NodeHuini[size+1];
    for(int i = 0; i<size;i++)
        temp[i] = L[i];

    delete [] L;
    L = temp;

    //заносим значения в узел
    NodeHuini tempHuini;
    tempHuini.play = play;

    //следующего элемента нет
    tempHuini.next = -1;

    //предыдущий элемент - бывший хвост
    tempHuini.prev = Tail;

    //если были элементы до этого
    if (Tail != -1)
        L[Tail].next = size;

    //если элемент первый
    if (size == 0)
        Head = Tail = 0;
    else
        Tail = size;

    L[size] = tempHuini;
    size++;

}

void ListHuini::AddHead(Player play)
{
    //увеличиваем размер списка и переносим все значения
    NodeHuini *temp = new NodeHuini[size+1];
    for(int i = 0; i<size;i++)
        temp[i] = L[i];
    delete [] L;
    L = temp;

    //заносим значение в узел
    NodeHuini tempHuini;
    tempHuini.play = play;

    //предыдущего эллемента нет
    tempHuini.prev = -1;
    //следующий равен бывшей голове
    tempHuini.next = Head;

    //если элементы были до этого
    if(Head != -1)
        //в голову
        L[Head].prev = size;

    //если элемент первый
    if (size == 0)
        Head = Tail = 0;
    else
        Head = size;
    L[size] = tempHuini;

    size++;



}

void ListHuini::sortNum(int left, int right)
{
    int opor = GetNodeHuini((left + right) / 2).play.get_age();
    int l = left, r = right;
    while(l <= r)
    {
        while(GetNodeHuini(l).play.get_age() < opor) l++;
        while(GetNodeHuini(r).play.get_age() > opor) r--;
        if(l <= r)
        {
            swap(l, r);
            l++;
            r--;
        }
    }
    if(left < r) sortNum(left, r);
    if(l < right) sortNum(l, right);

}

void ListHuini::swap(int play, int play2)
{
    Player temp;
    temp = L[play].play;
    L[play].play = L[play2].play;
    L[play2].play = temp;
}

int ListHuini::HeadOrEnd(int pos)
{
    if (pos <= size/2) return Head;
    else return Tail;
}

void ListHuini::QSort(int begin, int end)
{
    if (size == 0)
        return;

    if (begin == -1 && end == -1)
    {
        begin = 1;
        end = size;
    }

    int l = begin;
    int r = end;
    int C = (begin + end) / 2;

    int Centr = Head;

    for (int i = 1; i < C; i++)
        Centr = L[Centr].next;

    int c = L[Centr].play.get_age();

    while (l <= r)
    {
        int A = Head;

        for (int i = 1; i < l; i++)
            A = L[A].next;

        while (L[A].play.get_age() > c)
        {
            l++;
            A = L[A].next;
        }

        int B = Tail;

        for (int i = size; i > r; i--)
            B = L[B].prev;


        while (L[B].play.get_age() < c)
        {
            r--;
            B = L[B].prev;
        }

        if (l <= r)
        {
            swap(A, B);

            l++, r--;
        }
    }

    if (begin < r)
        QSort(begin, r);

    if (l < end)
        QSort(l, end);
}
