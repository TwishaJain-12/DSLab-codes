//Write a program for the evaluation of a Postfix expression. 
#include<iostream>
using namespace std;
class Stack{
    int top=-1;
    int n=30;
    int st[30];

    public: 
    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top >= n - 1);
    }
    
    void push(int x){
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
    
    int peek() {
        if(!isEmpty()) {
            return st[top];
        }
        return '\0'; 
    }
};

int main(){
    Stack S;
    char exp[30];
    int result=0;
    int d1,d2;
    char op[5] = {'+', '-', '*', '/'};
    cout<<"Enter the postfix expression: ";
    cin>>exp;
    int i=0;
    while(exp[i]!='\0'){
        if(exp[i]>='0' && exp[i]<='9'){
            S.push(exp[i]-'0');
        }

        else if(exp[i]==op[0] || exp[i]==op[1] ||  exp[i]==op[2] ||  exp[i]==op[3]){
                d1 = S.peek();
                S.pop();
                d2 = S.peek();
                S.pop();

                if(exp[i]==op[0]){
                    result = (d2+d1);
                }
                else if(exp[i]==op[1]){
                    result = (d2-d1);
                }
                else if(exp[i]==op[2]){
                    result = (d2*d1);
                }
                else if(exp[i]==op[3]){
                    result = (d2/d1);
                }
                S.push(result);
        }
        i++;
    }

    cout << "The Postfix evaluation is: "<< S.peek()<<endl;

    return 0;
}