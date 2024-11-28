#include <iostream>
#include <queue>

//2233. Maximum Product After K Increments
//You are given an array of non-negative integers nums and an integer k. In one operation, you may choose any element from nums and increment it by 1.Return the maximum product of nums after at most k operations. Since the answer may be very large, return it modulo 109 + 7. Note that you should maximize the product before taking the modulo

const int MOD = 1e9 + 7;
int max_product(const std::vector<int>& nums,int k){
    std::priority_queue<int,std::vector<int>,std::greater<>> pq(nums.begin(),nums.end());
    for(int i = 0;i<k;i++){
        int curr_min = pq.top();
        pq.pop();
        curr_min++;
        pq.push(curr_min);
    }
    int max_product = 1;
    while(!pq.empty()){
        max_product%=MOD;
        max_product*=pq.top();
        pq.pop();
    }
    return max_product % MOD;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {24,5,64,53,26,38};
    std::cout<<max_product(nums, 54)<<std::endl;
}
