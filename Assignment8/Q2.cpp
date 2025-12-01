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

bool searchRec(Node* root, int x) {
    if(root==NULL) return false;

    if(root->data == x) return true;
    else if(root->data>x) return searchRec(root->left, x);
    else return searchRec(root->right, x);
}

bool searchNonRec(Node* root, int x) {
    Node* temp = root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

Node* minimumEle(Node* root){
    Node* temp = root;
    while(temp && temp->left) temp = temp->left;
    return temp;
}

Node* maximumEle(Node* root){
    Node* temp = root;
    while(temp && temp->right) temp = temp->right;
    return temp;
}

Node* inorderSuccessor(Node* node, Node* x){
    Node* succ = NULL;
    while(node){
        if(x->data < node->data){ 
            succ=node; 
            node=node->left; 
        }
        else node = node->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* node, Node* x){
    Node* pred = NULL;
    while(node){
        if(x->data>node->data){ 
            pred=node; 
            node=node->right; 
        }
        else node=node->left;
    }
    return pred;
}

int main(){
    Node* root = NULL;

    cout<<"Enter data for BST"<<endl;
    takeInput(root);

    // Node* x = new Node(22);
    // Node* succ = inorderSuccessor(root, x);
    // cout<<succ->data;

    // Node* x = new Node(22);
    // Node* pred = inorderPredecessor(root, x);
    // cout<<pred->data;
    
    Node* max = maximumEle(root);
    Node* min = minimumEle(root);

    cout<<"Max "<<max->data<<" Min "<<min->data<<endl;

    if(searchRec(root, 66)) cout<<"66 found";
    else cout<<"66 not found";

    if(searchNonRec(root, 14)) cout<<"14 found"<<endl;
    else cout<<"14 not found"<<endl;


}
