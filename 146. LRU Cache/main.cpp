#include "lru_cache.h"

//146. LRU Cache
//Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
//The functions get and put must each run in O(1) average time complexity.

int main(int argc, const char * argv[]) {
   
    lru_cache* cache = new lru_cache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    std::cout<<cache->get(1)<<std::endl;
    cache->put(3, 3);
    std::cout<<cache->get(2)<<std::endl;
    cache->put(4,4);
    std::cout<<cache->get(1)<<std::endl;
    std::cout<<cache->get(3)<<std::endl;
    std::cout<<cache->get(4)<<std::endl;
    
    delete cache;
}
