//construct binary tree from preorder and inorder traversal
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

Node* construct(int in[], int pre[], int &preIndex, int inStart, int inEnd, int n){
    //base case
    if(preIndex>=n || inStart>inEnd){
        return NULL;
    }

    int rootEle = pre[preIndex++];
    Node* root = new Node(rootEle); //created the root node
    int inPos = findPosition(in, rootEle, n);

    //recursive calls for left and right
    root->left = construct(in, pre, preIndex, inStart, inPos-1, n);
    root->right = construct(in, pre, preIndex, inPos+1, inEnd, n);

    return root;
}

Node* buildTree(int in[], int pre[], int n){
    int preIndex = 0;
    Node* ans = construct(in, pre, preIndex, 0, n-1, n);
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
    int n;
    cout<<"Enter the no. of nodes in the BINARY TREE: ";
    cin>>n;
    int in[n], pre[n];
    cout<<endl<<"Enter the inorder traversal: ";
    for(int i=0; i<n; i++){
        cin>>in[i];
    }
    cout<<endl<<"Enter the preorder traversal: ";
    for(int i=0; i<n; i++){
        cin>>pre[i];
    }

    Node* root = buildTree(in, pre, n);
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"POSTORDER TRAVERSAL: "<<endl;
    postorderTraversal(root);
    return 0;
}