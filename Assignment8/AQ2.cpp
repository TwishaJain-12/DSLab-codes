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

vector<Node*> build(int start, int end){
    vector<Node*> result;

    if(start>end){
        result.push_back(NULL);
        return result;
    }

    //now we choose every number as root
    for(int i=start; i<=end; i++){
        vector<Node*> leftTrees = build(start, i-1);
        vector<Node*> rightTrees = build(i+1, end);

        //till now i have built all possible left and right subtrees for i
        //now we need to combine each combination to form a unique bst
        for(auto left: leftTrees){
            for(auto right: rightTrees){
                Node* root = new Node(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
}

vector<Node*> generateTrees(int n){
    if(n==0) return {};
    return build(1, n);
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
    cout<<"Enter n: ";
    cin>>n;

    vector<Node*> uniqueBSTs = generateTrees(n); 
    cout<<"No. of unique BSTS generated: "<<uniqueBSTs.size()<<endl;

    int idx = 1;
    for(auto root: uniqueBSTs){
        cout<<"Tree "<<idx++<<" :"<<endl;
        preorderTraversal(root);
        cout<<endl;
    }
    return 0;
}