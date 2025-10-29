#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

    //destrcutor
    ~Node(){
        int value = this->data;
        cout<<"Memory freed for node with data "<<value<<endl;
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
        head->prev = temp;
        head = temp;
    }
}

void insertAfter(Node* &head, Node* &tail, int ivalue, int d){
    Node* temp=head; //traverse
    while(temp!=NULL){
        if(ivalue==temp->data){
            Node* newNode = new Node(d);
            if(temp->next == NULL){
                //insertAtTail
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
                break;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            break;
        }
        temp=temp->next;
    }
}

void deleteNode(int ivalue, Node* &head, Node* &tail){
    if(ivalue==head->data){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
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
            tail->next = NULL;
        }
            
        prev->next = curr->next;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

void search(Node* &head, int ivalue){
    Node* temp = head;
    int cnt=1;
    while(temp != NULL){
        if(ivalue== temp->data){
            cout<<"The node was found at "<<cnt<<" position (from head)"<<endl;
            break;
        }
        temp=temp->next;
        cnt++;
    }
    if(temp==NULL){
        cout<<"Element not found!"<<endl;
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
    int menu, d, ele;
    do{
        cout<<"MENU for double linked list: "<<endl<<"1. Insertion at start"<<endl<<"2. Insertion after a particular element"<<endl<<"3. Deletion"<<endl<<"4. Search for a node"<<endl<<"5. EXIT"<<endl;
        cout<<"Enter the option: ";
        cin>>menu;
        switch(menu){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>d;
                insertAtHead(head, tail, d);
                print(head);
                break;
            
        
            case 2:
                cout<<"Enter the element to be inserted: ";
                cin>>d;
                cout<<"Enter the element after which it has to be inserted: ";
                cin>>ele;
                insertAfter(head, tail, ele, d);
                print(head);
                break;

            case 3:
                cout<<"Enter the element to be deleted: ";
                cin>>d;
                deleteNode(d, head, tail);
                print(head);
                break;
            
            case 4:
                cout<<"Enter the element to be searched: ";
                cin>>d;
                search(head, d);
                break;

            case 5:
                cout<<"The program has been exited!"<<endl;
                break;
        }
    }while(menu<5);
}