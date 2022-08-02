#include"../inc/solution.hpp"
#include<unordered_map>
#include<stack>


int Solution::evalRPN(std::vector<std::string>& tokens)
{
    enum Operator{plus,minus,multiply,divide};  // switch requires integral / enumeration type as conditional argument
    std::unordered_map<std::string,Operator> opMap{{"+",Operator::plus},{"-",Operator::minus},  // construct a map to convert input to enum type
                                                    {"*",Operator::multiply},{"/",Operator::divide}};
    std::stack<std::string> calcStack{};  // RPN calculations are easily evaluated using a stack

    auto it = tokens.begin();
    while(it != tokens.end())
    {
        if(opMap.contains(*it))  // if token is an operator
        {
            int op2 = std::stoi(calcStack.top()); calcStack.pop();  // second operand is first to be popped
            int op1 = std::stoi(calcStack.top()); calcStack.pop();
            int res{0};
            switch(opMap[*it])  // compute the intermediate result
            {
                case 0: res = op1 + op2; break;
                case 1: res = op1 - op2; break;
                case 2: res = op1 * op2; break;
                case 3: res = op1 / op2; break;
            };
            calcStack.push(std::to_string(res));  // push intermediate result onto the stack
        }
        else{ calcStack.push(*it); }  // if token is a operand
        ++it;
    }
    return std::stoi(calcStack.top());  // final result (a string) will be last remaining element on the stack
}