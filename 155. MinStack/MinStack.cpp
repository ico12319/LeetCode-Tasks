#include <stdio.h>
#include "MinStack.h"

void MinStack::push(int val){
    currValues.push(val);
    if(minValues.empty()){
        minValues.push_back(val);
        return;
    }
    if(minValues.front() >= val)
        minValues.push_front(val);
    else
        minValues.push_back(val);
}

int MinStack::top() const{
    return currValues.top();
}

int MinStack::getMin() const{
    if(currValues.empty())
        return 0;
    return minValues.front();
}


void MinStack::pop(){
    if(currValues.empty())
        return;
    
    int currValue = currValues.top();
    if(currValue == minValues.front())
        minValues.pop_front();
    
    currValues.pop();
}
