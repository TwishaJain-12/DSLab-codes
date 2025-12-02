#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){ 
        data=d; 
        next=NULL; 
    }
};

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout << endl;
}

Node* push(Node* head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

int main(){
    // List1
    Node* head1 = NULL;
    head1 = push(head1, 20);
    head1 = push(head1, 4);
    head1 = push(head1, 15);
    head1 = push(head1, 10);

    // List2
    Node* head2 = NULL;
    head2 = push(head2, 10);
    head2 = push(head2, 2);
    head2 = push(head2, 4);
    head2 = push(head2, 8);

    unordered_set<int> s1, s2;

    Node* temp = head1;
    while(temp){
        s1.insert(temp->data);
        temp = temp->next;
    }

    temp = head2;
    while(temp){
        s2.insert(temp->data);
        temp = temp->next;
    }

    // Intersection
    cout << "Intersection List: ";
    for(int x:s1){
        if(s2.count(x)) cout<<x<<" ";
    }
    cout<<endl;

    // Union
    cout<<"Union List: ";
    unordered_set<int> uni = s1;
    for(int x:s2) uni.insert(x);

    for(int x:uni) cout<<x<<" ";
    return 0;
}