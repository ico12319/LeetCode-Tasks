#include <iostream>
#include <map>

//1656. Design an Ordered Stream
//There is a stream of n (idKey, value) pairs arriving in an arbitrary order, where idKey is an integer between 1 and n and value is a string. No two pairs have the same id.Design a stream that returns the values in increasing order of their IDs by returning a chunk (list) of values after each insertion. The concatenation of all the chunks should result in a list of the sorted values.

class ordered_stream{
private:
    std::vector<int> parent_array;
    std::vector<int> sizes;
    std::map<int,std::string> included;
    
public:
    ordered_stream(int n){
        parent_array.resize(n + 1);
        sizes.resize(n + 1,1);
        for(int i = 0;i<=n;i++)
            parent_array[i] = i;
    }
    
    int find(int stream){
       if(stream == parent_array[stream])
           return stream;
        return parent_array[stream] = find(parent_array[stream]);
    }
    
    void union_by_size(int stream1,int stream2){
        auto ultimate_parent1 = find(stream1);
        auto ultimate_parent2 = find(stream2);
        
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
    
    std::vector<std::string> insert(int id_key,const std::string& value){
        included.insert({id_key,value});
        if(included.contains(id_key - 1))
            union_by_size(id_key, id_key - 1);
        if(included.contains(id_key + 1))
            union_by_size(id_key, id_key + 1);
        
        if(id_key != 1 && !included.contains(id_key + 1))
            return {};
        auto size = sizes[find(1)];
        std::vector<std::string> res;
        for(int i = id_key;i<=size;i++)
            res.push_back(included[i]);
        return res;
    }
};

void print(const std::vector<std::string>& v){
    for(const auto& word : v)
        std::cout<<word<<" ";
    std::cout<<std::endl;
}

int main(int argc, const char * argv[]) {
    ordered_stream stream(5);
    auto res1 = stream.insert(3, "ccc");
    print(res1);
    auto res2 = stream.insert(1, "aaaaa");
    print(res2);
    auto res3 = stream.insert(2, "bbbb");
    print(res3);
    auto res5 = stream.insert(5, "eeeee");
    print(res5);
    auto res4 = stream.insert(4, "dddd");
    print(res4);
}
