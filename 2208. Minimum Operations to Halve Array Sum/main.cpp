#include <iostream>
#include <queue>

//2208. Minimum Operations to Halve Array Sum
//You are given an array nums of positive integers. In one operation, you can choose any number from nums and reduce it to exactly half the number. (Note that you may choose this reduced number in future operations.)Return the minimum number of operations to reduce the sum of nums by at least half.

namespace CONSTANTS{
constexpr double EPSILON = 0.0000000001;
}

double find_sum(const std::vector<int>& nums){
    double sum = 0;
    for(const auto& num : nums)
        sum += num;
    return sum;
}


int halve_array(std::vector<int>& nums){
    auto initial_sum = find_sum(nums);
    auto halved = static_cast<double>(initial_sum) / 2.0;
    int min_operations = 0;
    std::priority_queue<double,std::vector<double>,std::less<double>> pq(nums.begin(),nums.end());
    while(!pq.empty()){
        if(initial_sum - halved <= CONSTANTS::EPSILON)
            return min_operations;
        min_operations++;
        auto curr_max = static_cast<double>(pq.top());
        auto to_add = curr_max / 2.0;
        pq.pop();
        initial_sum -= to_add;
        pq.push(to_add);
    }
    return min_operations;
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums = {3,8,20};
    std::cout<<halve_array(nums)<<std::endl;
}
