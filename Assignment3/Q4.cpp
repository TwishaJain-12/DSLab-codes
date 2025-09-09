//Write a program to convert an Infix expression into a Postfix expression.
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

int Precedence(char x){
    if(x=='^') return 3;
    if(x=='*' || x=='/') return 2;
    if(x=='+' || x=='-') return 1;
    else return 0;
}

int main(){
    Stack S;
    char exp[30], result[30];
    char op[5] = {'+', '-', '*', '/', '^'};
    cout<<"Enter the infix expression: ";
    cin>>exp;
    int i=0, j=0;
    while(exp[i]!='\0'){
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='('){
            S.push(exp[i]);
        }
        
        else if(exp[i]>='A' && exp[i]<='Z'){
            result[j++]=exp[i];
        }

        else if(exp[i]==op[0] || exp[i]==op[1] ||  exp[i]==op[2] ||  exp[i]==op[3] ||  exp[i]==op[4]){
            while(!S.isEmpty() && Precedence(S.peek()) >= Precedence(exp[i])){
                result[j++]=exp[i];
                S.pop();
            }
            S.push(exp[i]);
        }

        else if(exp[i]=='}' || exp[i]==']' || exp[i]==')'){
            while(!S.isEmpty() && !(S.peek() == '(' || S.peek() == '[' || S.peek() == '{')){
                result[j++]=S.peek();
                S.pop();
            }
            if (!S.isEmpty()) S.pop();
        }
        i++;
    }

    while(!S.isEmpty()){
        result[j++] = S.peek();
        S.pop();
    }

    result[j] = '\0';

    cout << "The Postfix expression is: "<< result<<endl;

    return 0;
}