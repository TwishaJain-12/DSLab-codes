//WAP to count the no. of occurrences of a given key in a SLL and then delete all the occurrences
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
    int d, n, key, cnt=0;
    cout<<"Enter the number of elements in the LL: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter the value of node to be inserted: ";
        cin>>d;
        insertAtTail(head, tail, d);
    }
    cout<<"Enter the key: ";
    cin>>key;
    
    Node* temp = head;
    while(temp!=NULL){
        if(key==temp->data){
            cnt++;
        }
        temp=temp->next;
    }
    cout<<"Total number of keys: "<<cnt<<endl;
    int i=1;
    while(i<=cnt){
        deleteNode(key, head, tail);
        i++;
    }
    print(head);
    return 0;
}