#include <iostream>

//1561. Maximum Number of Coins You Can Get
//There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:In each step, you will choose any 3 piles of coins (not necessarily consecutive).Of your choice, Alice will pick the pile with the maximum number of coins.You will pick the next pile with the maximum number of coins.Your friend Bob will pick the last pile.Repeat until there are no more piles of coins.
//Return the maximum number of coins that you can have.

int maxCoins(std::vector<int>& piles){
    std::sort(piles.begin(),piles.end());
    int index = piles.size() - 2;
    int coins = 0;
    int count = 0;
    while(count != piles.size() / 3){
        coins += piles[index];
        index -= 2;
        count++;
    }
    return coins;
}
int main(int argc, const char * argv[]) {
    std::vector<int> piles = {9,8,7,6,5,1,2,3,4};
    std::cout<<maxCoins(piles)<<std::endl;
}
