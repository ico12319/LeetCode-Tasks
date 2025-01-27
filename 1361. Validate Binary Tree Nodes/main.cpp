#include <iostream>
#include <queue>


//1361. Validate Binary Tree Nodes
//You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.If node i has no left child then leftChild[i] will equal -1, similarly for the right child.Note that the nodes have no values and that we only use the node numbers in this problem.

std::vector<int> in_edges(const std::vector<int>& left_child,const std::vector<int>& right_child,int n){
    std::vector<int> edges(n,0);
    for(int i = 0;i<left_child.size();i++){
        if(left_child[i] != -1)
            edges[left_child[i]]++;
    }
    for(int i = 0;i<right_child.size();i++){
        if(right_child[i] != -1)
            edges[right_child[i]]++;
    }
    return edges;
}

bool validate_root(const std::vector<int>& left_child,const std::vector<int>& right_child,int n,int& root){
    auto edges = in_edges(left_child, right_child, n);
    int count = 0;
    for(int i = 0;i<edges.size();i++){
        if(edges[i] == 0){
            root = i;
            count++;
        }
    }
    return count == 1;
}

std::vector<std::vector<int>> convert(const std::vector<int>& left_child,const std::vector<int>& right_child,int n){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(int i = 0;i<left_child.size();i++){
        auto from = i;
        auto left = left_child[i];
        auto right = right_child[i];
        if(left != -1)
            adj[from].push_back(left);
        if(right != -1)
            adj[from].push_back(right);
    }
    return adj;
}

bool bfs(const std::vector<int>& left_child,const std::vector<int>& right_child,int n){
    int root;
    if(!validate_root(left_child, right_child, n, root))
        return false;
    auto adj = convert(left_child, right_child, n);
    std::queue<int> q;
    std::vector<bool> visited(n,false);
    q.push(root);
    visited[root] = true;
    while(!q.empty()){
        auto curr_node = q.front();
        q.pop();
        for(const auto& child : adj[curr_node]){
            if(visited[child])
                return false;
            q.push(child);
            visited[child] = true;
        }
    }
    auto it = std::find(visited.begin(), visited.end(), false);
    return it == visited.end();
}




int main(int argc, const char * argv[]) {
    int n = 4;
    std::vector<int> left_child = {3,-1,1,-1};
    std::vector<int> right_child = {-1,-1,0,-1};
    std::cout<<bfs(left_child, right_child, n)<<std::endl;
}
