#include <iostream>
#include <forward_list>
#include <list>

//705. Design HashSet
//Design a HashSet without using any built-in hash table libraries.

class hash_set{
private:
    std::list<int> data;
    using iterator_type = std::list<int>::iterator;
    std::vector<std::forward_list<iterator_type>> hash;
    std::hash<int> hash_function;
    double load_factor = 0.75;

    
    void resize(){
        auto size = hash.size() * 2;
        std::vector<std::forward_list<iterator_type>> new_hash(size);
        for(auto it = data.begin();it!=data.end();it++){
            auto new_hash_code = hash_function(*it) % size;
            new_hash[new_hash_code].push_front(it);
        }
        hash = std::move(new_hash);
    }
    double current_load_factor() const{
        return (double)data.size() / hash.size();
    }
public:
    hash_set(){
        hash.resize(1);
    }
    
    void add(int key){
        if(current_load_factor() > load_factor)
            resize();
        auto hash_code = hash_function(key) % hash.size();
        auto& current_bucket = hash[hash_code];
        auto lambda = [&key](iterator_type iter){return *iter == key;};
        auto it = std::find_if(current_bucket.begin(),current_bucket.end(),lambda);
        if(it == current_bucket.end()){
            data.push_back(key);
            current_bucket.push_front(--data.end());
        }
        else
            return;
    }
    
    bool contains(int key) const{
        auto hash_code = hash_function(key) % hash.size();
        auto& current_bucket = hash[hash_code];
        auto lambda = [&key](iterator_type iter){return *iter == key;};
        auto it = std::find_if(current_bucket.begin(),current_bucket.end(),lambda);
        if(it == current_bucket.end())
            return false;
        return true;
    }
    
    void remove(int key){
        auto hash_code = hash_function(key) % hash.size();
        auto& current_bucket = hash[hash_code];
        current_bucket.remove_if([&key,this](iterator_type iter)
                                 {
            if(*iter == key){
                data.erase(iter);
                return true;
            }
            return false;
        });
        
    }
    void print(){
        for(const auto& el : data)
            std::cout<<el<<" ";
        std::cout<<std::endl;
    }
};

int main(int argc, const char * argv[]) {
    hash_set set;
    
    set.add(1);
    set.add(2);
    std::cout<<set.contains(1)<<std::endl;
    std::cout<<set.contains(3)<<std::endl;
    set.add(2);
    std::cout<<set.contains(2)<<std::endl;
    set.remove(2);
    std::cout<<set.contains(2)<<std::endl;
}
