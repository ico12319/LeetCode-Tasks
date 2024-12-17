#include <iostream>
#include <unordered_set>

//2103. Rings and Rods
//There are n rings and each ring is either red, green, or blue. The rings are distributed across ten rods labeled from 0 to 9.You are given a string rings of length 2n that describes the n rings that are placed onto the rods. Every two characters in rings forms a color-position pair that is used to describe each ring where:The first character of the ith pair denotes the ith ring's color ('R', 'G', 'B').The second character of the ith pair denotes the rod that the ith ring is placed on ('0' to '9').For example, "R3G2B1" describes n == 3 rings: a red ring placed onto the rod labeled 3, a green ring placed onto the rod labeled 2, and a blue ring placed onto the rod labeled 1.Return the number of rods that have all three colors of rings on them.

bool is_digit(char s){
    return s>='0' && s<='9';
}

size_t count_points(std::string& rings){
    std::unordered_map<char, std::unordered_set<char>> rod_color;
    int index = 0;
    
    while(index != rings.size()){
        if(is_digit(rings[index]))
            rod_color[rings[index]].insert(rings[index - 1]);
        index++;
    }
    size_t points = 0;
    for(const auto& pair : rod_color){
        if(pair.second.size() == 3)
            points++;
    }
    return points;
}


int main(int argc, const char * argv[]) {
    std::string rings = "G4";
    std::cout<<count_points(rings)<<std::endl;
}
