#include <iostream>
#include <queue>

//373. Find K Pairs with Smallest Sums
//You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.Define a pair (u, v) which consists of one element from the first array and one element from the second array.Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

void print(const std::vector<int>& v){
    for(const auto& el : v)
        std::cout<<el<<" ";
    std::cout<<std::endl;
}

struct tuple_comparator{
    bool operator()(const std::tuple<int,int,int>& t1,const std::tuple<int,int,int>& t2) const{
        return std::get<0>(t1) > std::get<0>(t2);
    }
};

std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::vector<std::vector<int>> res;
    std::priority_queue<std::tuple<int,int,int>,std::vector<std::tuple<int,int,int>>,tuple_comparator>pq;
    for(int i = 0;i<nums2.size();i++)
        pq.push({nums1[0] + nums2[i] ,0,i});
    
    while(k != 0 && !pq.empty()){
        k--;
        auto top = pq.top();
        pq.pop();
            
        int i = std::get<1>(top);
        int j = std::get<2>(top);
        res.push_back({nums1[i],nums2[j]});
            
        if(i + 1 < nums1.size() && j < nums2.size())
            pq.push({nums1[i + 1] + nums2[j],i+1,j});
    }
    return res;
}
int main(int argc, const char * argv[]) {
    std::vector<int> nums1 = {1,7,11};
    std::vector<int> nums2 = {2,4,6};
    std::vector<std::vector<int>> result = kSmallestPairs(nums1, nums2, 3);
    for(int i = 0;i<result.size();i++)
        print(result[i]);
}
