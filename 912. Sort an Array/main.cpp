#include <iostream>
#include <queue>

//912. Sort an Array
//Given an array of integers nums, sort the array in ascending order and return it.You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

struct priority_queue{
    std::vector<int> heap_candidate;
    
    static size_t left_child_index(size_t index){
        return 2 * index + 1;
    }
    static size_t right_child_index(size_t index){
        return 2 * index + 2;
    }
    
    void heapify(size_t index){
        while(true){
            size_t left_index = left_child_index(index);
            size_t right_index = right_child_index(index);
            
            bool go_left = left_index < heap_candidate.size() && heap_candidate[left_index] < heap_candidate[index];
            bool go_right = right_index < heap_candidate.size() && heap_candidate[right_index] < heap_candidate[index];
            
            if(go_left && !go_right){
                std::swap(heap_candidate[left_index], heap_candidate[index]);
                index = left_index;
            }
            else if(!go_left && go_right){
                std::swap(heap_candidate[right_index], heap_candidate[index]);
                index = right_index;
            }
            else if(go_left && go_right){
                if(heap_candidate[left_index] < heap_candidate[right_index]){
                    std::swap(heap_candidate[left_index],heap_candidate[index]);
                    index = left_index;
                }
                else{
                    std::swap(heap_candidate[right_index],heap_candidate[index]);
                    index = right_index;
                }
            }
            else
                break;
        }
    }
    
    void pop(){
        if(heap_candidate.empty()) return;
        if(heap_candidate.size() == 1){
            heap_candidate.pop_back();
            return;
        }
        std::swap(heap_candidate[0],heap_candidate[heap_candidate.size() - 1]);
        heap_candidate.pop_back();
        heapify(0);
    }
    
    int top() const{
        return heap_candidate[0];
    }
    
    priority_queue(std::vector<int>& v){
        this->heap_candidate = v;
        for(int i = v.size() / 2  - 1;i>=0;i--)
            heapify(i);
    }
    
    bool empty() const{
        return heap_candidate.size() == 0;
    }
};


std::vector<int> sortArray(std::vector<int>& nums) {
    priority_queue pq(nums);
    int index = 0;
    while (!pq.empty()) {
        nums[index++] = pq.top();
        pq.pop();
    }
    return nums;
    
}

int main(int argc, const char * argv[]) {
    std::vector<int> v = {5,1,1,2,0,0};
    v = sortArray(v);
    for(const auto& el : v)
        std::cout<<el<<" ";
}
