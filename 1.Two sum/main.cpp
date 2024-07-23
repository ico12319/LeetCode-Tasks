#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

std::vector<int> twoSum(std::vector<int>& nums,int target){
    const size_t size = nums.size();
    std::unordered_map<int, int> map;
    
    for(int i = 0;i<size;i++){
        if(map.find(target - nums[i])!=map.end()){
            return std::vector<int>{map[target - nums[i]],i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int main() {
    std::vector<int> v = {1,5,7,2};
    int target = 9;
    std::vector<int> ni = twoSum(v, target);
    std::cout<<ni[0] <<" : "<<ni[1]<<std::endl;
}

