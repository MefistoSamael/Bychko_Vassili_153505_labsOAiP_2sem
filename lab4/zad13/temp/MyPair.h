#pragma once
#include <iostream>
#include <type_traits> //is_constructible

template<typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;

    //конструктор по умолчанию
    Pair() : first(), second()
    {
    }

    //конструктор копирования
    Pair(const Pair& another) = default;

    //конструктор перемещения
    Pair(Pair&&) = default;

    //конструктор копирования для пар с разными
    //типами ?
    //static_cast следит за возможностью конвертации
    template<typename Other1, typename Other2>
    Pair(const Pair<Other1, Other2>& Right)
    {
        first = static_cast<T1> (Right.first);
        second = static_cast<T2> (Right.second);
    }

    //конструктор перемещения для пар с разными
    //типами ?
    //static_cast следит за возможностью конвертации
    template<typename Other1, typename Other2>
    Pair(const Pair<Other1, Other2>&& Right)
    {
        first = static_cast<T1> (Right.first);
        second = static_cast<T2> (Right.second);
    }

    //копирование значений 
    Pair(const T1& Val1, const T2& Val2)
    {
        first = Val1;
        second = Val2;
    }

    //перемещение значений
    Pair(T1&& Val1, T2&& Val2)
    {
        first = Val1;
        second = Val2;
    }

    Pair& operator= (const Pair& p)
    {
        first = p.first;
        second = p.second;
        return *this;
    }

    template<typename Other1, typename Other2>
    Pair& operator= (const Pair<Other1, Other2>& p)
    {
        std::cout << "hui\n";
        first = static_cast<T1> (p.first);
        second = static_cast<T2> (p.second);
        return *this;

    }


    Pair& operator= (Pair&& p)
    {
        first = p.first;
        second = p.second;
        return *this;
    }

    template<typename Other1, typename Other2>
    Pair& operator= (Pair<Other1, Other2>&& p)
    {
        first = static_cast<T1> (p.first);
        second = static_cast<T2> (p.second);
        return *this;

    }



    bool operator> ( Pair& c)
    {
        if (first > c.first) return true;

        if (first < c.first) return false;

        if (second > c.second) return true;

        return false;
    }


    bool operator< ( Pair& c)
    {
        if (first < c.first) return true;

        if (first > c.first) return false;

        //if (second < c.second) return true;

        return false;
    }

    bool operator>= ( Pair& c2)
    {
        return (*this == c2 || *this > c2);
    }

    bool operator<= ( Pair& c2)
    {
        return (*this == c2 || *this < c2);
    }

};

template <typename T1, typename T2>
Pair<T1, T2> make_Pair(T1 a, T2 b)
{
    Pair<T1, T2> p(a, b);
    return p;
}


