// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<iostream>
#include"../inc/solution.hpp"

int main()
{
	//std::vector<std::string> tokens{"2","1","+","3","*"};  // 9
	//std::vector<std::string> tokens{"4","13","5","/","+"};  // 6
	std::vector<std::string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};  // 22 
	Solution sol;
	std::cout << sol.evalRPN(tokens);
	return 0;
}

