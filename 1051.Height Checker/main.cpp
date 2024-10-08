#include <iostream>

//1051. Height Checker
//A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).Return the number of indices where heights[i] != expected[i].

int heightChecker(std::vector<int>& heights){
    std::vector<int> orig = heights;
    std::sort(heights.begin(),heights.end());
    const size_t size = orig.size();
    int unmatch = 0;
    for(int i = 0;i<size;i++){
        if(orig[i]!=heights[i])
            unmatch++;
    }
    return unmatch;
}

int main(int argc, const char * argv[]) {
    std::vector<int> arr = {5,1,2,3,4};
    std::cout<<heightChecker(arr)<<std::endl;
}
