#include<iostream>
using namespace std;
int main(){
    int n, input[20], output[20];
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>input[i];
    }
    int i, j;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(input[j]>input[i]){
                output[i]=input[j];
                break;
            }
        }
        if(j==n){
            output[i]=-1;
        }
    }

    cout<<"The INPUT ARRAY: ";
    for(int i=0; i<n; i++){
        cout<<input[i]<<"  ";
    }
    cout<<endl;

    cout<<"The OUTPUT ARRAY: ";
    for (int i=0; i<n; i++)
    {
        cout<<output[i]<<"  ";
    }
    cout<<endl;
    
}