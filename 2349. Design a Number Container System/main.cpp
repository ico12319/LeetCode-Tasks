#include "number_container.h"

int main(int argc, const char * argv[]) {
    number_contaner* container = new number_contaner();
    //std::cout<<container->find(10)<<std::endl;
    container->change(1, 10);
    std::cout<<container->find(10)<<std::endl;
    container->change(1, 20);
    std::cout<<container->find(10)<<std::endl;
    std::cout<<container->find(20)<<std::endl;
    std::cout<<container->find(30)<<std::endl;
    
    delete container;
}
