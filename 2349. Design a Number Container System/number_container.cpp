#include <stdio.h>
#include "number_container.h"

void number_contaner::change(int index, int number){
    if(ind_nums.count(index)){
        int old_number = ind_nums[index];
        map[old_number].erase(index);
        if(map[old_number].empty())
            map.erase(old_number);
    }
    ind_nums[index] = number;
    map[number].insert(index);
}

int number_contaner::find(int number){
    if(map.contains(number) && map[number].size() != 0)
        return *map[number].begin();
    return -1;
}
