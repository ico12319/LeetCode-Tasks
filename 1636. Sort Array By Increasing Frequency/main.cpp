#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

// 1636. Sort Array by Increasing Frequency
// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
//Return the sorted array.

std::unordered_map<int, int> constructMap(std::vector<int>& nums){
    std::unordered_map<int, int> occur;
    for(const auto& num : nums){
        occur[num]++;
    }
    return occur;
}

std::vector<int> constructResultVector(std::vector<std::pair<int,int>>& freqVec){
    std::vector<int> res;
    for(const auto& pair : freqVec){
        int value  = pair.first;
        int freq = pair.second;
        for(int i = 0;i<freq;i++){
            res.push_back(value);
        }
    }
    return res;
}

std::vector<int> frequencySort(std::vector<int>& nums){
    std::unordered_map<int, int> no = constructMap(nums);
    std::vector<std::pair<int,int>> freqVec;
    for(const auto& pair : no){
        freqVec.emplace_back(pair.first,pair.second);
    }
    
    std::sort(freqVec.begin(),freqVec.end(),[](const std::pair<int,int>& a,const std::pair<int,int>& b){
        if(a.second!=b.second){
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    
    std::vector<int> res = constructResultVector(freqVec);
    return res;
}

void printVector(const std::vector<int>& nums){
    const size_t size = nums.size();
    for(int i = 0;i<size;i++)
        std::cout<<nums[i]<<" ";
}

int main() {
    std::vector<int> v = {-1,1,-6,4,5,-6,1,4,1};
    std::vector<int> result = frequencySort(v);
    printVector(result);
}

