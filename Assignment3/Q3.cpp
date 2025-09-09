//Write a program that checks if an expression has balanced parentheses. 
#include<iostream>
using namespace std;
class Stack{
    int top=-1;
    int n=30;
    char st[30];

    public: 
    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top >= n - 1);
    }
    
    void push(char x){
        if(!isFull()){
            top = top + 1;
            st[top] = x;
        }
    }
    
    void pop() {
        if(!isEmpty()) {
            top--;
        }
    }
    
    char peek() {
        if(!isEmpty()) {
            return st[top];
        }
        return '\0'; 
    }
};


int main(){
    Stack S;
    bool flag=true;
    char exp[30];
    cout<<"Enter the expression consisting of parenthesis: ";
    cin>>exp;
    int i=0;
    while(exp[i]!='\0'){
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='('){
            S.push(exp[i]);
        }

        else if(exp[i]==')'){
            if(S.isEmpty() || S.peek() != '(') {
                flag = false;
                break;
            }
            S.pop();
        }
        else if(exp[i]==']'){
            if(S.isEmpty() || S.peek() != '[') {
                flag = false;
                break;
            }
            S.pop();
        }
        else if(exp[i]=='}'){
            if(S.isEmpty() || S.peek() != '{') {
                flag = false;
                break;
            }
            S.pop();
        }
        i++;
    }

    if(flag && S.isEmpty()) {
        cout << "The expression has Balanced Parenthesis!" << endl;
    }
    else {
        cout << "The expression doesn't have Balanced Parenthesis!" << endl;
    }

    return 0;
}