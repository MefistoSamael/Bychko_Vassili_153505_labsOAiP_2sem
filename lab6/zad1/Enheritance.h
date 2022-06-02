#ifndef ENHERITANCE_H
#define ENHERITANCE_H

#include "Tree.h"
#include <string>

class Enheritance : public Tree
{
public:

    Enheritance() : Tree(){}

    void swap_min_max_keys()
    {
        if (Tree::get_root() == nullptr) return;

        std::vector<std::pair<int, std::string>> vec;
        AddToVecInnerLeft(Tree::get_root(), vec);
        int minInd, maxInd;

        //ключи минимального и максимального
        minInd = vec[0].first;
        maxInd = vec[vec.size() - 1].first;

        //запоминаем данные минимального
        std::string minData = vec[0].second;

        //заменяем
        SearchByKey(minInd,Tree::get_root())->data = SearchByKey(maxInd, Tree::get_root())->data;
        SearchByKey(maxInd, Tree::get_root())->data = minData;
    }


};

#endif // ENHERITANCE_H
