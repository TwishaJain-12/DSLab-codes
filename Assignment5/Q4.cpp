#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node* next;
    //Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //Destructor
    ~Node(){
        int value = this->data;
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d){
    Node* ins = new Node(d);
    if(head == NULL){   // empty list
        head = ins;
        tail = ins;
    }
    else {
        tail->next = ins;
        tail = ins;
    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp = temp->next; 
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int menu, d;
    bool flag=true;
    while(flag){
        cout<<"Option 1: Insert an element; Option 2: Stop; Select: ";
        cin>>menu;
        switch(menu){
            case 1:
            cout<<"Enter the value of node to be inserted: ";
            cin>>d;
            insertAtTail(head, tail, d);
            break;
    
            case 2:
            cout<<"Insertion completed"<<endl;
            flag=false;
            break;
    
            default:
            cout<<"Error!"<<endl;
            flag=false;
            break;
        }
    }
    cout<<"Original LL: ";
    print(head);
    Node* temp=head;
    Node* prev=NULL;
    tail = head; //for reversed ll
    while(temp!=NULL){
        Node* after=temp->next;
        temp->next=prev;
        prev=temp; //update prev
        head=temp; //update head for reversed ll
        temp=after; //update temp
    }
    cout<<"Reversed LL: ";
    print(head);

    cout<<head->data<<"  "<<tail->data;
    
    return 0;
}