#include <iostream>

//1833. Maximum Ice Cream Bars
//At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible.
//Note: The boy can buy the ice cream bars in any order.Return the maximum number of ice cream bars the boy can buy with coins coins.


constexpr size_t MIN_VALUE = 1;
constexpr size_t MAX_VALUE = 100000;
std::vector<int> countingSort(std::vector<int>& costs){
    std::vector<int> count(MAX_VALUE - MIN_VALUE + 1,0);
    for(int i = 0;i<costs.size();i++)
        count[costs[i] - MIN_VALUE]++;
    
    for(int i = 1;i<MAX_VALUE - MIN_VALUE + 1;i++)
        count[i] += count[i - 1];
    
    std::vector<int> res(costs.size(),0);
    for(int i = 0;i<costs.size();i++){
        size_t correctIndex = --count[costs[i] - MIN_VALUE];
        res[correctIndex] = costs[i];
    }
    return res;
}

int maxIceCream(std::vector<int>& costs,int coins){
    costs = countingSort(costs);
    int currSpend = 0;
    int count = 0;
    for(int i = 0;i<costs.size();i++){
        if(currSpend + costs[i] > coins)
            break;
        currSpend+=costs[i];
        count++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::vector<int> costs = {1,6,3,1,2,5};
    std::cout<<maxIceCream(costs, 20);
}
