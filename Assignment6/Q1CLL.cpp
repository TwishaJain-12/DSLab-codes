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

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail==NULL){
        cout<<"The list is empty!"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
            if(curr==tail->next){
                cout<<"The value was not found in the Linked List!"<<endl;
                return;
            }
        }
        prev->next = curr->next;
        //one node
        if(curr==prev){
            tail == NULL;
        }
    
        //2 nodes
        else if(curr==tail){
            tail = prev;
        }
    
        curr->next = NULL;
        delete curr;
    }
}

void search(Node* &tail, int value){
    Node* curr = tail;
    while(curr->data!=value){
        curr=curr->next;
        if(curr==tail){
            cout<<"The value was not found in the Linked List!"<<endl;
            return;
        }
    }
    cout<<"The value "<< curr->data<< " was found!"<<endl;
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
    cout<<endl;
}

int main(){
    Node* tail = NULL;
    int menu, d, ele;
    do{
        cout<<"MENU for circular linked list: "<<endl<<"1. Insertion"<<endl<<"2. Deletion"<<endl<<"3. Search for a node"<<endl<<"4. EXIT"<<endl;
        cout<<"Enter the option: ";
        cin>>menu;
        switch(menu){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>d;
                cout<<"Enter the element after which it has to be inserted: ";
                cin>>ele;
                insertNode(tail, ele, d);
                print(tail);
                break;
            
            case 2:
                cout<<"Enter the element to be deleted: ";
                cin>>d;
                deleteNode(tail, d);
                print(tail);
                break;
            
            case 3:
                cout<<"Enter the element to be searched: ";
                cin>>d;
                search(tail, d);
                break;

            case 4:
                cout<<"The program has been exited!"<<endl;
                break;
        }
    }while(menu<4);
}