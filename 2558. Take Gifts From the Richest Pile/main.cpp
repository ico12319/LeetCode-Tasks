#include <iostream>
#include <queue>

//2558. Take Gifts From the Richest Pile
//You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:Choose the pile with the maximum number of gifts.If there is more than one pile with the maximum number of gifts, choose any.Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.Return the number of gifts remaining after k seconds.

int number_of_gifts_remaining_after_k_seconds(std::vector<int>& gifts,int k){
    std::priority_queue<int> pq;
    for(auto it = gifts.begin();it!=gifts.end();it++)
        pq.push(*it);
    
    for(int i = 0;i<k;i++){
        int curr_biggest = pq.top();
        int new_val = sqrt(curr_biggest);
        pq.pop();
        pq.push(new_val);
    }
    
    int sum = 0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}



int main(int argc, const char * argv[]) {
    std::vector<int> gifts = {1,1,1,1};
    int k = 4;
    std::cout<<number_of_gifts_remaining_after_k_seconds(gifts, k)<<std::endl;
}
