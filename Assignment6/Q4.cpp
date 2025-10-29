//check whether DLL of characters is palindrome or not
#include<iostream>
using namespace std;
class Node{
    public: 
    char data;
    Node* next;
    Node* prev;

    //constructor
    Node(char d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

    //destrcutor
    ~Node(){
        char value = this->data;
        cout<<"Memory freed for node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, char d){
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

void insertAtTail(Node* &head, Node* &tail, char d){
    Node* newNode = new Node(d);
    if(tail==NULL){
        tail = newNode;
        head = newNode;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteNode(char ivalue, Node* &head, Node* &tail){
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

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp = temp->next; 
    }
    cout<<endl;
}

bool checkPalindrome(Node* head, Node* tail, int size){
    Node* front = head; //traversal from head
    Node* rear = tail; //traversal from tail
    for(int i=1; i<=size/2; i++){
        if(front->data == rear->data){
            front = front-> next;
            rear = rear-> prev;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int menu, size=0;
    char d;
    do{
        cout<<"MENU for double linked list: "<<endl<<"1. Insertion at start"<<endl<<"2. Insertion at end"<<endl<<"3. Deletion"<<endl<<"4. EXIT"<<endl;
        cout<<"Enter the option: ";
        cin>>menu;
        switch(menu){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>d;
                insertAtHead(head, tail, d);
                print(head);
                size++;
                break;

            case 2:
                cout<<"Enter the element to be inserted: ";
                cin>>d;
                insertAtTail(head, tail, d);
                print(head);
                size++;
                break;
            
            case 3:
                cout<<"Enter the element to be deleted: ";
                cin>>d;
                deleteNode(d, head, tail);
                print(head);
                size--;
                break;
            
            case 4:
                cout<<"The program has been exited!"<<endl;
                break;
        }
    }while(menu<4);

    cout<<endl<<"Checking if the Double Linked list is palindrome or not.... ";
    if(checkPalindrome(head, tail, size)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}