#ifndef MAP_H
#define MAP_H

#include <memory>
#include <list>

template<class Tk, class Td>
struct Node
{
    std::pair<const Tk, Td> key_data;

    uint8_t height;

    Node<Tk, Td>* parent;

    Node<Tk, Td>* left;
    Node<Tk, Td>* right;

    typename std::list<Node<Tk, Td>*>::iterator it;

    Node(std::pair<Tk, Td> key_data, Node<Tk, Td>* parent = nullptr, Node<Tk, Td>* left = nullptr, Node<Tk, Td>* right = nullptr) :
        key_data(key_data),
        height(1),
        parent(parent),
        left(left),
        right(right) {}

    Node(const Node<Tk, Td>& other, Node<Tk, Td>* prnt = nullptr) :
        key_data(other.key_data),
        height(other.height),
        parent(prnt),

        left((other.left) ?
            new Node<Tk, Td>(*other.left, this) :
            //else
            nullptr),

        right((other.right) ?
            new Node<Tk, Td>(*other.right, this) :
            //else
            nullptr) {}

    Node<Tk, Td>& operator=(const Node<Tk, Td>& other) = delete;

    ~Node()
    {
        delete left, left = nullptr;
        delete right, right = nullptr;

        parent = nullptr;
    }

    Node<Tk, Td>* isolate()
    {
        left = nullptr;
        right = nullptr;

        return this;
    }
};


template<class Tk, class Td>
class Map
{
protected:
    Node<Tk, Td>* root;

    std::list<Node<Tk, Td>*> node_list;

public:

    class Iterator_vert;

    class Iterator_ant;

    Map() :
        root(nullptr),
        node_list() {}

    ~Map()
    {
        delete root;
    }

    Iterator_ant GetRoot()
    {
        return Iterator_ant(root);
    }

    void Clear()
    {
        delete root, root = nullptr;

        node_list.clear();
    }

    size_t size()
    {
        return node_list.size();
    }

    size_t height()
    {
        return height(root);
    }

    bool isEmpty()
    {
        return (size() == 0);
    }

    std::pair<Iterator_vert, bool> Insert(const std::pair<const Tk, Td>& key_data)
    {
        if (root == nullptr)
        {
            root = new Node<Tk, Td>(key_data);

            node_list.push_front(root);
            root->it = node_list.begin();

            return std::make_pair(Iterator_vert(root->it), true);
        }

        Node<Tk, Td>* tmp = root;
        Node<Tk, Td>* prnt = nullptr;

        while (tmp != nullptr)
        {
            prnt = tmp;

            if (key_data.first < tmp->key_data.first)
                tmp = tmp->left;

            else if (key_data.first > tmp->key_data.first)
                tmp = tmp->right;

            else return std::make_pair(Iterator_vert(tmp->it), false);
        }

        tmp = new Node<Tk, Td>(key_data, prnt);

        fix_prnt(key_data.first, prnt, tmp);

        auto it = prnt->it;

        if (tmp->key_data.first < prnt->key_data.first)
            node_list.insert(it, tmp);
        else
            node_list.insert(++it, tmp);

        tmp->it = --it;

        BalanceAll(tmp);

        return std::make_pair(Iterator_vert(tmp->it), true);
    }

    bool Erase(Tk key)
    {
        if(root == nullptr)
            return false;

        auto tmp_for_tmp = Find(key);

        if(tmp_for_tmp == end())
            return false;

        Node<Tk, Td>* tmp = tmp_for_tmp.get_ptr();

        Node<Tk, Td>* prnt = tmp->parent;

        if (tmp->left == nullptr)
        {
            fix_prnt(key, prnt, tmp->right);

            node_list.erase(tmp->it);
            delete tmp->isolate();

            BalanceAll(prnt);
        }
        else if (tmp->right == nullptr)
        {
            fix_prnt(key, prnt, tmp->left);

            node_list.erase(tmp->it);
            delete tmp->isolate();

            BalanceAll(prnt);
        }
        else
        {
            std::pair<const Tk, Td> max = FindMax(tmp->left)->key_data;

            Erase(max.first);

            Node<Tk, Td>* tmp_2 = new Node<Tk, Td>(max, tmp->parent, tmp->left, tmp->right);

            fix_prnt(max.first, tmp->parent, tmp_2);

            if (tmp->left)  tmp->left->parent = tmp_2;
            if (tmp->right) tmp->right->parent = tmp_2;

            *(tmp->it) = tmp_2;
            tmp_2->it = tmp->it;

            delete tmp->isolate();
        }
        return true;
    }

    Iterator_vert Find(Tk key)
    {
        Iterator_ant ant(root);
        if(!ant)
            return end();
        while (ant->first != key)
        {
            if (key < ant->first)
                ant.to_left();

            else if (key > ant->first)
                ant.to_right();

            if (!ant) return end();
        }

        return Iterator_vert(ant);
    }

    Td& operator[] (Tk key)
    {
        Iterator_vert f = Find(key);

        if (f != end()) return f->second;
        else return (Insert(std::make_pair(key, Td()))).first->second;
    }

