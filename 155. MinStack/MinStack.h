#include <iostream>
#include <stack>

class MinStack{
private:
    std::stack<int> currValues;
    std::deque<int> minValues;
    
    
public:
    MinStack() = default;
    void push(int val);
    void pop();
    int top() const;
    int getMin() const;
    
};
