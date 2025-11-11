//remove loop - 2 pointer 
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ 
        data = x; 
        next = NULL; 
    }
};

void removeLoop(Node* head){
    Node *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if(slow != fast) return;

    slow = head;
    if(slow == fast){
        while (fast->next != slow)
            fast = fast->next;
    } 
    else{
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    removeLoop(head);
    printList(head);
}
