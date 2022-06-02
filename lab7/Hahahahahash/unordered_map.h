#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <forward_list>
#include <QTableWidgetItem>
#include <string>

template <class Tk, class Td, class Hash = std::hash<Tk>>
class Unordered_Map
{
    using key_data_list_t = std::forward_list<std::pair<const Tk, Td>>;
    using key_data_list_iterator_t = typename std::forward_list<std::pair<const Tk, Td>>::iterator;

    key_data_list_t* array;

    int count;
    int count_list;

    double max_load_factor;

    Hash hs;

public:

    Unordered_Map() :
        array(new key_data_list_t[4]),
        count(0),
        count_list(4),
        max_load_factor(1) {}

    ~Unordered_Map()
    {
        delete[] array, array = nullptr;
    }

    key_data_list_iterator_t find(Tk key)
    {
        size_t ind = hs(key) % count_list;

        for (auto i = array[ind].begin(); i != array[ind].end(); ++i)
        {
            if (i->first == key)
                return i;
        }
        return array[ind].end();
    }

    key_data_list_iterator_t insert(std::pair<Tk,Td> key_data)
    {
        size_t ind = hs(key_data.first) % count_list;

        if (contains(key_data.first)) return array[ind].end();

        array[ind].push_front(key_data);
        count++;

        auto it = array[ind].begin();

        rehash();

        return it;
    }

    void Rewrite(QTableWidget* tableWidget)
    {
        QTableWidgetItem* item;
        for(int i = 0;i < count_list;i++)
        {
            QString ind;
            ind.setNum(i);
            item = new QTableWidgetItem(ind);
            tableWidget->setItem(i,0,item);

            std::string ansKey;
            std::string ansValue;

            for(auto it = array[i].begin(); it != array[i].end(); it++)
            {
                ansKey += QString::number(it->first).toStdString() + " ";
                ansValue +=it->second + " ";
            }

            item = new QTableWidgetItem(QString::fromStdString(ansKey));
            tableWidget->setItem(i,1,item);

            item = new QTableWidgetItem(QString::fromStdString(ansValue));
            tableWidget->setItem(i,2,item);
        }
    }

    void erase(Tk key)
    {
        size_t ind = hs(key) % count_list;

        auto temp = array[ind].before_begin();
        auto i = array[ind].begin();

        for (; i != array[ind].end() && i->first != key; ++i, ++temp) {}

        array[ind].erase_after(temp);
        count--;
    }

    bool contains(Tk key)
    {
        size_t ind = hs(key) % count_list;

        if (find(key) != array[ind].end()) return true;
        else return false;
    }

    void rehash()
    {
        if ((double)count / count_list <= max_load_factor) return;

        count_list *= 2;

        key_data_list_t* temp(new key_data_list_t[count_list]);

        size_t ind;
        for (int i = 0; i < count_list / 2; i++)
        {
            for (auto k = array[i].begin(); k != array[i].end();k = array[i].begin())
            {
                ind = hs(k->first) % count_list;
                temp[ind].splice_after(temp[ind].before_begin(), array[i], array[i].before_begin());
            }
        }

        delete[] array;
        array = temp;
    }

    void clear()
    {
        delete[]array;
        array = new key_data_list_t[4];
        count = 0;
        count_list = 4;
    }


    Td& operator[](Tk key)
    {
        size_t ind = hs(key) % count_list;

        auto it = find(key);

        if (it != array[ind].end())
            return it->second;

        else
            return insert(std::make_pair(key, Td()))->second;
    }

    Td& at(Td key)
    {
        try
        {
            size_t ind = hs(key) % count_list;

            auto it = find(key);

            if (it != array[ind].end())
                return it->second;

            else throw 0;
        }
        catch (int) {}
    }

};


#endif // UNORDERED_MAP_H
