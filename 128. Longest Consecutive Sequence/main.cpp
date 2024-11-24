#include <iostream>
#include <set>
#include <unordered_set>

//128. Longest Consecutive Sequence
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.You must write an algorithm that runs in O(n) time.

int logest_consecutive(std::vector<int>& nums){
    if(nums.size() == 0) return 0;
    
    std::unordered_set<int> set;
    for(const auto& num : nums)
        set.insert(num);
    
    int max_count = INT_MIN;
    for(auto it = set.begin();it!=set.end();it++){
        if(set.find(*it - 1) == set.end()){ // check if the number is a start of a sequence
            int curr_num = *it;
            int streak = 1;
            while(set.find(curr_num + 1) != set.end()){
                curr_num+=1;
                streak+=1;
            }
            max_count = std::max(streak, max_count);
        }
    }
    return max_count;
}


int main(int argc, const char * argv[]) {
    std::vector<int> v = {0,3,7,2,5,8,4,6,0,1};
    std::cout<<logest_consecutive(v)<<std::endl;
}
