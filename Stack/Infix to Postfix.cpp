#include <iostream>
#include <stack>

bool isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
        return true;
    }
    else return false;
}

int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

std::string infixToPostfix(std::string infix){
    std::string postfix;
    std::stack<char> mystack;
    for(int i=0; i<infix.length(); i++){
        char ch = infix[i];
        // check if ch is operand
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
            postfix = postfix + ch;
        }
        // check if ch is opening bracket
        else if(ch=='('){
            mystack.push(ch);
        }
        // if ch is a closing bracket
        else if(ch==')'){
            while(mystack.top()!='(' && !mystack.empty()){
                char temp = mystack.top();
                postfix = postfix + temp;
                mystack.pop();
            }
            if(mystack.top()=='(') mystack.pop();
        }
        // if ch is operator
        else if(isOperator(ch)){
            if(mystack.empty()){
                mystack.push(ch);
            }
            else{
                if(precedence(ch)>precedence(mystack.top())){
                    mystack.push(ch);
                }
                else if(precedence(ch)==precedence(mystack.top()) && ch=='^'){
                    mystack.push(ch);
                }
                else{
                    // precedence(ch)<=precedence(mystack.top())
                    while(!mystack.empty() && precedence(ch)<=precedence(mystack.top())){
                        postfix = postfix + mystack.top();
                        mystack.pop();
                    }
                    mystack.push(ch);
                }
            }
        }
    }
    // popping remaining ch in stack
    while(!mystack.empty()){
        postfix = postfix + mystack.top();
        mystack.pop();
    }
    return postfix;
}

int main(){
    std::string infix, result;
    infix = "a+b*(c^d-e)^(f+g*h)-i";
    std::cout<<"Infix expression:"<<std::endl;
    std::cout<<infix<<std::endl;
    result = infixToPostfix(infix);
    std::cout<<"Postfix expression:"<<std::endl;
    std::cout<<result;
    return 0; 
}
