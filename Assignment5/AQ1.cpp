//find the intersection of 2 LLs
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x) { 
        data = x; 
        next = NULL; 
    }
};

int getLength(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersection(Node* head1, Node* head2){
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);
    if(len1 > len2){
        while(diff--){
            head1 = head1->next;
        }
    }
    else{
        while(diff--){
            head2 = head2->next;
        }
    }

    while(head1 && head2){
        if(head1 == head2) return head1;

        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main() {
    Node* common = new Node(8);
    common->next = new Node(10);
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common;
    Node* head2 = new Node(4);
    head2->next = new Node(7);
    head2->next->next = common;
    Node* inter = getIntersection(head1, head2);
    if(inter){
        cout<<inter->data;
    }
}
