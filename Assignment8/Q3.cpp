#include <iostream>
#include <algorithm>
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

Node* insert(Node* root, int d){
    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d>root->data){
        root->right = insert(root->right, d);
    }
    else{
        root->left = insert(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insert(root, data);
        cin>>data;
    }
}

void inorderTraversal(Node* root){
    Node* temp = root;
    if(temp==NULL){
        return;
    }

    inorderTraversal(temp->left);
    cout<<temp->data<<"  ";
    inorderTraversal(temp->right);
}

Node* minimumEle(Node* root){
    Node* temp = root;
    while(temp && temp->left) temp = temp->left;
    return temp;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root==NULL) return root;

    if(root->data == val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL && root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int minRight = minimumEle(root->right)->data;
            root->data = minRight;
            root->right = deleteFromBST(root->right, minRight);
            return root;
        }
    }
    else if(root->data>val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int maxDepth(Node* node){
    if(!node) return 0;
    return 1 + max(maxDepth(node->left), maxDepth(node->right));
}
    
int minDepth(Node* node){
    if(!node) return 0;
    return 1 + min(minDepth(node->left), minDepth(node->right));
}

int main(){
    Node* root = NULL;

    cout<<"Enter data for BST"<<endl;
    takeInput(root);

    inorderTraversal(root);

    cout<<"max depth: "<<maxDepth(root)<<endl;
    cout<<"min depth: "<<minDepth(root)<<endl;

    root = deleteFromBST(root, 50);
    inorderTraversal(root);
}