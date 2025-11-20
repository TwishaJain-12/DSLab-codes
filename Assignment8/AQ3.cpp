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

int height(Node* root){
    if(root==NULL)return 0; 
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right)+1;
    return ans;
}

int main(){
    Node* root = NULL;

    buildTree(root);
    cout<<"Height: "<<height(root)<<endl;
}