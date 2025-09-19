#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    //destrcutor
    ~Node(){
        int value = this->data;
        cout<<"Memory freed for node with data "<<value<<endl;
    }
};

void insertNode(Node* &tail, int ele, int d){
    //empty list
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* curr = tail;
        while(curr->data!=ele){
            curr=curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* &tail){
    if(tail == NULL){
        cout<<"The list is empty!"<<endl;
        return;
    }
    Node* temp =tail;
    do{
        cout<<temp->data<<"  ";
        temp = temp->next;
    } while(temp!=tail);
    cout<<temp->data;
    cout<<endl;
}

int main(){
    Node* tail = NULL;
    int menu, d, ele;
    do{
        cout<<"MENU for circular linked list: "<<endl<<"1. Insertion"<<endl<<"2. EXIT"<<endl;
        cout<<"Enter the option: ";
        cin>>menu;
        switch(menu){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>d;
                cout<<"Enter the element after which it has to be inserted: ";
                cin>>ele;
                insertNode(tail, ele, d);
                break;

            case 2:
                cout<<"The insertion has been exited!"<<endl;
                break;
        }
    }while(menu<2);

    cout<<"The circular linked list is: ";
    print(tail);
}