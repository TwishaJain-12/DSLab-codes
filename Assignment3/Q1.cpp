//Stack implementation using array
#include<iostream>
using namespace std;
struct Stack{
    int top=-1;
    int n;
    int st[10];
} S;

bool isEmpty(){
    if(S.top == -1){
        cout<<"Underflow Condition. The stack is empty."<<endl;
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

void push(int x){
    if(!isFull()){
        S.top = S.top + 1;
        S.st[S.top] = x;
    }
}

void pop(){
    if(!isEmpty()){
        cout<<"The element - "<<S.st[S.top]<<" is deleted."<<endl;
        S.top = S.top - 1;
    }
}

void peek(){
    if(!isEmpty())
        cout << "Top element: " << S.st[S.top] << endl;
}

void display(){
    if(isEmpty()) return;
    cout<<endl;
    for(int i = S.top; i >= 0; i--){
        cout << S.st[i] << "\n";
    }

}

int main(){
    bool flag=1;
    S.n = 10;
    int x;
    while(flag){
        int menu;
        cout<<endl<<"Choose an operation to perform on Stack: "<<endl<<"1. push()"<<endl<<"2. pop()"<<endl<<"3. isEmpty()"<<endl<<"4. isFull()"<<endl<<"5. peek()"<<endl<<"6. display()"<<endl<<"7. EXIT"<<endl<<": ";
        cin>>menu;
        switch(menu){
            case 1: //push
                cout<<endl<<"Enter the element to be pushed into the Stack: ";
                cin>>x;
                push(x);
                break;
            
            case 2: //pop
                pop();
                break;
            
            case 3: //isEmpty
                if(!isEmpty()){
                    cout<<"The Stack is not empty!"<<endl;
                }
                break;

            case 4: //isFull
                if(!isFull()){
                    cout<<"The Stack is not full!"<<endl;
                }
                break;

            case 5: //peek
                peek();
                break;

            case 6:
                display();
                break;

            default:
                flag=0;
                break;
        }
    }
    cout<<"The program has been exited!"<<endl;
    return 0;
}