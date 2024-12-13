#include <iostream>
#include <list>

class first_unique_integer{
private:
    using iterator = std::list<int>::iterator;
    std::list<int> stream;
    std::unordered_map<int, std::pair<int,iterator>> map;

public:
    first_unique_integer() = default;
    void add(int num){
        auto it = map.find(num);
        if(it == map.end()){
            stream.push_back(num);
            map[num].first++;
            map[num].second = --stream.end();
            return;
        }
        if(it->second.second != stream.end())
            stream.erase(it->second.second);
        map[num].first++;
        map[num].second = stream.end();
    }
    int show() const{
        if(stream.empty()) return -1;
        return *stream.begin();
    }
};

int main(int argc, const char * argv[]) {
    first_unique_integer first;
    first.add(2);
    first.add(3);
    std::cout<<first.show()<<std::endl;
    first.add(2);
    std::cout<<first.show()<<std::endl;
    first.add(5);
    first.add(3);
    first.add(3);
    std::cout<<first.show()<<std::endl;
}
