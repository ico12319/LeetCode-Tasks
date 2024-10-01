#include <iostream>
#include <stack>

//150. Evaluate Reverse Polish Notation
//You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.Evaluate the expression. Return an integer that represents the value of the expression.

bool isOperation(std::string& str){
    if(str.length() > 1)
        return false;
    
    return str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/';
}

int applyOperation(std::string& str,int num1,int num2){
    if(str[0] == '+')
        return num1 + num2;
    else if(str[0] == '-')
        return num1 - num2;
    else if(str[0] == '*')
        return num1 * num2;
    else if(str[0] == '/')
        return num1 / num2;
    
    throw std::invalid_argument("Invalid operation!");
}

int evalRPN(std::vector<std::string>& n){
    const size_t size = n.size();
    std::stack<int> result;
    for(int i = 0;i<size;i++){
        if(isOperation(n[i])){
            if(!result.empty()){
                int second = result.top();
                result.pop();
                int first = result.top();
                result.pop();
                int numAfterOperation = applyOperation(n[i], first, second);
                result.push(numAfterOperation);
            }
        }
        else{
            int num = std::stoi(n[i]);
            result.push(num);
        }
    }
    return result.top();
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> rpn = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout<<evalRPN(rpn)<<std::endl;

}
