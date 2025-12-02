#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){ 
        data=d; 
        left=right=NULL; 
    }
};

bool check(Node* root, unordered_set<int>& s){
    if(!root) return false;

    if(s.count(root->data)) return true;
    s.insert(root->data);

    return check(root->left, s) || check(root->right, s);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(20);   // duplicate value

    unordered_set<int> s;
    cout<<(check(root, s) ? "Duplicates Found":"No Duplicates");
    return 0;
}