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

void insertAtHead(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == NULL){   // empty list
        head = temp;
        tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

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

void deleteNode(int ivalue, Node* &head, Node* &tail){
    if(ivalue==head->data){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        
        do{
        prev = curr;
        curr = curr->next;
        }
        while(ivalue!=curr->data);
        
        if(curr->next==NULL){
            tail = prev;
        }
            
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
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
    int menu, d, cnt=0;
    bool flag=true;
    while(flag){
        cout<<"Option 1: Insert an element; Option 2: Stop; Select: ";
        cin>>menu;
        switch(menu){
            case 1:
            cout<<"Enter the value of node to be inserted: ";
            cin>>d;
            insertAtTail(head, tail, d);
            cnt++;
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
    
    // Node* temp = head;
    // while(temp!=NULL){
    //     cnt++; 
    //     temp=temp->next;
    // }
    print(head);
    cout<<"Total number of elements are: "<<cnt<<endl;
    Node* mid = head;
    int i=1;
    while(i<cnt/2){
        mid=mid->next;
        i++;
    }
    if(cnt%2==0){
        cout<<mid->data<<"  ";
        mid=mid->next;
        cout<<mid->data<<endl;
    }
    else{
        mid=mid->next;
        cout<<mid->data<<endl;
    }
    
    return 0;
}