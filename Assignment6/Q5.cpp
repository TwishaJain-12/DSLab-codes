//check if a linked list is Circular Linked List or not
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

bool isCircular(Node* head){
    //approach 1: tail->next == temp (where we started)
    // Node* temp = head -> next;
    // while(temp!=NULL){
    //     if(temp->next == head){
    //         return true;
    //     }
    //     temp = temp->next;
    // }
    // return false;

    //----APPROACH 2: Slow & Fast Pointers---
    Node* slowptr = head->next;
    Node* fastptr = head->next->next;
    while(fastptr!=NULL){
        if(slowptr==fastptr){
            return true;
        }
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    // Making linked list circular
    head->next->next->next->next = head;

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}