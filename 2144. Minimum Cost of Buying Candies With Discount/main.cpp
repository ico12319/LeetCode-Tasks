#include <iostream>

//2144. Minimum Cost of Buying Candies With Discount
//A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

bool cmp(int a,int b){
    return a > b;
}

int minimumCost(std::vector<int>& cost){
    std::sort(cost.begin(),cost.end(),cmp);
    int minCost = 0;
    int iters = 0;
    for(int i = 0;i<cost.size();i++){
        if(iters == 2 && cost[i] < minCost){
            iters = 0;
            continue;
        }
        minCost+=cost[i];
        iters++;
    }
    return minCost;
}

int main(int argc, const char * argv[]) {
    std::vector<int> arr = {1,2,3};
    std::cout<<minimumCost(arr)<<std::endl;
}
