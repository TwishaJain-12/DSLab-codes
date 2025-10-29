#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* lchild;
    Node* rchild;

    Node(int d){
        this->data = d;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

bool checkBST(Node* rnode){
    Node* temp = rnode;
    if(temp!=NULL){
        if(temp->lchild->data>temp->data){
            return false;
        }
        else{
            checkBST(temp->lchild);
        }

        if(temp->rchild->data<temp->data){
            return false;
        }
        else{
            checkBST(temp->rchild);
        }
    }
    else{
        return true;
    }
}

int main(){
    Node* rnode = new Node(10);
    Node* node1 = new Node(9);
    Node* node2 = new Node(4);
    Node* node3 = new Node(8);
    Node* node4 = new Node(17);
    Node* node5 = new Node(11);
    Node* node6 = new Node(21);
    Node* node7 = new Node(19);
    Node* node8 = new Node(25);

    rnode->lchild=node1;
    node1->lchild=node2;
    node2->rchild=node3;

    rnode->rchild=node4;
    node4->lchild=node5;
    node4->rchild=node6;
    node6->lchild=node7;
    node6->rchild=node8;

    bool flag = checkBST(rnode);
    if(flag==true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

}
