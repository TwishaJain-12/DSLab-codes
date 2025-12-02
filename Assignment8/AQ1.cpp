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

Node* buildTree(Node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<": ";
    root->left = buildTree(root->left);

    cout<<"Enter the data for inserting in right of "<<data<<": ";
    root->right = buildTree(root->right);

    return root;
}

bool isLeaf(Node* node){
    if(node==NULL) return false;
    if(node->left==NULL && node->right==NULL) return true;
    return false;
}

int SumLeftLeaves(Node* root){
    if(!root) return 0;
    int sum = 0;
    if(isLeaf(root->left)){
        sum = sum + root->left->data;
    }
    else{
        sum = sum + SumLeftLeaves(root->left);
    }
    sum = sum + SumLeftLeaves(root->right);
    return sum;
}

int main(){
    cout<<endl<<"Enter BST: ";
    Node* root = NULL;
    root = buildTree(root);

    cout<<"Sum of all left leaves of the BST is: "<<SumLeftLeaves(root)<<endl;

    return 0;
}
