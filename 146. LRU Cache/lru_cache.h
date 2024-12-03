#pragma once
#include <iostream>
#include <list>

class lru_cache{
private:
    size_t capacity;
    std::list<int> cache;
    std::unordered_map<int,std::pair<int,std::list<int>::iterator>> map;
    
public:
    lru_cache(size_t capacity);
    int get(int key);
    void put(int key,int value);
};
