#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <QDebug>
#include <stack>
#include <QString>





class HashTable
{
    const int size;
    std::stack<std::pair<const int,QString>>* arr;

public:

    HashTable() : size(15)
    {
        arr = new std::stack<std::pair<const int,QString>>[size];
    }


    int get_size()
    {
        return size;
    }

    void push(int key, QString str)
    {
        int index = HashFunct(key, size);

        arr[index].push(std::make_pair(key,str));
    }

    int FindStack(int key)
    {
        return HashFunct(key,size);
    }

    QString find(int key)
    {
        int index = HashFunct(key, size);

        std::stack<std::pair<const int,QString>> tmp = arr[index];


        QString ans = "";
        while (!tmp.empty())
        {
            int tmp_key = tmp.top().first;

            if (tmp_key == key) ans+= tmp.top().second;

            tmp.pop();
        }

        return ans;
    }

    void del(int key)
    {
        int index = HashFunct(key, size);

        std::stack<std::pair<const int,QString>> tmp;

        while (!arr[index].empty())
        {
            int tmp_key = arr[index].top().first;

            if (tmp_key == key)
            {
                arr[index].pop();
                break;
            }

            tmp.push(arr[index].top());
            arr[index].pop();
        }

        while (!tmp.empty())
        {
            arr[index].push(tmp.top());

            tmp.pop();
        }
    }

    //вывод стека в кач-ве строки
    QString stack_str(int index)
    {
        QString ans;

        std::stack<std::pair<const int,QString>> tmp = arr[index];

        while (!tmp.empty())
        {
            ans += tmp.top().second + " ";

            tmp.pop();
        }

        return ans;
    }

    //поиск максимального ключа в стеке
    int stack_max(int index)
    {
        int ans = 0;

        std::stack<std::pair<const int,QString>> tmp = arr[index];

        while (!tmp.empty())
        {
            if(tmp.top().first > ans)
                ans = tmp.top().first;

            tmp.pop();
        }

        return ans;
    }

    //данные максимального ключа
    QString max_key_data(int &indexOfStack)
    {
        int ans = 0;

        for(int i = 0;i < 15;i++)
        {
            if(ans < stack_max(i))
            {
                ans = stack_max(i);
                indexOfStack = i;
            }
        }

        return find(ans);
    }



    int HashFunct(int key,int size)
    {
        return ((key + (1000 - 7))<< 7) % size;
    }

    void clean()
    {
        delete[] arr;
        arr = new std::stack<std::pair<const int,QString>>[size];
    }


    ~HashTable()
    {
        delete[] arr;
    }

};






#endif // HASH_H
