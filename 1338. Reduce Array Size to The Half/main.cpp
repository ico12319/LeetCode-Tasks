#include <iostream>
#include <queue>

//1338. Reduce Array Size to The Half
//You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.Return the minimum size of the set so that at least half of the integers of the array are removed.

struct compare{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int,int>& p2) const{
        return p1.second < p2.second;
    }
};

size_t min_set_size(std::vector<int>& arr){
    std::unordered_map<int, int> freq;
    for(const auto& num : arr)
        freq[num]++;
    std::vector<std::pair<int,int>> temp(freq.begin(),freq.end());
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,compare> pq(temp.begin(),temp.end());
    
    size_t orig_size = arr.size();
    size_t curr_removed = 0;
    size_t count = 0;
    while(!pq.empty()){
        int top_freq = pq.top().second;
        count++;
        if(top_freq + curr_removed >= orig_size/2)
            break;
        curr_removed+=top_freq;
        pq.pop();
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::vector<int> arr = {7,7,7,7,7,7,7};
    std::cout<<min_set_size(arr)<<std::endl;
}
