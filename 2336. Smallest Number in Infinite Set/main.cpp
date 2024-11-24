#include "infinite_set.h"

//2336. Smallest Number in Infinite Set

int main(int argc, const char * argv[]) {
    infinte_set* set = new infinte_set();
    set->add_back(2);
    std::cout<<set->pop_smallest()<<std::endl;
    std::cout<<set->pop_smallest()<<std::endl;
    std::cout<<set->pop_smallest()<<std::endl;
    set->add_back(1);
    std::cout<<set->pop_smallest()<<std::endl;
    std::cout<<set->pop_smallest()<<std::endl;
    std::cout<<set->pop_smallest()<<std::endl;
    
    delete set;
}
