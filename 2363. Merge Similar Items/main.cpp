#include <iostream>
#include <map>

//2363. Merge Similar Items

std::vector<std::vector<int>> mergeSimilarItems(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2) {
    std::map<int, int> map;
    for(int i = 0;i<items1.size();i++)
        map[items1[i][0]] = items1[i][1];
    
    for(int i = 0;i<items2.size();i++){
        if(map.contains(items2[i][0]))
            map[items2[i][0]]+=items2[i][1];
        else
            map[items2[i][0]] = items2[i][1];
    }
    
    std::vector<std::vector<int>> result;
    for(const auto& pair : map)
        result.push_back({pair.first,pair.second});
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
