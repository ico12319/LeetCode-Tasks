#include <iostream>
#include <algorithm>

//973. K Closest Points to Origin
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points,int k){
    std::vector<std::pair<int,int>> currDistance(points.size());
    const size_t size = points.size();
    for(int i = 0;i<size;i++){
        currDistance[i].first = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
        currDistance[i].second = i;
    }
    
    std::sort(points.begin(),points.end());
    std::vector<std::vector<int>> closest;
    int index = 0;
    for(int i = 0;i<k;i++){
        closest.push_back(points[currDistance[index].second]);
        index++;
    }
    return closest;
}

void print(const std::vector<int>& v){
    for(int i = 0;i<v.size();i++){
        std::cout<<v[i]<<" ";
    }
}




int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> points = {{3,8},{-2,2}};
    int k = 1;
    std::vector<std::vector<int>> closest = kClosest(points, k);
    for(const auto& v : closest){
        print(v);
    }
    
}
