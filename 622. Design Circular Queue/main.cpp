#include <iostream>

//622. Design Circular Queue
//Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

class circular_queue{
private:
    std::vector<int> data;
    size_t capacity;
    size_t tail;
    size_t head;
    size_t size;
    
    void move_index(size_t& index,bool forward){
        if(forward)
            ++(index) %= capacity;
        else
            index = (index == 0) ? capacity - 1 : index - 1;
    }
    
public:
    circular_queue(int k) : capacity(k),head(0),tail(0){
        data.resize(k);
    }
    bool empty() const{
        return size == 0;
    }
    
    void push_back(int el){
        if(size == capacity)
            return;
        data[tail] = el;
        move_index(tail, true);
        size++;
    }
    void pop_front(){
        if(empty())
            return;
        move_index(head, true);
        size--;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
