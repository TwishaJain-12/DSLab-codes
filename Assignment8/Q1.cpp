#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
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

void preorderTraversal(Node* root){
    Node* temp = root;
    if(temp==NULL){
        return;
    }

    cout<<temp->data<<"  ";
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);

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

void postorderTraversal(Node* root){
    Node* temp = root;
    if(temp==NULL){
        return;
    }

    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout<<temp->data<<"  ";
}

int main(){
    Node* root = NULL;

    //creating a tree
    root = buildTree(root); //8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1

    //preorder traversal
    cout<<endl<<"Preorder Traversal: ";
    preorderTraversal(root); 

    //inorder traversal
    cout<<endl<<"Inorder Traversal: ";
    inorderTraversal(root); 

    //postorder traversal
    cout<<endl<<"Postorder Traversal: ";
    postorderTraversal(root); 
    
    return 0;
}
