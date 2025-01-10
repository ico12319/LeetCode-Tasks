#include <iostream>

//1361. Validate Binary Tree Nodes
//You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.If node i has no left child then leftChild[i] will equal -1, similarly for the right child.Note that the nodes have no values and that we only use the node numbers in this problem.

std::vector<std::vector<int>> convert_to_undirected(int n,std::vector<int>& left_child,std::vector<int>& right_child){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(int i = 0;i<left_child.size();i++){
        if(left_child[i] != -1){
            adj[i].push_back(left_child[i]);
            adj[left_child[i]].push_back(i);
        }
        if(right_child[i] != -1){
            adj[i].push_back(right_child[i]);
            adj[right_child[i]].push_back(i);
        }
    }
    return adj;
}

void dfs(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int src){
    visited[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child])
            dfs(adj, visited, child);
    }
}

int count_connected_components(std::vector<std::vector<int>>& adj){
    std::vector<bool> visited(adj.size(),false);
    int sets = 0;
    for(int i = 0;i<adj.size();i++){
        if(!visited[i]){
            dfs(adj,visited, i);
            sets++;
        }
    }
    return sets;
}

std::vector<std::vector<int>> convert(int n,std::vector<int>& left_child,std::vector<int>& right_child){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(int i = 0;i<left_child.size();i++){
        if(left_child[i] != -1)
            adj[i].push_back(left_child[i]);
        if(right_child[i] != -1)
            adj[i].push_back(right_child[i]);
    }
    return adj;
}


bool contains_cycle_helper(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,std::vector<bool>& is_in_stack,int src){
    visited[src] = true;
    is_in_stack[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child] && contains_cycle_helper(adj, visited, is_in_stack, child))
            return true;
        else if(is_in_stack[child])
            return true;
    }
    is_in_stack[src] = false;
    return false;
}

bool contains_more_than_one_in_goind_edges(std::vector<std::vector<int>>& adj){
    std::vector<int> in_going_edges(adj.size(),0);
    for(int i = 0;i<adj.size();i++){
        for(int j = 0;j<adj[i].size();j++){
            in_going_edges[adj[i][j]]++;
        }
    }
    for(const auto& el : in_going_edges)
        std::cout<<el<<" ";
    std::cout<<std::endl;
    auto it = std::max_element(in_going_edges.begin(), in_going_edges.end());
    return *it == 1;
}

bool validate_binary_tree_nodes(int n,std::vector<int>& left_child,std::vector<int>& right_child){
    auto adj = convert(n, left_child, right_child);
    auto undirected_adj = convert_to_undirected(n, left_child, right_child);
    int sets = count_connected_components(undirected_adj);
    std::vector<bool> visited(n,false);
    std::vector<bool> is_in_stack(n,false);
    int connected_sets = count_connected_components(adj);
    for(int i = 0;i<n;i++){
        if(contains_cycle_helper(adj, visited, is_in_stack, i))
            return false;
    }
    return contains_more_than_one_in_goind_edges(adj) && sets == 1;
}

int main(int argc, const char * argv[]) {
    std::vector<int> left_child = {1,-1,-1,4,-1,-1};
    int n = 6;
    std::vector<int> right_child = {2,-1,-1,5,-1,-1};
   
    std::cout<<validate_binary_tree_nodes(n, left_child, right_child)<<std::endl;
}
