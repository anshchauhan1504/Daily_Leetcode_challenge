// 150. Evaluate Reverse Polish Notation

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
// Note that division between two integers should truncate toward zero.
// It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

//This is the standard question of stack.....Very important
//Logic is written in notebook

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>s1;
        for(auto x:tokens)//It will automately increment
        {
            if(x!="+" && x!="*" && x!="-" && x!="/")
            {
                s1.push(stoi(x));//stoi is a inbuilt fun which converts string into integer
            }
            else{
                long long a=s1.top();
                s1.pop();
                long long b=s1.top();
                s1.pop();
                if(x=="+")
                {
                    s1.push(a+b);
                }
                if(x=="*")
                {
                    s1.push(a*b);
                }
                if(x=="-")
                {
                    s1.push(b-a);
                }
                if(x=="/")
                {
                    s1.push(b/a);
                }
            }

        }
        return s1.top();
    }
};