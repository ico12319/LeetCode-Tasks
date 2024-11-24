#pragma once
#include <iostream>
#include <set>


class infinte_set{
private:
    std::set<int> infinite;
    int smallest_popped = 1;
    
public:
    infinte_set() = default;
    int pop_smallest();
    void add_back(int num);
};
