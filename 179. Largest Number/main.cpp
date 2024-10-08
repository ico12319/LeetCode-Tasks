#include <iostream>
#include <string>

//179. Largest Number
// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.Since the result may be very large, so you need to return a string instead of an integer.

bool cmp(const std::string& str1,const std::string& str2){
    return (str1 + str2) > (str2 + str1);
}

std::string largestNumber(std::vector<int>& nums){
    std::vector<std::string> arr;
    
    for(const auto& num: nums){
        arr.push_back(std::to_string(num));
    }
    
    std::sort(arr.begin(),arr.end(),cmp);
    
    if(arr[0] == "0")
        return "0";
    
    std::string res;
    for(const auto& el:arr)
        res+=el;
    
    return res;
}

void print(const std::vector<int>& v){
    const size_t size = v.size();
    for(int i = 0;i<size;i++){
        std::cout<<v[i]<<" ";
    }
}
int main(int argc, const char * argv[]) {
    std::vector<int> arr = {0,1,0,3,12};
    std::cout<<largestNumber(arr);
}
