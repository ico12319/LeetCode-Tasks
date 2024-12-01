#include <iostream>
#include <stack>

//121. Best Time to Buy and Sell Stock
//You are given an array prices where prices[i] is the price of a given stock on the ith day.You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

int best_time_to_buy_and_sell_stocks(std::vector<int>& prices){
    std::stack<int> stack;
    int max_proft = 0;
    for(int i = 0;i<prices.size();i++){
        if(stack.empty()){
            stack.push(prices[i]);
            continue;
        }
        if(stack.top() > prices[i])
            stack.push(prices[i]);
        else{
            int profit = prices[i] - stack.top();
            max_proft = std::max(profit, max_proft);
        }
    }
    return max_proft;
}

int main(int argc, const char * argv[]) {
    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout<<best_time_to_buy_and_sell_stocks(prices)<<std::endl;
}
