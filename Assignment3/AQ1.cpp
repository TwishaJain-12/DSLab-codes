//arr A; nearest smallest element to A[i] ->B[j] where j<i => A[i] ke left me small ele
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> st;
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
        if(st.empty()){
            cout<<"-1  ";
            st.push(arr[j++]);
        }
        else{
            if(arr[j]>st.top()){
                cout<<st.top()<<"  ";
                st.push(arr[j++]);
            }
            else{
                st.pop();
            }
        }
    }
    return 0;
}