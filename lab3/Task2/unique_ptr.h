#pragma once
#include <iostream>
template <typename T>
class unique_ptr
{
private:
    T* ptr;

public:

    unique_ptr(unique_ptr const& other) = delete;
    unique_ptr& operator=(unique_ptr const& other) = delete;
    unique_ptr& operator=(unique_ptr<T>&& other) noexcept;

    unique_ptr(unique_ptr&& other) noexcept;

    unique_ptr();
    unique_ptr(T* ptr);
    ~unique_ptr();
    T& operator*() const ;
    T* operator->() const noexcept ;

    //возвращаем указатель
    T* get() const;


    //высвобождаем значение в указателе
    //и зануляем его
    T* release();

    //заменяем значение в указателе
    void reset(T* p);

    void swap(unique_ptr<T>& other) noexcept;





};

template <typename T>
T&& Move(T& Ptr);
