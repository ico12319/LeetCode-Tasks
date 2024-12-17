#include <iostream>
#include <queue>
#include <unordered_set>

//997. Find the Town Judge
//In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.If the town judge exists, then:The town judge trusts nobody.Everybody (except for the town judge) trusts the town judge.There is exactly one person that satisfies properties 1 and 2.

int find_judge(int n,std::vector<std::vector<int>>& trust){
    std::unordered_map<int, std::unordered_set<int>> graph;
    for(const auto& el : trust){
        graph[el[0]].insert(el[1]);
        graph[el[1]].insert(-1);
    }
    
    for(const auto& pair : graph){
        if(pair.second.size() == 1){
            int key = pair.first;
            int count = 0;
            for(const auto& el : graph){
                if(key != el.first){
                    if(el.second.contains(key))
                        count++;
                }
            }
            if(count == n - 1)
                return key;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{1,3},{2,3},{3,1}};
    int n = 3;
    std::cout<<find_judge(n, edges)<<std::endl;
}
