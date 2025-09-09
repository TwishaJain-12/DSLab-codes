//Stack implementation using array
#include<iostream>
using namespace std;
class Stack{
    int top=-1;
    int n=10;
    int st[10];

    public: 
    bool isEmpty(){
        if(top == -1){
            cout<<"Underflow Condition. The stack is empty."<<endl;
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(top >= n - 1){
            cout<<"Overflow Condition. The stack is full. No more elements can be entered."<<endl;
            return true;
        }
        else{
            return false;
        }
    }
    
    void push(int x){
        if(!isFull()){
            top = top + 1;
            st[top] = x;
        }
    }
    
    void pop(){
        if(!isEmpty()){
            cout<<"The element - "<<st[top]<<" is deleted."<<endl;
            top = top - 1;
        }
    }
    
    void peek(){
        if(!isEmpty())
            cout << "Top element: " << st[top] << endl;
    }
    
    void display(){
        if(isEmpty()) return;
        cout<<endl;
        for(int i = top; i >= 0; i--){
            cout << st[i] << "\n";
        }
    
    }
};


int main(){
    Stack S;
    bool flag=1;
    int x;
    while(flag){
        int menu;
        cout<<endl<<"Choose an operation to perform on Stack: "<<endl<<"1. push()"<<endl<<"2. pop()"<<endl<<"3. isEmpty()"<<endl<<"4. isFull()"<<endl<<"5. peek()"<<endl<<"6. display()"<<endl<<"7. EXIT"<<endl<<": ";
        cin>>menu;
        switch(menu){
            case 1: //push
                cout<<endl<<"Enter the element to be pushed into the Stack: ";
                cin>>x;
                S.push(x);
                break;
            
            case 2: //pop
                S.pop();
                break;
            
            case 3: //isEmpty
                if(!S.isEmpty()){
                    cout<<"The Stack is not empty!"<<endl;
                }
                break;

            case 4: //isFull
                if(!S.isFull()){
                    cout<<"The Stack is not full!"<<endl;
                }
                break;

            case 5: //peek
                S.peek();
                break;

            case 6:
                S.display();
                break;

            default:
                flag=0;
                break;
        }
    }
    cout<<"The program has been exited!"<<endl;
    return 0;
}