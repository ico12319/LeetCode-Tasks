#include <iostream>
#include <queue>

//215. Kth Largest Element in an Array
//Given an integer array nums and an integer k, return the kth largest element in the array.Note that it is the kth largest element in the sorted order, not the kth distinct element.Can you solve it without sorting?

int find_k_th_largest(const std::vector<int>& v,int k){
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
    for(const auto& el : v){
        if(pq.size() < k)
            pq.push(el);
        else{
            if(el > pq.top()){
                pq.pop();
                pq.push(el);
            }
        }
    }
    return pq.top();
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    std::cout<<find_k_th_largest(nums, k)<<std::endl;
}
