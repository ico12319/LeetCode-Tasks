#include <iostream>
#include <queue>


//1985. Find the Kth Largest Integer in the Array
//You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.Return the string that represents the kth largest integer in nums.Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.

struct string_comparator{
    bool operator()(const std::string& str1,const std::string& str2) const{
        if(str1.size() != str2.size())
            return str1.size() > str2.size();
        for(int i = 0;i<str1.size();i++){
            if(str1[i] > str2[i])
                return true;
            else if(str2[i] > str1[i])
                return false;
        }
        return false;
    }
};

std::string k_th_largest_number(const std::vector<std::string>& nums,int k){
    std::priority_queue<std::string,std::vector<std::string>,string_comparator> pq;
    string_comparator cmp;
    for(const auto& num : nums){
        if(pq.size() < k)
            pq.push(num);
        else{
            if(cmp(num,pq.top())){
                pq.pop();
                pq.push(num);
            }
        }
    }
    return pq.top();
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> nums = {"3","6","7","10"};
    int k = 4;
    std::cout<<k_th_largest_number(nums, k)<<std::endl;
}
