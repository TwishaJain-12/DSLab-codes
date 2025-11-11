#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x; 
        left=right=NULL; 
    }
};

class Tree {
public:
    Node* root;
    Tree(){ 
        root=NULL; 
    }

    Node* insert(Node* node, int x){
        if(!node) return new Node(x);
        if(x < node->data) node->left = insert(node->left, x);
        else node->right = insert(node->right, x);
        return node;
    }

    bool isBST(Node* node, Node* minN, Node* maxN){ //minN = minimum allowed value for a node, maxN = max allowed value for a node
        if(!node) return true;
        if((minN && node->data <= minN->data) || (maxN && node->data >= maxN->data)) return false;
        return isBST(node->left, minN, node) && isBST(node->right,node,maxN);
    }
};

int main(){
    Tree t;
    int n; 
    cin>>n;
    for(int i=0; i<n; i++){ 
        int x; 
        cin>>x; 
        t.root = t.insert(t.root, x); 
    }
    if(t.isBST(t.root,NULL,NULL)) cout<<"YES"; 
    else cout<<"NO";
}