    Td& at(Td key)
    {
        try
        {
            Iterator_vert f = Find(key);

            if (f != end()) return f->second;
            else throw 0;
        }
        catch (int) {}
    }

    bool Contains(Tk key)
    {
        if (Find(key) != end()) return true;

        return false;
    }

    Iterator_vert begin()
    {
        return Iterator_vert(node_list.begin());
    }

    Iterator_vert end()
    {
        return Iterator_vert(node_list.end());
    }

    class Iterator_vert
    {
    protected:
        typename std::list <Node<Tk, Td>*> ::iterator it;

    public:

        Iterator_vert(typename std::list <Node<Tk, Td>*> ::iterator it) :
            it(it) {}

        Iterator_vert(const Iterator_vert& other) : it(other.it) {}

        Iterator_vert& operator =(Iterator_vert& other)
        {
            this->it = other.it;

            return *this;
        }

        Iterator_vert(Iterator_ant& ant) : it(ant.get_ptr()->it) {}

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


        std::pair<const Tk, Td>& operator*() const noexcept
        {
            return (**it).key_data;
        }

        std::pair<const Tk, Td>* operator->() const noexcept
        {
            return &(**it).key_data;
        }

        Node<Tk, Td>* get_ptr()
        {
            return *it;
        }
    };

    class Iterator_ant
    {
        Node<Tk, Td>* ptr;

    public:

        Iterator_ant(Node<Tk, Td>* n) : ptr(n) {}

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

        std::pair<const Tk, Td>& operator*() const noexcept
        {
            return ptr->key_data;
        }

        std::pair<const Tk, Td>* operator->() const noexcept
        {
            return &(ptr->key_data);
        }

        Node<Tk, Td>* get_ptr()
        {
            return ptr;
        }
    };

private:

    int height(Node<Tk, Td>* n)
    {
        if (n) return n->height;
        else   return 0;
    }

    int h_dif(Node<Tk, Td>* n)
    {
        return height(n->right) - height(n->left);
    }

    void fix_h(Node<Tk, Td>* p)
    {
        int hl = height(p->left);
        int hr = height(p->right);

        p->height = (hl > hr ? hl : hr) + 1;
    }

    void fix_prnt(Tk key, Node<Tk, Td>* prnt, Node<Tk, Td>* brunch)
    {
        if (brunch)
            brunch->parent = prnt;

        if (!prnt)
            root = brunch;

        else if (key < prnt->key_data.first)
            prnt->left = brunch;

        else
            prnt->right = brunch;
    }

    Node<Tk, Td>* RotateRight(Node<Tk, Td>* y)
    {
        Node<Tk, Td>* x = y->left;

        x->parent = y->parent;

        y->left = x->right;

        if (y->left)
            y->left->parent = y;

        x->right = y;

        y->parent = x;

        fix_prnt(x->key_data.first, x->parent, x);

        fix_h(x);
        fix_h(y);

        return x;
    }

    Node<Tk, Td>* RotateLeft(Node<Tk, Td>* y)
    {
        Node<Tk, Td>* x = y->right;

        x->parent = y->parent;

        y->right = x->left;

        if (y->right)
            y->right->parent = y;

        x->left = y;

        y->parent = x;

        fix_prnt(x->key_data.first, x->parent, x);

        fix_h(x);
        fix_h(y);

        return x;
    }

    Node<Tk, Td>* Balance(Node<Tk, Td>* n)
    {
        fix_h(n);
                                                                                        /*                                        Simple Rotation                                                */
        if (h_dif(n) == 2)                                                              /*                             y                                       x                                 */
        {                                                                               /*                            / \         Right Rotation(y)           / \                                */
            if (h_dif(n->right) < 0)                                                    /*                          x   T3           -------->               T1  y                               */
                n->right = RotateRight(n->right);                                       /*                         / \               <--------                  / \                              */
                                                                                        /*                       T1  T2           Left Rotation(x)             T2  T3                            */
            return RotateLeft(n);
        }
                                                                                        /*                                        Double rotation                                                */
        if (h_dif(n) == -2)                                                             /*          z                                     z                                        x             */
        {                                                                               /*         / \                                   / \                                     /   \           */
            if (h_dif(n->left) > 0)                                                     /*        T1   y        Right Rotate (y)       T1   x           Left Rotate(z)          z     y          */
                n->left = RotateLeft(n->left);                                          /*            / \          --------->              /  \           -------->            / \   / \         */
                                                                                        /*           x   T4                               T2   y                              T1 T2 T3  T4       */
            return RotateRight(n);                                                      /*          / \                                       /  \                                               */
        }                                                                               /*         T2  T3                                    T3   T4                                             */
        return n;
    }

    void BalanceAll(Node<Tk, Td>* n)
    {
        while (n != nullptr)
        {
            n = Balance(n)->parent;
        }
    }

    Node<Tk, Td>* FindMin(Node<Tk, Td>* n)
    {
        while (n->left != nullptr)
            n = n->left;

        return n;
    }

    Node<Tk, Td>* FindMax(Node<Tk, Td>* n)
    {
        while (n->right != nullptr)
            n = n->right;

        return n;
    }
};

#endif // MAP_H
