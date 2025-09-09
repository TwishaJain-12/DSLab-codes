//arr A; smallest element to A[i] ->B[j] where j<i => A[i] ke left me small ele
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> st1;
    stack <int> st2;
    int n;
    int j=0;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The nearest smallest element for each member of input array is: ";
    while(j<n){
        st2.push(arr[j]);
        if(st1.empty()){
            cout<<"-1"<<"  ";
            st2.pop();
            st1.push(arr[j]);
        }
        else if(st2.top()>st1.top()){
            cout<<st1.top()<<"  ";
        }
        else{
            st2.pop();
            st1.push(arr[j]);
            cout<<"-1"<<" ";
        }
        j++;
    }

}