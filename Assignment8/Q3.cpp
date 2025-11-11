#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){ data=x; left=right=NULL; }
};

class BST {
public:
    Node* root;
    BST(){ 
        root=NULL; 
    }

    Node* insert(Node* node, int key){
        if(!node) return new Node(key);

        if(key<node->data) 
            node->left = insert(node->left,key);
        else if(key>node->data) 
            node->right = insert(node->right,key);
        return node;
    }

    Node* minNode(Node* node){
        while(node->left) 
            node=node->left;

        return node;
    }

    Node* deleteNode(Node* node, int key){
        if(!node) return node;

        if(key<node->data) 
            node->left = deleteNode(node->left, key);
        else if(key>node->data) 
            node->right = deleteNode(node->right, key);
        else{
            if(!node->left) return node->right;
            else if(!node->right) return node->left;
            Node* t = minNode(node->right);
            node->data = t->data;
            node->right = deleteNode(node->right, t->data);
        }
        return node;
    }

    int maxDepth(Node* node){
        if(!node) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }
    
    int minDepth(Node* node){
        if(!node) return 0;
        return 1 + min(minDepth(node->left), minDepth(node->right));
    }
};

int main(){
    BST b;
    int n; cin>>n;
    for(int i=0;i<n;i++){ 
        int x; 
        cin>>x; 
        b.root=b.insert(b.root,x); 
    }
    int del; 
    cin>>del;
    b.root=b.deleteNode(b.root,del);
    cout<<"MaxDepth "<<b.maxDepth(b.root)<<endl;
    cout<<"MinDepth "<<b.minDepth(b.root)<<endl;;
}