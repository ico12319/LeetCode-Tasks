#include <stdio.h>
#include "infinite_set.h"

int infinte_set::pop_smallest(){
    if(!infinite.empty()){
        int to_return = *infinite.begin();
        infinite.erase(infinite.begin());
        return to_return;
    }
    return smallest_popped++;
}

void infinte_set::add_back(int num){
    if(num < smallest_popped)
        infinite.insert(num);
}
