#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int power;
    Node* next;
    
    Node(int data, int power){
        this->data = data;
        this->power = power;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        cout<<"The node with value "<<value<<" is deleted!"<<endl; 
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<"("<<temp->data<<","<<temp->power<<")  ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* add2LL(Node* head1, Node* head2){
    Node* dummy = new Node(0,0); //sum LL ka head
    Node* curr1 = head1;
    Node* curr2 = head2;
    Node* prev = dummy; //for insertion/joining
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->power < curr2->power){
            prev->next = curr2;
            prev = curr2;
            curr2 = curr2->next;
        }
        else if(curr1->power > curr2->power){
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
        }
        else{
            curr1->data = curr1->data + curr2->data;
            prev->next = curr1;
            prev = curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
    }

    if(curr1!=NULL){
        prev->next = curr1;
    }

    if(curr2!=NULL){
        prev->next = curr2;
    }

    return dummy->next;
}


int main(){
    // 1st polynomial: 5x^2+4x^1+2x^0
    Node* head1 = new Node(5,2); 
    head1->next = new Node(4,1);
    head1->next->next = new Node(2,0);
    
    // 2nd polynomial: -5x^1-5x^0
    Node* head2 = new Node(-5,1); 
    head2->next = new Node(-5,0);

    Node* head = add2LL(head1, head2);
    print(head);
    
}