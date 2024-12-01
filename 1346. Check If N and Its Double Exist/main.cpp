#include <iostream>

//1346. Check If N and Its Double Exist
//Given an array arr of integers, check if there exist two indices i and j such that :
// 1)i != j
// 2)0 <= i, j < arr.length
// 3)arr[i] == 2 * arr[j]


bool is_even(int num){
    return !(num & 1);
}

bool check_if_exist(std::vector<int>& arr){
    std::unordered_map<int, int> map;
    for(int i = 0;i<arr.size();i++){
        if((map.contains(arr[i] * 2) || (is_even(arr[i]) && map.contains(arr[i] / 2))) && map[arr[i]] != i)
            return true;
        map[arr[i]] = i;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::vector<int> arr = {10,2,5,3};
    std::cout<<check_if_exist(arr)<<std::endl;
}
