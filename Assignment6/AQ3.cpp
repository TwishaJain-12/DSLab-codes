//reverse in groups of k nodes
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){ 
        data = x; 
        next = prev = NULL; 
    }
};

Node* reverseK(Node* head, int k){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;
    while(curr && count<k){
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        count++;
    }
    if(next){
        head->next = reverseK(next, k);
        head->next->prev = head;
    }
    return prev;
}

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    int n, k;
    cin>>n>>k;
    Node* head = NULL; 
    Node* tail = NULL;
    for(int i=0; i<n; i++){
        int x; 
        cin>>x;
        Node* temp = new Node(x);
        if(!head) 
            head = tail = temp;
        else{ 
            tail->next = temp; 
            temp->prev = tail; 
            tail = temp; 
        }
    }
    head = reverseK(head, k);
    print(head);
}
