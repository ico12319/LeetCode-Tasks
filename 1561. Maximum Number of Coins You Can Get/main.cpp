#include <iostream>

//1561. Maximum Number of Coins You Can Get
//There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:In each step, you will choose any 3 piles of coins (not necessarily consecutive).Of your choice, Alice will pick the pile with the maximum number of coins.You will pick the next pile with the maximum number of coins.Your friend Bob will pick the last pile.Repeat until there are no more piles of coins.Given an array of integers piles where piles[i] is the number of coins in the ith pile.Return the maximum number of coins that you can have.

int maxCoins(std::vector<int>& piles){
    std::sort(piles.begin(),piles.end());
    const size_t size = piles.size();
    int steps = 0;
    int res = 0;
    for(int i = size-2;i>0;i-=2){
        res+=piles[i];
        steps++;
        if(steps == size / 3)
            break;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::vector<int> piles = {2,4,1,2,7,8};
    std::cout<<maxCoins(piles)<<std::endl;
}
