#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>


struct Node
{
    std::string data;
    int key;
    Node* left;
    Node* right;

    Node() : left(nullptr), right(nullptr), key(0) {}
    ~Node() {}
    Node(int key, std::string data,
        Node* left = nullptr, Node* right = nullptr)
        : key(key), data(data), left(left), right(right) {}


};

class Tree
{

    Node* root;

public:
    Tree() : root(nullptr) {}
    Tree(Node* NotRoot) : root(NotRoot) {}
    ~Tree() {
        DelAll(root);
    }
    Node*& get_root() { return root; }
    void set_root(Node* NotRoot) { root = NotRoot; }

    Node* SearchByKey(int key, Node* NotRoot)
    {
        //Если дерево пустое, то ключ,
        //который мы ищем, в дереве отсутствует

        /*если ключ совпадает с
        ключом корня, поиск завершился успешно
        и мы возвращаем вершину.*/
        if (NotRoot == nullptr || NotRoot->key == key) return NotRoot;


        /*Если искомый ключ меньше ключа корня,
        продолжаем поиск в левом поддереве.
        Если ключ больше ключа в корне,
        мы ищем в правом поддереве*/
        else if (key < NotRoot->key) SearchByKey(key, NotRoot->left);
        else  SearchByKey(key, NotRoot->right);
    }

    Node* AddKey(int key,std::string data, Node* NotRoot)
    {
        //если корень поменялася
        if (root == nullptr)
        {
            root = new Node(key, data);
            return root;
        }
        if (NotRoot == nullptr) return new Node(key, data);


        if (key < NotRoot->key) NotRoot->left = AddKey(key, data, NotRoot->left);
        else if(key > NotRoot->key) NotRoot->right = AddKey(key, data, NotRoot->right);

        return NotRoot;
    }

    int find_max(Node* NotRoot)
    {
        if (NotRoot->right != nullptr)
            return find_max(NotRoot->right);
        else return NotRoot->key;
    }

    Node* DeleteByKey(int key, Node*& NotRoot)
    {
        if (key == NotRoot->key)
        {
            //Вершина v не имеет поддеревьев,
            //т.е.является листом дерева
            if(NotRoot->left == nullptr && NotRoot->right == nullptr)
            {
                //если эта вершина корень дерева
                if (root == NotRoot)
                {
                    root = nullptr;
                    return nullptr;
                }
                delete NotRoot;
                NotRoot = nullptr;
                return nullptr;
            }

            //У вершины v есть только левое
            //или только правое поддерево
            if (NotRoot->right == nullptr)
            {
                //если эта вершина корень дерева
                if (root == NotRoot)
                {
                    root = NotRoot->left;
                    return nullptr;
                }
                Node* temp = NotRoot->left;
                delete NotRoot;
                return temp;
            }
            if (NotRoot->left == nullptr)
            {
                //если эта вершина корень дерева
                if (root == NotRoot)
                {
                    root = NotRoot->right;
                    return nullptr;
                }
                Node* temp = NotRoot->right;
                delete NotRoot;
                return temp;

            }

            //левое удаление
            if (NotRoot->right != nullptr && NotRoot->left != nullptr)
            {
                int max_key = find_max(NotRoot->left);
                DeleteByKey(max_key, NotRoot);
                NotRoot->key = max_key;
                //надо чтобы дальше не шло
                return nullptr;
            }
        }

        if (key < NotRoot->key) NotRoot->left = DeleteByKey(key, NotRoot->left);
        else if (key > NotRoot->key) NotRoot->right = DeleteByKey(key, NotRoot->right);

        return NotRoot;
    }

    //передача адреса по ссылке
    //обратный
    void DelAll(Node *&NotRoot)
    {
        if (NotRoot != nullptr)
        {
            DelAll(NotRoot->left);
            DelAll(NotRoot->right);
            delete NotRoot;
            NotRoot = nullptr;
        }
    }

    //прямой левый
    void AddToVecForwLeft(const Node* NotRoot, std::vector<std::pair<int,std::string> >& vec )
    {
        if (NotRoot != nullptr)
        {
            vec.push_back(std::make_pair(NotRoot->key, NotRoot->data));
            AddToVecForwLeft(NotRoot->left, vec);
            AddToVecForwLeft(NotRoot->right, vec);
        }
    }

    //обратный левый
    void AddToVecBackLeft(const Node* NotRoot, std::vector<std::pair<int, std::string> >& vec)
    {
        if (NotRoot != nullptr)
        {
            AddToVecBackLeft(NotRoot->left, vec);
            AddToVecBackLeft(NotRoot->right, vec);
            vec.push_back(std::make_pair(NotRoot->key, NotRoot->data));
        }

    }

    //внутренний левый
    void AddToVecInnerLeft(const Node* NotRoot, std::vector<std::pair<int, std::string> >& vec)
    {
        if (NotRoot != nullptr)
        {
            AddToVecInnerLeft(NotRoot->left, vec);
            vec.push_back(std::make_pair(NotRoot->key, NotRoot->data));
            AddToVecInnerLeft(NotRoot->right, vec);
        }
    }

    //внутренний правый
    void AddToVecInnerRight(const Node* NotRoot, std::vector<std::pair<int, std::string> >& vec)
    {
        if (NotRoot != nullptr)
        {
            AddToVecInnerRight(NotRoot->right, vec);
            vec.push_back(std::make_pair(NotRoot->key, NotRoot->data));
            AddToVecInnerRight(NotRoot->left, vec);
        }
    }

    void FindBalance()
    {
        std::vector<std::pair<int, std::string>> vec;

        AddToVecInnerLeft(root, vec);

        DelAll(root);

        int size = vec.size()+1;

        std::vector<std::pair<int, std::string>> ans;

        for (int i = 1; i < size; i *= 2)
                {
                    for (int j = 1,k = 0;k < i;j += 2,k++)
                    {
                        int l = size * j / (2 * i) + (((int)(size * j * 10 / (double)(2 * i)) % 10) >= 5);   //округление

                        ans.push_back(vec[l - 1]);
                    }
                }

        AddFromVec(root, ans);
    }

    void AddFromVec(Node* NotRoot, const std::vector<std::pair<int, std::string>> &vec)
    {
        for(int i = 0; i<vec.size(); i++)
            AddKey(vec[i].first,vec[i].second, root);
    }



};


#endif // TREE_H
