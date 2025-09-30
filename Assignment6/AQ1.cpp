#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data= data;
        this->next = NULL;
    }
};

void splitList(Node* &head, Node* &head1, Node* &head2){
    Node* slow = head;
    Node* fast = head;

    if(head==NULL){
    cout<<"The List is Empty! No spliting!"<<endl;
    return;
    }

    while(fast->next!=head && fast->next->next!=head){
        slow = slow->next;
        fast = fast->next->next;
    }

    //even case
    if(fast->next->next == head){
        fast = fast->next;
    }

    head1 = head;
    head2 = slow->next;

    //circular condition for half2
    fast->next = slow->next;

    //for half1
    slow->next = head;
}

void printList(Node* head){
    Node* temp=head;
    do{
        cout<<temp->data<<"  ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

int main(){
    Node *head = new Node(1); 
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    // Created linked list will be 1->2->3->4
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    splitList(head, head1, head2);
    printList(head1); 
    printList(head2);
    
    return 0; 
}