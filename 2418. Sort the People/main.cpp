#include <iostream>
#include <vector>

// 2418. Sort the People
// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
// For each index i, names[i] and heights[i] denote the name and height of the ith person.
// Return names sorted in descending order by the people's heights.


std::vector<std::pair<int,std::string>> constructMap(const std::vector<std::string>& names,const std::vector<int>& heights){
    std::vector<std::pair<int,std::string>> nh;
    const size_t size = names.size();
    for(int i = 0;i<size;i++){
        nh.emplace_back(heights[i],names[i]);
    }
    return nh;
}


std::vector<std::string> sortPeople(std::vector<std::string>& names,std::vector<int>& heights){
    std::vector<std::pair<int,std::string>> nh = constructMap(names, heights);
    std::sort(nh.begin(), nh.end(), std::greater<>());
    const size_t size = names.size();
    for(int i = 0;i<size;i++){
        names[i] = nh[i].second;
    }
    return names;
    
}

int main(int argc, const char * argv[]) {
    
    std::vector<std::string> names;
    names.push_back("Mary");
    names.push_back("John");
    names.push_back("Emma");
    
    std::vector<int> heights;
    heights.push_back(180);
    heights.push_back(165);
    heights.push_back(170);
    
    std::vector<std::string> sorted = sortPeople(names, heights);
    for(const auto& name : sorted)
        std::cout<<name<<" ";
    
   
}
