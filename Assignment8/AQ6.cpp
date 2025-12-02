//construct binary tree from postorder and inorder
#include<bits/stdc++.h>
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

int findPosition(int in[], int element, int n){
    for(int i=0; i<n; i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}

Node* construct(int in[], int post[], int &postIndex, int inStart, int inEnd, int n){
    //base case
    if(postIndex<0 || inStart>inEnd){
        return NULL;
    }

    int rootEle = post[postIndex--];
    Node* root = new Node(rootEle); //created the root node
    int inPos = findPosition(in, rootEle, n);

    //recursive calls for left and right
    //in case of postorder, the right subtree is built first
    root->right = construct(in, post, postIndex, inPos+1, inEnd, n);
    root->left = construct(in, post, postIndex, inStart, inPos-1, n);

    return root;
}

Node* buildTree(int in[], int post[], int n){
    int postIndex = n-1;
    Node* ans = construct(in, post, postIndex, 0, n-1, n);
    return ans;
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){ //purana level complete traverse ho chuka hain
            //level separator
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); 
//once a NULL comes, jo uss level ke lefts and rights hai wo queue me aa gye hain to unka NULL push kardenge
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
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

int main(){
    int n;
    cout<<"Enter the no. of nodes in the BINARY TREE: ";
    cin>>n;
    int in[n], post[n];
    cout<<endl<<"Enter the inorder traversal: ";
    for(int i=0; i<n; i++){
        cin>>in[i];
    }
    cout<<endl<<"Enter the postorder traversal: ";
    for(int i=0; i<n; i++){
        cin>>post[i];
    }

    Node* root = buildTree(in, post, n);
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"PREORDER TRAVERSAL: "<<endl;
    preorderTraversal(root);
    return 0;
}