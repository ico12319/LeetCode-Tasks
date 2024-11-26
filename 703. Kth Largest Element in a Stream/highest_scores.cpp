#include "highest_scores.h"

highest_scores::highest_scores(int k,std::vector<int>& nums){
    for(const auto& el : nums){
        if(min_heap.size() < k)
            min_heap.push(el);
        else if(el > min_heap.top()){
            min_heap.pop();
            min_heap.push(el);
        }
    }
    this->k = k;
}


int highest_scores::add(int el){
    if(min_heap.size() < k)
        min_heap.push(el);
    else if(el > min_heap.top()){
        min_heap.pop();
        min_heap.push(el);
    }
    
    return min_heap.top();
}
