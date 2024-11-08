#include <iostream>
#include <stack>

//739. Daily Temperatures.Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

std::vector<int> dailyTemperatures(std::vector<int>& temperatures){
    std::vector<int> res(temperatures.size(),0);
    std::stack<int> stk;
    int days = 0;
    for(int i = 0;i<temperatures.size();i++){
        while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
            int prevIndex = stk.top();
            res[prevIndex] = i - prevIndex;
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}


int main(int argc, const char * argv[]) {
    std::vector<int> temp = {73,74,75,71,69,72,76,73};
    std::vector<int> res = dailyTemperatures(temp);
}
