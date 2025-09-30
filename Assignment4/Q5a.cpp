//stack using 2 queues
#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int>q1;
    queue<int>q2;
    int topEle;

    public:
    bool isEmpty(){
        if(q1.empty() && q2.empty()){
            return 1;
        }
        else{
            return 0;
        }
    }

    void push(int x){
        q1.push(x);
        topEle=x; //if no pop done, then jo last ele entered = top
    }

    void pop(){
        if(isEmpty()){
        cout << "Queue is empty, cannot delete!" << endl;
        return;
    }
        int n=q1.size();
        for(int i=1; i<n; i++){
            q2.push(q1.front());
            topEle = q1.front(); //pop will change my top to next element in stack jiske liye we update top
            q1.pop();
        }
        cout<<"The top element: "<<q1.front()<<" is deleted!"<<endl;
        q1.pop();

        queue<int>temp;
        temp = q1;
        q1=q2;
        q2=temp; //swapped q1 and q2
    }

    void peek(){
        if(isEmpty()){
        cout << "Queue is empty, no top element!" << endl;
        return;
    }
        cout<<"The top element: "<<topEle<<endl;
    }

};

int main(){
    Stack s;
    int x, menu;
    bool flag=1;
    while(flag){
        cout<<"1. Insert in stack"<<endl;
        cout<<"2. Delete an element"<<endl;
        cout<<"3. Top element ? "<<endl;
        cout<<"4. IsEmpty()"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Select: ";
        cin>>menu;
        switch(menu){
            case 1:
            cout<<"Enter the element to be pushed: ";
            cin>>x;
            s.push(x);
            break;
            
            case 2:
            s.pop();
            break;

            case 3:
            s.peek();
            break;

            case 4:
            if(s.isEmpty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<"Stack is not empty"<<endl;
            }
            break;

            case 5:
            cout<<"The program has been exited!"<<endl;
            flag=0;
            break;

            default:
            cout<<"ERROR!"<<endl;
            flag=0;
            break;
        }
    }
    return 0;
}