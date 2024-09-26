#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <string>
#include <stack>

// 1700. Number of Students Unable to Eat Lunch
// The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.Otherwise, they will leave it and go to the queue's end.This continues until none of the queue students want to take the top sandwich and are thus unable to eat.You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

std::queue<int> putDataInQueue(std::vector<int>& v){
    const size_t size = v.size();
    std::queue<int> q;
    for(int i = 0;i<size;i++)
        q.push(v[i]);
    return q;
}

std::stack<int> putDataInStack(std::vector<int>& v){
    const size_t size = v.size();
    std::stack<int> s;
    for(int i = size - 1;i>=0;i--)
        s.push(v[i]);
    return s;
}

size_t countStudents(std::vector<int>& students,std::vector<int>& sandwiches){
    int count = 0;
    std::queue<int> st = putDataInQueue(students);
    std::stack<int> sa = putDataInStack(sandwiches);
    
    while(!st.empty()){
        int currStudent = st.front();
        int currSand = sa.top();
        if(currSand == currStudent){
            count = 0;
            st.pop();
            sa.pop();
        }
        else{
            st.pop();
            st.push(currStudent);
            count++;
            if(count == st.size())
                break;
        }
        
    }
    return st.size();
}

int main(){
    std::vector<int> st = {1,1,1,0,0,1};
    std::vector<int> sa = {1,0,0,0,1,1};
    std::cout<<countStudents(st, sa)<<std::endl;
    
    
}
