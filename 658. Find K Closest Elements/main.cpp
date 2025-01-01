#include <iostream>
#include <queue>

//658. Find K Closest Elements
//Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

struct comparator{
    bool operator()(const std::pair<int, int>& p1,const std::pair<int, int>& p2) const{
        if(std::abs(p1.second) == std::abs(p2.second))
            return p1.first > p2.first;
        return std::abs(p1.second) > std::abs(p2.second);
    }
};

std::vector<int> find_closest_elements(std::vector<int>& arr,int k,int x){
    std::vector<std::pair<int, int>> diffs;
    for(const auto& number : arr)
        diffs.push_back(std::make_pair(number, number - x));
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,comparator> pq(diffs.begin(),diffs.end());
    std::vector<int> result;
    for(int i = 0;i<k;i++){
        result.push_back(pq.top().first);
        pq.pop();
    }
    std::sort(result.begin(),result.end());
    return result;
    
}

int main(int argc, const char * argv[]) {
    std::vector<int> arr = {1,1,1,10,10,10};
    int k = 1;
    int x = 9;
    auto res = find_closest_elements(arr, k,x);
    for(const auto& el : res)
        std::cout<<el<<" ";
}
