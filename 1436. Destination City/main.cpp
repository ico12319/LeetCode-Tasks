#include <iostream>

//1436. Destination City
//You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

std::string dest_city(std::vector<std::vector<std::string>>& paths){
    std::unordered_map<std::string, std::vector<std::string>> out_edges;
    std::unordered_map<std::string, std::vector<std::string>> in_edges;
    for(const auto& path : paths){
        out_edges[path[0]].push_back(path[1]);
        in_edges[path[1]].push_back(path[0]);
    }
    
    for(const auto& pair : in_edges){
        if(!out_edges.contains(pair.first))
            return pair.first;
    }
    return " ";
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<std::string>> paths = {{"B","C"},{"D","B"},{"C","A"}};
    std::cout<<dest_city(paths)<<std::endl;
}
