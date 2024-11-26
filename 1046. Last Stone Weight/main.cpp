#include <iostream>
#include <queue>

//1046. Last Stone Weight
//You are given an array of integers stones where stones[i] is the weight of the ith stone.We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y.You are given an array of integers stones where stones[i] is the weight of the ith stone.We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y

int lastStoneWeight(std::vector<int>& stones) {
    if(stones.size() == 1) return stones[0];
    std::priority_queue<int> pq;
    for(const auto& el : stones)
        pq.push(el);
    
    while(true){
        int curr_biggest = pq.top();
        pq.pop();
        int next_biggest = pq.top();
        
        int diff = curr_biggest - next_biggest;
        if(diff != 0){
            pq.pop();
            pq.push(diff);
        }
        else
            pq.pop();
        
        if(pq.size() == 1 || pq.size() == 0)
            break;
    }
    
    return !pq.empty() ? pq.top() : 0;
}


int main(int argc, const char * argv[]) {
    std::vector<int> v = {2,7,4,1,8,1};
    std::cout<<lastStoneWeight(v)<<std::endl;
}
