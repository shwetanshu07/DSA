/*
Given string str representing a postfix expression, the task is to evaluate the expression
and print the final value.

Input: str = "231*+9-"
Output: -4
*/


#include <iostream>
#include <stack>
#include <cmath>

int calculate(int a, int b, char op){
    int result;
    if(op=='+') result = a+b;
    if(op=='-') result = a-b;
    if(op=='*') result = a*b;
    if(op=='/') result = a/b;
    if(op=='^') result = pow(a,b);
    return result;
}


int evaluatePostfix(std::string postfix){
    std::stack<int> mystack;
    for(int i=0; i<postfix.length(); i++){
        char ch = postfix[i];
        if(ch>=48 && ch<=57){
            //48 is ascii for 0 and 57 is ascii for 9
            int n = (int)ch - 48;
            mystack.push(n);
        }
        else{
            // ch is operator
            int b = mystack.top();
            mystack.pop();
            int a = mystack.top();
            mystack.pop();
            int result = calculate(a, b, ch);
            mystack.push(result);
        }

    }
    return mystack.top();
}


int main(){
    std::string postfix = "231*+9-";
    int value = evaluatePostfix(postfix);
    std::cout<<"Expression: "<<postfix<<std::endl;
    std::cout<<"Result: "<<value;
    return 0;
}
