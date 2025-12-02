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

bool hasCycle(Node* head){
    unordered_set<Node*> st;
    while(head){
        if(st.count(head)) return true;
        st.insert(head);
        head = head->next;
    }
    return false;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=head->next; // forms the cycle

    cout<<(hasCycle(head) ? "true":"false");
    return 0;
}