#include <iostream>
#include <forward_list>

//1352. Product of the Last K Numbers
//Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.Implement the ProductOfNumbers class:

class product_of_numbers{
private:
    std::forward_list<int> last_nums;
    
public:
    product_of_numbers() = default;
    void add(int num){
        last_nums.push_front(num);
    }
    int get_product(int k){
        int product = 1;
        for(auto it = last_nums.begin();it!=last_nums.end();it++){
            product*=*it;
            k--;
            if(k <= 0)
                break;
        }
        return product;
    }
};


int main(int argc, const char * argv[]) {
    product_of_numbers nums;
    nums.add(3);
    nums.add(0);
    nums.add(2);
    nums.add(5);
    nums.add(4);
    
    std::cout<<nums.get_product(2)<<std::endl;
    std::cout<<nums.get_product(3)<<std::endl;
    std::cout<<nums.get_product(4)<<std::endl;
}
