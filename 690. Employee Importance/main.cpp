#include <iostream>
#include <queue>

//690. Employee Importance
//You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.You are given an array of employees employees where:employees[i].id is the ID of the ith employee.employees[i].importance is the importance value of the ith employee.employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.

class employee{
public:
    int id;
    int imprtance;
    std::vector<int> subordinates;
    
    employee(int id,int importance,std::vector<int>& subordinates) : id(id),imprtance(importance),subordinates(subordinates){}
};

int get_importance(std::vector<employee*> employees,int id){
    std::unordered_map<int,employee*> emp_info;
    for(const auto& employee : employees)
        emp_info[employee->id] = employee;
    
    std::queue<employee*> q;
    q.push(emp_info[id]);
    int total_importance = 0;
    while(!q.empty()){
        employee* curr = q.front();
        q.pop();
        total_importance += curr->imprtance;
        for(const auto& child : curr->subordinates){
            if(child)
                q.push(emp_info[child]);
        }
    }
    return total_importance;
}


int main(int argc, const char * argv[]) {
    std::vector<employee*> emp;
    std::vector<int> emp1_children = {2,3};
    std::vector<int> emp2_children = {};
    std::vector<int> emp3_children = {};
    employee* emp1 = new employee(1,5,emp1_children);
    employee* emp2 = new employee(2,3,emp2_children);
    employee* emp3 = new employee(3,3,emp3_children);
    
    emp.push_back(emp1);
    emp.push_back(emp2);
    emp.push_back(emp3);
    
    std::cout<<get_importance(emp, 1)<<std::endl;
}
