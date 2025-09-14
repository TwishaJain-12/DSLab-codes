#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[20], result[20], n;
    stack<int>st;
    cout<<"Enter the no. of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
        result[i]=-1; //initialised to -1
    }
    for(int i=n-1; i>=0; i--){
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }

    cout<<"The INPUT ARRAY: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    cout<<"The OUTPUT ARRAY: ";
    for (int i=0; i<n; i++)
    {
        cout<<result[i]<<"  ";
    }
    cout<<endl;

}