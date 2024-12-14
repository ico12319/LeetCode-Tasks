#include <iostream>
#include <unordered_set>

//2554. Maximum Number of Integers to Choose From a Range I
//You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:The chosen integers have to be in the range [1, n].Each integer can be chosen at most once.The chosen integers should not be in the array banned.The sum of the chosen integers should not exceed maxSum.Return the maximum number of integers you can choose following the mentioned rules.

int max_count(std::vector<int>& banned,int n,int max_sum){
    std::unordered_set<int> seen(banned.begin(),banned.end());
    int counter = 0;
    int sum = 0;
    for(int i = 1;i<=n;i++){
        if(!seen.contains(i) && sum + i <= max_sum){
            counter++;
            sum+=i;
        }
    }
    return counter;
}

int main(int argc, const char * argv[]) {
    std::vector<int> banned = {11};
    int n = 7;
    int max_sum = 50;
    std::cout<<max_count(banned, n, max_sum)<<std::endl;
}
