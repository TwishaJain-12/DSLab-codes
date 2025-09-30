#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        cout<<"The node with value "<<value<<" is deleted!"<<endl; 
    }
};

    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"   ";
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
    int k;
    cout<<"Enter the integer for rotation: ";
    cin>>k;

    tail->next = head; //circular linked list
    Node* temp = head;
    int cnt=1;
    while(cnt<k){
        temp = temp->next;
        cnt++;
    }
    head = temp->next; //updated head
    tail = temp;
    temp->next = NULL; //end of LL
    cout<<"Rotated LL: ";
    print(head);
}