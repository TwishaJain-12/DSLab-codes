//Find Missing Number in sorted array from 1 - n-1 integers using LINEAR SEARCH
#include<iostream>
using namespace std;
int main(){
    int n, mn;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the sorted array having distinct integers: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        if(a[i]==i+2){
            mn= a[i]-1;
            break;
        }
    }

    cout<<"The missing number is: "<<mn<<endl;
    return 0;
}