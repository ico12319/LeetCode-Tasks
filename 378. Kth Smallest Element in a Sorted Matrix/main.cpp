#include <iostream>
#include <queue>

//378. Kth Smallest Element in a Sorted Matrix
//Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.Note that it is the kth smallest element in the sorted order, not the kth distinct element.You must find a solution with a memory complexity better than O(n2).

int find_kth_smallest_in_sorted_matrix(const std::vector<std::vector<int>>& matrix,int k){
    std::priority_queue<int> pq;
    for(int i = 0;i<matrix.size();i++){
        for(int j = 0;j<matrix.size();j++){
            if(pq.size() < k)
                pq.push(matrix[i][j]);
            else{
                if(matrix[i][j] < pq.top()){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
    }
    return pq.top();
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    std::cout<<find_kth_smallest_in_sorted_matrix(matrix, k)<<std::endl;
}
