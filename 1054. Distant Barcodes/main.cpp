#include <iostream>
#include <queue>
#include <map>

//1054. Distant Barcodes
//In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

struct pair_comparator{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int, int>& p2) const{
        return p1.second < p2.second;
    }
};


std::priority_queue<std::pair<int, int>,std::vector<std::pair<int,int>>,pair_comparator> parse_data(const std::vector<int>& barcodes){
    std::unordered_map<int,int> map;
    for(const auto& el : barcodes)
        map[el]++;
    std::vector<std::pair<int, int>> cont(map.begin(),map.end());
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int,int>>,pair_comparator> pq(cont.begin(),cont.end());
    return pq;
}

std::vector<int> rearrange_barcodes(std::vector<int>& barcodes){
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int,int>>,pair_comparator> pq = parse_data(barcodes);
    std::vector<int> result;
    std::queue<std::pair<int,int>> idle;
    while(!pq.empty() || !idle.empty()){
        if(!pq.empty()){
            std::pair<int, int> curr_max = pq.top();
            pq.pop();
            result.push_back(curr_max.first);
            if(!idle.empty()){
                pq.push(idle.front());
                idle.pop();
            }
            if(curr_max.second - 1 != 0)
                idle.push({curr_max.first,curr_max.second - 1});
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> v = {1,1,1,1,2,2,3,3};
    std::vector<int> r = rearrange_barcodes(v);
    for(const auto& el : r){
        std::cout<<el<<" ";
    }
}
