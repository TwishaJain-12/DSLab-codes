//reverse LL in groups of k nodes
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){ 
        data = x; 
        next = NULL; 
    }
};

Node* reverseK(Node* head, int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;
    while(curr && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next)
        head->next = reverseK(next, k);

    return prev;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = reverseK(head, 2);
    printList(head);
}
