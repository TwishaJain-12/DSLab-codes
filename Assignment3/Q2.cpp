//Given a string, reverse it using STACK
//Stack implementation using array
#include<iostream>
using namespace std;
struct Stack{
    int top=-1;
    int n;
    char st[100];
} S;

bool isEmpty(){
    if(S.top == -1){
        cout<<endl<<"Underflow Condition. The stack is empty."<<endl;
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if(S.top == S.n - 1){
        cout<<"Overflow Condition. The stack is full. No more elements can be entered."<<endl;
        return true;
    }
    else{
        return false;
    }
}

void push(char x){
    if(!isFull()){
        S.top = S.top + 1;
        S.st[S.top] = x;
    }

}

void pop(){
        cout<<S.st[S.top];
        S.top = S.top - 1;
}

int main(){
    S.n = 100;
    char str[60];
    cout<<"Enter the string: ";
    cin.getline(str,60);
    int i=0;
    while(str[i]!='\0'){
        push(str[i++]);
    }
    
    cout<<"The Reversed String is: ";
    while(!isEmpty()){
        pop();
    }
    cout<<endl;
    return 0;
}