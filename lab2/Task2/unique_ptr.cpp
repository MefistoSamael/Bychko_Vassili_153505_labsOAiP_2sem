#pragma once

#include <iostream>
#include "unique_ptr.h"

    template <typename T>
    unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>&& other) noexcept
    {
        reset(other.release());
        return *this;
    }

    template <typename T>
    unique_ptr<T>::unique_ptr (unique_ptr&& other) noexcept : ptr(other.release()){}

    template <typename T>
    unique_ptr<T>::unique_ptr()
        : ptr(nullptr)
    {
       // std::cout << "constuctor\n";
    }

    template <typename T>
    unique_ptr<T>::unique_ptr(T* ptr)
        : ptr(ptr)
    {
        //std::cout << "constuctor value\n";
    }

    template <typename T>
    unique_ptr<T>::~unique_ptr()
    {
       //std::cout << "destructor\n";
        delete ptr;
    }

    template <typename T>
    T& unique_ptr<T>::operator*() const
    {
        return *ptr;
    }

    template <typename T>
    T* unique_ptr<T>::operator->() const noexcept
    {
        return ptr;
    }


    //возвращаем указатель
    template <typename T>
    T* unique_ptr<T>::get() const
    {
        return ptr;
    }

    //высвобождаем значение в указателе
    //и зануляем его
    template <typename T>
    T* unique_ptr<T>::release()
    {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    //заменяем значение в указателе
    template <typename T>
    void unique_ptr<T>::reset(T* p)
    {
        delete ptr;
        ptr = p;
    }

    template <typename T>
    void unique_ptr<T>::swap(unique_ptr<T>& other) noexcept
    {
        std::swap(ptr, other.ptr);
    }

template <typename T>
T&& Move (T& obj)
{
    return static_cast<T&&>(obj);
}
