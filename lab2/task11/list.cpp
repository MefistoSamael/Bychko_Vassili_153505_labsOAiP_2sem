#include "list.h"

List::List()
{
    Head = Tail = NULL;
    size = 0;
}

List::List(QWidget *parent)
{
    Head = Tail = NULL;
    size = 0;
    this->parent = parent;
}

List::~List()
{
    DelAll();
}

int List::GetSize()
{
    return size;
}

Node *List::GetNode(int pos)
{
    if (pos > size || pos < 1)
    {
        QMessageBox::information(parent, "GetNode","Полчучение несуществующей ячейки");
        return nullptr;
    }


    int i = 0;
    Node *temp = HeadOrEnd(pos);
    //если мы начинаем с конца
    if (temp->next == NULL)
    {
        i = size;
        while (i != pos && temp != 0)
        {
            temp= temp->prev;
            i--;
        }
    }
    //если мы начинаем с начала
    else if (temp->prev == NULL)
    {
        i = 1;
        while (i != pos && temp != 0)
        {
            temp = temp->next;
            i++;
        }
    }



    if (temp == 0)
        return 0;
    else
        return temp;
}

void List::Del(int pos)
{
    if (pos > size || pos < 1)
    {
        QMessageBox::information(parent, "Del","Полчучение несуществующей ячейки");
        return;
    }


    int i = 0;
    Node *temp = HeadOrEnd(pos);


    //если начинаем с конца
    if (temp->next == NULL)
    {
        i = size;
        while (i != pos)
        {
            temp= temp->prev;
            i--;
        }
    }
    //если мы начинаем с начала
    else if (temp->prev == NULL)
    {
        i = 1;
        while (i != pos)
        {
            temp = temp->next;
            i++;
        }
    }


    Node* PredDel = temp->prev;
    Node* NextDel = temp->next;

    //если удаляем не голову
    if (i != 1 && temp->prev != 0)
    {
        PredDel->next = NextDel;
    }

    //если удаляем не хвост
    if (i != size && temp->next != 0)
    {
        NextDel->prev = PredDel;
    }

    if (i == 1) Head = NextDel;
    if (i == size) Tail = PredDel;

    delete temp;
    size--;
}

void List::Insert(int pos, abitura abiturient)
{
    if (pos > size+1 || pos < 1)
    {
        QMessageBox::information(parent, "Insert","Полчучение несуществующей ячейки");
        return;
    }

    //если добвадение в конец списка
    if (pos == size + 1)
    {
        AddTail(abiturient);
        return;
    }
    //если добавление в начало списка
    else if (pos == 1)
    {
        AddHead(abiturient);
        return;
    }


    Node *Ins = HeadOrEnd(pos);
    //Ins == Tail
    if (Ins->next == NULL)
    {
        int i = size;
        while (i > pos)
        {
            Ins= Ins->prev;
            i--;
        }
    }
        else if (Ins->prev == NULL)
        {
        int i = 1;
        while (i < pos)
        {
            Ins = Ins->next;
            i++;
        }
        }
        Node *temp = new Node;
        temp->abiturient = abiturient;
        Node *PrevIns = Ins->prev;

        if(PrevIns != 0 && size != 1)
            PrevIns->next = temp;

        temp->next = Ins;
        temp->prev = PrevIns;
        Ins->prev = temp;

        size++;

}

void List::AddTail(abitura abiturient)
{
    Node *temp = new Node;
    temp->abiturient = abiturient;

    temp->prev = Tail;
    temp->next = 0;

    if (Tail != 0)
        Tail->next = temp;

    if (size == 0)
        Head = Tail = temp;
    else
        Tail = temp;
    size++;



}

void List::AddHead(abitura abiturient)
{
    Node *temp = new Node;
    temp->abiturient = abiturient;

    temp->prev = 0;
    temp->next = Head;
    if (Head != 0)
        Head->prev = temp;

    if (size == 0)
        Head = Tail = temp;
    else
        Head = temp;
    size++;
}

void List::sortNum(int left, int right)
{
    double opor = GetNode((left + right) / 2)->abiturient.get_average();
    int l = left, r = right;
    while(l <= r)
    {
        while(GetNode(l)->abiturient.get_average() < opor) l++;
        while(GetNode(r)->abiturient.get_average() > opor) r--;
        if(l <= r)
        {
            swap(this->GetNode(l)->abiturient, this->GetNode(r)->abiturient);
            l++;
            r--;
        }
    }
    if(left < r) sortNum(left, r);
    if(l < right) sortNum(l, right);
}

void List::swap(abitura &abit1, abitura &abit2)
{
    abitura temp;

    temp = abit1;
    abit1 = abit2;
    abit2 = temp;
}

void List::DelAll()
{
    while(size != 0)
        Del(1);
}

Node* List::HeadOrEnd(int i)
{
    if (i >= size/2) return Tail;
    else return Head;
}


