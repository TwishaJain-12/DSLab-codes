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
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
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

void insertAtPos(Node* &head, Node* &tail, int ivalue, int d){
    Node* temp=head; //traverse
    while(temp->next!=NULL){
        if(ivalue==temp->data){
            Node* newNode = new Node(d);
            newNode->next = temp->next;
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

void search(Node* &head, int ivalue){
    Node* temp = head;
    int cnt=1;
    while(temp->next != NULL){
        if(ivalue== temp->data){
            cout<<"The node was found at "<<cnt<<" position (from head)"<<endl;
            break;
        }
        temp=temp->next;
        cnt++;
    }
    cout<<"Element not found!"<<endl;
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

    int menu, ivalue, d;
    do{
        cout<<"Menu for single linked list: "<<endl;
        cout<<"1. Insertion at the beginning."<<endl;
        cout<<"2. Insertion at the end."<<endl;
        cout<<"3. Insertion in between (after a node)."<<endl;
        cout<<"4. Deletion from the beginning"<<endl;
        cout<<"5. Deletion from the end."<<endl;
        cout<<"6. Deletion of a specific node, say 'Delete Node 60')."<<endl;
        cout<<"7. Search for a node and display its position from head."<<endl;
        cout<<"8. Display all the node values."<<endl;
        cout<<"9. Exit"<<endl;
        cout<<endl<<"Enter the option number: ";
        cin>>menu;

        switch(menu){
            case 1:
                cout<<"Enter the value of node to be inserted: ";
                cin>>d;
                insertAtHead(head, tail, d);
            break;
            
            case 2:
                cout<<"Enter the value of node to be inserted: ";
                cin>>d;
                insertAtTail(head, tail, d);
            break;

            case 3:
                cout<<"Enter the value of node to be inserted: ";
                cin>>d;
                cout<<"Enter the node after which it has to be inserted: ";
                cin>>ivalue;
                insertAtPos(head, tail, ivalue, d);
            break;

            case 4:
                deleteNode(head->data, head, tail);
            break;
            
            case 5:
                deleteNode(tail->data, head, tail);
            break;

            case 6:
                cout<<"Enter the node's value to be deleted: ";
                cin>>ivalue;
                deleteNode(ivalue, head, tail);
            break;

            case 7:
                cout<<"Enter the value to be searched: ";
                cin>>ivalue;
                search(head, ivalue);
            break;

            case 8:
                print(head);
            break;

            case 9:
                cout<<"The program has been exited!"<<endl;
            break;

            default:
                cout<<"Error!"<<endl;
            break;
        }
    }while(menu<9);

    return 0;
}