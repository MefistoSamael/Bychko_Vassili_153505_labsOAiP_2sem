#ifndef SET_H
#define SET_H


#include "Map.h"


template <class Tk>
class Set : public Map<Tk, char>
{
public:
    class Iterator_vert;

    bool Insert(Tk key)
    {
        return Map<Tk, char>::Insert(std::make_pair(key, char())).second;
    }

    const Tk& operator [](Tk key)
    {
        auto f = Map<Tk, char>::Find(key);

        if (f != Map<Tk, char>::end()) return f->first;
        else return (Map<Tk, char>::Insert(std::make_pair(key, char()))).first->first;
    }

    Tk& at(Tk key)
    {
        try
        {
            auto f = Find(key);

            if (f != this->end()) return f->first;
            else throw 0;
        }
        catch (int) {}
    }

    Iterator_vert begin()
    {
        return Iterator_vert(Map<Tk, char>::node_list.begin());
    }

    Iterator_vert end()
    {
        return Iterator_vert(Map<Tk, char>::node_list.end());
    }

    class Iterator_vert
    {
        typename std::list <Node<Tk, char>*> ::iterator it;
    public:
        Iterator_vert(typename std::list <Node<Tk, char>*> ::iterator it) :
            it(it) {}

        Iterator_vert(const Iterator_vert& other) : it(other.it) {}

        Iterator_vert& operator =(Iterator_vert& other)
        {
            this->it = other.it;

            return *this;
        }

        ~Iterator_vert() {}


        bool operator ==(const Iterator_vert& other) const noexcept
        {
            return this->it == other.it;
        }

        bool operator !=(const Iterator_vert& other) const noexcept
        {
            return this->it != other.it;
        }


        Iterator_vert& operator++()
        {
            it++;

            return *this;
        }

        Iterator_vert operator++(int) noexcept
        {
            Iterator_vert tmp = *this;
            ++(*this);

            return tmp;
        }


        Iterator_vert& operator--()
        {
            it--;

            return *this;
        }

        Iterator_vert operator--(int) noexcept
        {
            Iterator_vert tmp = *this;
            --(*this);

            return tmp;
        }


        const Tk& operator*() const noexcept
        {
            return (**it).key_data.first;
        }

        Tk* operator->() const noexcept
        {
            return &(**it).key_data.first;
        }
    };

    class Iterator_ant
    {
        Node<Tk, char>* ptr;

    public:

        Iterator_ant(Node<Tk, char>* n) : ptr(n) {}

        Iterator_ant(const Iterator_ant& other) : ptr(other.ptr) {}

        Iterator_ant& operator =(Iterator_ant& other)
        {
            this->ptr = other.ptr;

            return *this;
        }

        Iterator_ant(const Iterator_vert& vert) : ptr(vert.get_ptr()) {}

        ~Iterator_ant() {}

        bool operator ==(const Iterator_ant& other) const noexcept
        {
            return this->ptr == other.ptr;
        }

        bool operator !=(const Iterator_ant& other) const noexcept
        {
            return this->ptr != other.ptr;
        }

        Iterator_ant left()
        {
            return Iterator_ant(ptr->left);
        }

        Iterator_ant right()
        {
            return Iterator_ant(ptr->right);
        }

        Iterator_ant parent()
        {
            return Iterator_ant(ptr->parent);
        }

        Iterator_ant& to_left()
        {
            ptr = ptr->left;

            return *this;
        }

        Iterator_ant& to_right()
        {
            ptr = ptr->right;

            return *this;
        }

        Iterator_ant& to_parent()
        {
            ptr = ptr->parent;

            return *this;
        }

        operator bool()
        {
            return(ptr != nullptr);
        }

        Tk& operator*() const noexcept
        {
            return ptr->key_data.first;
        }

        Tk* operator->() const noexcept
        {
            return &(ptr->key_data.first);
        }
    };
};


#endif // SET_H
