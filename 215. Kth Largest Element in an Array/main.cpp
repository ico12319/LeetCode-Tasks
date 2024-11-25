#include <iostream>

//215. Kth Largest Element in an Array
//Given an integer array nums and an integer k, return the kth largest element in the array.Note that it is the kth largest element in the sorted order, not the kth distinct element.Can you solve it without sorting?

void heapify(std::vector<int>& heap,size_t index){
    
    while(true){
        size_t left_child_index = 2 * index + 1;
        size_t right_child_index = 2 * index + 2;
        
        bool go_left = left_child_index < heap.size() && heap[left_child_index] > heap[index];
        bool go_right = right_child_index < heap.size() && heap[right_child_index] > heap[index];
        
        if(go_left && !go_right){
            std::swap(heap[left_child_index],heap[index]);
            index = left_child_index;
        }
        else if(!go_left && go_right){
            std::swap(heap[right_child_index], heap[index]);
            index = right_child_index;
        }
        else if(go_left && go_right){
            if(heap[left_child_index] > heap[right_child_index]){
                std::swap(heap[left_child_index],heap[index]);
                index = left_child_index;
            }
            else{
                std::swap(heap[right_child_index],heap[index]);
                index = right_child_index;
            }
        }
        else
            break;
    }
    
}


void turn_to_heap(std::vector<int>& heap_candidate){
    for(int i = heap_candidate.size() / 2 - 1;i>=0;i--)
        heapify(heap_candidate, i);
}


void pop_from_heap(std::vector<int>& heap){
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    heapify(heap, 0);
}


int find_kth_largest(std::vector<int>& nums, int k) {
    turn_to_heap(nums);
    
    for(int i = 0;i<k - 1;i++)
        pop_from_heap(nums);
    
    return nums[0];
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> heap = {3,2,3,1,2,4,5,5,6};
    //std::cout<<std::endl;
    std::cout<<find_kth_largest(heap, 4)<<std::endl;
    
}
