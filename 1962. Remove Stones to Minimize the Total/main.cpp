#include <iostream>
#include <queue>

//1962. Remove Stones to Minimize the Total
//You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k. You should apply the following operation exactly k times:Choose any piles[i] and remove floor(piles[i] / 2) stones from it.Notice that you can apply the operation on the same pile more than once.Return the minimum possible total number of stones remaining after applying the k operations.

int min_stone_sum(std::vector<int>& piles,int k){
    std::priority_queue<int> pq(piles.begin(),piles.end());
    
    for(int i = 0;i<k;i++){
        int curr_max = pq.top();
        pq.pop();
        double res = curr_max / 2.0;
        pq.push(std::ceil(res));
    }
    
    int sum = 0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
