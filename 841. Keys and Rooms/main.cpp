#include <iostream>

//841. Keys and Rooms
//There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

void dfs(std::vector<std::vector<int>>& rooms,std::vector<bool>& visited,int src){
    visited[src] = true;
    for(const auto& neighbour : rooms[src]){
        if(!visited[neighbour])
            dfs(rooms, visited, neighbour);
    }
}


bool can_visit_all_rooms(std::vector<std::vector<int>>& rooms){
    std::vector<bool> visited(rooms.size(),false);
    int joint_sets = 0;
    for(int i = 0;i<rooms.size();i++){
        if(!visited[i]){
            dfs(rooms, visited, i);
            joint_sets++;
        }
    }
    return joint_sets == 1;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    std::cout<<can_visit_all_rooms(rooms)<<std::endl;
}
