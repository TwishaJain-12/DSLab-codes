//Find Missing Number in sorted array from 1 - n-1 integers using BINARY SEARCH
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
    int start=0, end=n-1, mid;
    while(start<=end){
        mid=(start+end)/2;
        if(a[mid]==mid+2){
            if(a[mid-1]==mid){
                cout<<"The missing number is: "<<mid+1<<endl;
                break;
            }
            else{
                end = mid-1;
            }
        }
        else{
            start = mid+1;
        }
    }
    return 0;
}