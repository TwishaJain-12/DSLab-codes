//correct random pointer
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int x){ 
        data = x; 
        next = prev = random = NULL; 
    }
};

int main(){
    int n, wrong, correct;
    cin>>n;
    Node* head = NULL; 
    Node* tail = NULL;
    Node* arr[100];
    for(int i=0; i<n; i++){
        int x; 
        cin>>x;
        arr[i] = new Node(x);
        if(!head) head = tail = arr[i];
        else{ 
            tail->next = arr[i]; 
            arr[i]->prev = tail; 
            tail = arr[i]; 
        }
    }
    cin>>wrong>>correct;
    for(int i=0; i<n; i++)
        arr[i]->random = arr[i];  

    arr[wrong-1]->random = arr[correct-1];

    for(int i=0; i<n; i++) {
        cout<<arr[i]->data<<"->";
        if(arr[i]->random)
            cout<<arr[i]->random->data<<" ";
        else
            cout<<"NULL ";
    }
}
