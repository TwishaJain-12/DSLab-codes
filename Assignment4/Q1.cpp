/*Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/
#include<iostream>
using namespace std;
class Queue{
    int size=5;
    int q[5];
    int cursize=0;
    int start=-1;
    int end=-1;

    public:
    void enqueue(int x){
        if(cursize==size){
            //queue is full
            cout<<"The queue is full. No more elements can be inserted!"<<endl;
        }

        if(cursize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%size;
        }
        q[end]=x;
        cursize=cursize+1;
    }

    int dequeue(){
        if(cursize==0){
            cout<<"The queue is empty!"<<endl;
        }
        int ele=q[start];
        if(cursize==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%size;
        }
        cursize=cursize-1;
        return ele;
    }

    bool isEmpty(){
        if(cursize==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool isFull(){
        if(cursize==size){
            return 1;
        }
        else{
            return 0;
        }
    }

    int peek(){
        if(isEmpty()){
            cout<<"The queue is empty!"<<endl;
        }
        return q[start];
    }

    void display(){
        if(isEmpty()){
            cout<<"The queue is empty!"<<endl;
        }
        for(int i=0; i<size; i++){
            cout<<q[i]<<"\t";
        }
        cout<<endl;
    }
};

int main(){
    Queue Q;
    bool flag=1;
    int x;
    while(flag){
        int menu;
        cout<<endl<<"Choose an operation to perform on Queue: "<<endl<<"1. push()"<<endl<<"2. pop()"<<endl<<"3. isEmpty()"<<endl<<"4. isFull()"<<endl<<"5. peek()"<<endl<<"6. display()"<<endl<<"7. EXIT"<<endl<<": ";
        cin>>menu;
        switch(menu){
            case 1: //push
                cout<<endl<<"Enter the element to be inserted into the Queue: ";
                cin>>x;
                Q.enqueue(x);
                break;
            
            case 2: //pop
                cout<<Q.dequeue()<<" element has been deleted!"<<endl;
                break;
            
            case 3: //isEmpty
                if(!Q.isEmpty()){
                    cout<<"The Queue is not empty!"<<endl;
                }
                break;

            case 4: //isFull
                if(!Q.isFull()){
                    cout<<"The Queue is not full!"<<endl;
                }
                break;

            case 5: //peek
                cout<<Q.peek()<<" is the Top element."<<endl;
                break;

            case 6:
                Q.display();
                break;

            default:
                flag=0;
                break;
        }
    }
    cout<<"The program has been exited!"<<endl;
    return 0;
}