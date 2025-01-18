#include <iostream>

//75. Sort Colors
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.You must solve this problem without using the library's sort function.

size_t get_left_child(size_t parent_index){
    return 2 * parent_index + 1;
}


size_t get_right_child(size_t parent_index){
    return 2 * parent_index + 2;
}


void heapify(std::vector<int>& heap,size_t size,size_t index){
    while(true){
        auto left_child_index = get_left_child(index);
        auto right_child_index = get_right_child(index);
        
        bool should_go_left = left_child_index < size && heap[index] < heap[left_child_index];
        bool should_go_right = right_child_index < size && heap[index] < heap[right_child_index];
        
        if(should_go_left && should_go_right){
            if(heap[left_child_index] > heap[right_child_index]){
                std::swap(heap[left_child_index],heap[index]);
                index = left_child_index;
            }
            else{
                std::swap(heap[right_child_index],heap[index]);
                index = right_child_index;
            }
        }
        else if(should_go_left){
            std::swap(heap[left_child_index],heap[index]);
            index = left_child_index;
        }
        else if(should_go_right){
            std::swap(heap[right_child_index],heap[index]);
            index = right_child_index;
        }
        else
            break;
    }
}


void sort_colors(std::vector<int>& v){
    for(int i = v.size() / 2 - 1;i >= 0; i--)
        heapify(v, v.size(), i);
    
    for(int i = v.size();i>=1;i--){
        std::swap(v[0],v[i - 1]);
        heapify(v, i - 1, 0);
    }
}

int main(int argc, const char * argv[]) {
    std::vector<int> colors = {2,0,2,1,1,0};
    sort_colors(colors);
    for(const auto& color : colors)
        std::cout<<color<<" ";
}
