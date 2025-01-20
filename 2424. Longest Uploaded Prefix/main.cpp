#include <iostream>
#include <unordered_set>
#include <queue>

//2424. Longest Uploaded Prefix
//You are given a stream of n videos, each represented by a distinct number from 1 to n that you need to "upload" to a server. You need to implement a data structure that calculates the length of the longest uploaded prefix at various points in the upload process.We consider i to be an uploaded prefix if all videos in the range 1 to i (inclusive) have been uploaded to the server. The longest uploaded prefix is the maximum value of i that satisfies this definition.

class lu_prefix{
private:
    std::vector<int> parent_array;
    std::vector<int> sizes;
    std::unordered_set<int> included;
    
public:
    lu_prefix(int n){
        parent_array.resize(n + 1);
        sizes.resize(n + 1,1);
        for(int i = 0;i<=n;i++)
            parent_array[i] = i;
    }
    
    int find(int video){
        if(video == parent_array[video])
            return video;
        return parent_array[video] = find(parent_array[video]);
    }
    
    void union_by_size(int video1,int video2){
        auto ultimate_parent1 = find(video1);
        auto ultimate_parent2 = find(video2);
        if(ultimate_parent1 == ultimate_parent2)
            return;
        if(sizes[ultimate_parent1] < sizes[ultimate_parent2]){
            parent_array[ultimate_parent1] = ultimate_parent2;
            sizes[ultimate_parent2] += sizes[ultimate_parent1];
        }
        else{
            parent_array[ultimate_parent2] = ultimate_parent1;
            sizes[ultimate_parent1] += sizes[ultimate_parent2];
        }
    }
    
    void upload(int video){
        included.insert(video);
        if(included.contains(video - 1))
            union_by_size(video, video - 1);
        if(included.contains(video + 1))
            union_by_size(video, video + 1);
    }
    
    int longest(){
        if(!included.contains(1))
            return 0;
        return sizes[find(1)];
    }
};

int main(int argc, const char * argv[]) {
    lu_prefix lu(4);
    lu.upload(3);
    std::cout<<lu.longest()<<std::endl;
    lu.upload(1);
    std::cout<<lu.longest()<<std::endl;
    lu.upload(2);
    std::cout<<lu.longest()<<std::endl;
}
