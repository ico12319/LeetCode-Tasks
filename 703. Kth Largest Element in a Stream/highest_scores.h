#pragma once
#include <iostream>
#include <queue>

class highest_scores{
private:
    std::priority_queue<int,std::vector<int>,std::greater<int>>min_heap;
    int k;
    
public:
    highest_scores(int k,std::vector<int>& nums);
    int add(int el);
};
