#include <iostream>

//56. Merge Intervals
//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

std::vector<int> merge(std::vector<int>& nums1,std::vector<int>& nums2){
    int first = 0;
    int second = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();
    std::vector<int> res;
    while(first < size1 && second < size2){
        if(nums1[first] <= nums2[second])
            res.push_back(nums1[first++]);
        else if(nums1[first] > nums2[second])
            res.push_back(nums2[second++]);
    }
    while(first < size1)
        res.push_back(nums1[first++]);
    while(second < size2)
        res.push_back(nums2[second++]);
    return res;
}

std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals){
    std::vector<std::vector<int>> result;
    std::sort(intervals.begin(),intervals.end());
    result.push_back(intervals[0]);
    for(int i = 1;i<intervals.size();i++){
        if(std::max(result[result.size() - 1][0],intervals[i][0]) <= std::min(result[result.size() - 1][1],intervals[i][1])){
            std::vector<int> merged = merge(result[result.size() - 1], intervals[i]);
            result[result.size() - 1][0] = merged[0];
            result[result.size() - 1][1] = merged[merged.size() - 1];
        }
        else
            result.push_back(intervals[i]);
    }
    return result;
    
}

void printIntervals(const std::vector<std::vector<int>>& v){
    for(const auto& el : v){
        std::cout<<"[";
        std::cout<<el[0]<<", "<<el[1];
        std::cout<<"]"<<std::endl;
    }
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> inter = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    std::vector<std::vector<int>> merged = mergeIntervals(inter);
    printIntervals(merged);
}
