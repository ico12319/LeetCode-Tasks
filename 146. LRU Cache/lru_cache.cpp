#include <stdio.h>
#include "lru_cache.h"

lru_cache::lru_cache(size_t capacity) : capacity(capacity){}

int lru_cache::get(int key){
    auto it = map.find(key);
    if(it == map.end())
        return -1;
    
    int to_retutn = it->second.first;
    cache.splice(cache.begin(), cache,it->second.second);
    map[it->first].second = cache.begin();
    return to_retutn;
}

void lru_cache::put(int key, int value){
    auto it = map.find(key);
    if(it == map.end()){
        if(cache.size() >= capacity){
            map.erase(*(--cache.end()));
            cache.pop_back();
        }
        cache.push_front(key);
        map[key] = {value,cache.begin()};
        return;
    }
    map[key].first = value;
    cache.splice(cache.begin(), cache,it->second.second);
    map[key].second = cache.begin();
}




