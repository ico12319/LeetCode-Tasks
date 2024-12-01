#include <iostream>
#include <unordered_set>

//2053. Kth Distinct String in an Array
//A distinct string is a string that is present only once in an array.Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".Note that the strings are considered in the order in which they appear in the array.

std::string kthDistinct(std::vector<std::string>& arr, int k) {
    std::unordered_map<std::string,int> map;
    for(const auto& str : arr)
        map[str]++;
    
    for(const auto& str : arr){
        if(map[str] == 1){
            k--;
            if(k == 0)
                return str;
        }
    }
    return "";
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> arr = {"aaa","b","aaa"};
    std::cout<<kthDistinct(arr, 3)<<std::endl;
}
