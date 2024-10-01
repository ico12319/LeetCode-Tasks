#include <iostream>
#include <map>

//41. First Missing Positive
//Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums. You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

std::map<int,int> fillMap(std::vector<int>& nums){
    std::map<int,int> m;
    for(const auto& num : nums)
        m[num]++;
    return m;
}

int firstMissingPositive(std::vector<int>& nums){
    std::map<int,int> m = fillMap(nums);
    int smallestPostive = 1;
    while(true){
        if(m.find(smallestPostive) != m.end())
            smallestPostive++;
        else
            break;
    }
    return smallestPostive;
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums = {3,4,-1,1};
    std::cout<<firstMissingPositive(nums)<<std::endl;

}
