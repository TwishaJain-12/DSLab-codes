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

Node* maximumEle(Node* root){
    Node* temp = root;
    while(temp && temp->left) temp = temp->left;
    return temp;
}

class BST {
public:
    Node* root;
    BST(){ 
        root=NULL; 
    }

    Node* insert(Node* node, int key){
        if(!node) return new Node(key);
        if(key < node->data) node->left = insert(node->left, key);
        else if(key > node->data) node->right = insert(node->right, key);
        return node;
    }

    Node* searchRec(Node* node, int key){
        if(!node || node->data==key) return node;

        if(key<node->data) return searchRec(node->left, key);
        else return searchRec(node->right, key);
    }

    Node* searchNonRec(Node* node, int key){
        while(node && node->data!=key){
            if(key < node->data) node = node->left;
            else node = node->right;
        }
        return node;
    }

    Node* minNode(Node* node){
        while(node && node->left) node = node->left;
        return node; 
    }

    Node* maxNode(Node* node){
        while(node && node->right) node = node->right;
        return node;
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
};

int main(){
    BST b;
    int n; 
    cin>>n;
    for(int i=0;i<n;i++){ 
        int x; 
        cin>>x; 
        b.root = b.insert(b.root, x); 
    }

    int key; 
    cin>>key;
    Node* x = b.searchRec(b.root, key);
    if(x) cout<<"Found"<<endl; 
    else cout<<"Not Found"<<endl;

    Node* mn = b.minNode(b.root); 
    Node* mx = b.maxNode(b.root);
    cout<<"Min "<<mn->data<<endl<<"Max "<<mx->data<<endl;

    Node* s = b.inorderSuccessor(b.root, x); 
    if(s) cout<<"Successor "<<s->data<<endl; 
    else cout<<"No Successor"<<endl;

    Node* p = b.inorderPredecessor(b.root, x);
    if(p) cout<<"Predecessor "<<p->data; 
    else cout<<"No Predecessor";
}

int main(){
    Node* root = NULL;

    cout<<"Enter data for BST"<<endl;
    takeInput(root);

    
}
