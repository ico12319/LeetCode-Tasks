#include <iostream>
#include <unordered_map>

//599. Minimum Index Sum of Two Lists
//Given two arrays of strings list1 and list2, find the common strings with the least index sum.A common string is a string that appeared in both list1 and list2.A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.Return all the common strings with the least index sum. Return the answer in any order..

std::unordered_map<std::string,int> fillMap(const std::vector<std::string>& words){
    std::unordered_map<std::string, int> map;
    for(int i = 0;i<words.size();i++){
        map[words[i]] = i;
    }
    return map;
}

std::vector<std::string> findRestaurant(std::vector<std::string>& list1,std::vector<std::string>& list2){
    std::unordered_map<std::string, int> map = fillMap(list1);
    std::vector<std::string> res;
    int min = INT16_MAX;
    for(int i = 0;i<list2.size();i++){
        if(map.find(list2[i])!=map.end()){
            int indexSum = i + map[list2[i]];
            if(indexSum < min){
                min = indexSum;
                res.clear();
                res.push_back(list2[i]);
            }
            else if(indexSum == min){
                res.push_back(list2[i]);
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> list1 = {"happy","sad","good"};
    std::vector<std::string> list2 = {"sad","happy","good"};
    std::vector<std::string> res = findRestaurant(list1, list2);
    for(int i = 0;i<res.size();i++){
        std::cout<<res[i]<<" ";
    }
    
}
