#pragma once
#include <iostream>
#include <set>
#include <map>

class number_contaner{
private:
    std::map<int,std::set<int>> map;
    std::unordered_map<int, int> ind_nums;
    
public:
    number_contaner() = default;
    void change(int index,int number);
    int find(int number);
};
