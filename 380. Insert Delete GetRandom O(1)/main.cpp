#include <iostream>

//380. Insert Delete GetRandom O(1)

class randomized_set{
private:
    std::unordered_map<int, int> num_ind;
    std::vector<int> nums;
public:
    randomized_set() = default;
    bool insert(int val){
        if(num_ind.contains(val))
            return false;
        nums.push_back(val);
        num_ind[val] = nums.size() - 1;
        return true;
    }
    bool remove(int val){
        if(!num_ind.contains(val))
            return false;
        int index = num_ind[val];
        if(index != nums.size() - 1){
            int last_val = nums[nums.size() - 1];
            nums[index] = last_val;
            num_ind[last_val] = index;
        }
        nums.pop_back();
        num_ind.erase(val);
        return true;
    }
    int get_random() const{
        int randomIndex = std::rand() % nums.size();
        return nums[randomIndex];
    }
};

int main(int argc, const char * argv[]) {
    randomized_set set;
    std::cout<<set.insert(1)<<std::endl;
    std::cout<<set.remove(2)<<std::endl;
    std::cout<<set.insert(2)<<std::endl;
    std::cout<<set.get_random()<<std::endl;
    std::cout<<set.remove(1)<<std::endl;
    std::cout<<set.insert(2)<<std::endl;
    std::cout<<set.get_random()<<std::endl;
    
}
