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
        if(x<node->data) node->left=insert(node->left,x);
        else node->right = insert(node->right, x);
        return node;
    }

    bool isLeaf(Node* n){ 
        return n && !n->left && !n->right;  //left right == NULL 
    }

    int sumLeft(Node* node){
        if(!node) return 0;
        int s = 0;
        if(isLeaf(node->left)) 
            s+= node->left->data;
        else 
            s+=sumLeft(node->left);

        s+=sumLeft(node->right);
        return s;
    }
};

int main(){
    Tree t;
    int n; 
    cin>>n;
    for(int i=0;i<n;i++){ 
        int x; 
        cin>>x; 
        t.root = t.insert(t.root, x); 
    }
    cout<<t.sumLeft(t.root);
}
