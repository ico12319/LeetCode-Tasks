#include <iostream>

//684. Redundant Connection
//In this problem, a tree is an undirected graph that is connected and has no cycles.You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

class union_find{
private:
    std::vector<int> parent_array;
    std::vector<int> size;
    
public:
    union_find(int n){
        parent_array.resize(n);
        size.resize(n,1);
        
        for(int i = 0;i<n;i++)
            parent_array[i] = i;
    }
    
    bool union_by_size(int node1,int node2){
        int ultimate_parent1 = find(node1);
        int ultimate_parent2 = find(node2);
        
        if(ultimate_parent1 == ultimate_parent2)
            return false;
        if(size[ultimate_parent1] < size[ultimate_parent2]){
            parent_array[ultimate_parent1] = ultimate_parent2;
            size[ultimate_parent2] += size[ultimate_parent1];
        }
        else{
            parent_array[ultimate_parent2] = ultimate_parent1;
            size[ultimate_parent1] += size[ultimate_parent2];
        }
        return true;
    }
    
    int find(int node){
        if(node == parent_array[node])
            return node;
        return parent_array[node] = find(parent_array[node]);
    }
};



std::vector<int> find_redundant_connection(const std::vector<std::vector<int>>& edges){
    std::vector<std::vector<int>> redundant_edges;
    union_find uf(edges.size());
    for(int i = 0;i<edges.size();i++){
        int from = edges[i][0] - 1;
        int to = edges[i][1] - 1;
        if(!uf.union_by_size(from, to))
            redundant_edges.push_back({from,to});
    }
    return {redundant_edges.back()[0] + 1,redundant_edges.back()[1] + 1};
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    auto res = find_redundant_connection(edges);
    for(const auto& el : res)
        std::cout<<el<<" ";
    std::cout<<std::endl;
}
