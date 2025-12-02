//right view
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int d){
            this->data = d;
            this->left = NULL; //previous
            this->right = NULL; //next
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

void solveView(Node* root, vector<int> &ans, int level){
    if(root==NULL) return;

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solveView(root->right, ans, level+1);
    solveView(root->left, ans, level+1);
}

vector<int> rightView(Node* root){
    vector<int> ans;
    solveView(root, ans, 0);
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    vector<int> RightView = rightView(root);
    for(int i=0; i<RightView.size(); i++){
        cout<<RightView[i]<<" ";
    }
    return 0;
}