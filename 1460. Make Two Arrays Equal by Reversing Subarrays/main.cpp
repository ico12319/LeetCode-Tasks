#include <iostream>

bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
    const size_t size1 = target.size();
    const size_t size2 = arr.size();
    if(size1!=size2)
        return false;
    
    std::sort(target.begin(),target.end());
    std::sort(arr.begin(),arr.end());
    return target == arr;
}

int main(int argc, const char * argv[]) {
    std::vector<int> target = {1,2,3,4};
    std::vector<int> arr = {2,4,1};
    std::cout<<canBeEqual(target, arr)<<std::endl;
}
