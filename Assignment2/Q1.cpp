//Binary Search Algo
#include<iostream>
using namespace std;
int main(){
    int n, ele;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array(sorted): ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter the element to be searched: ";
    cin>>ele;

    int start=0, end=n-1, mid;
    while(start<=end){
        mid = (start + end)/2;
        if(arr[mid]==ele){
            cout<<"The element was found at position "<<mid+1<<endl;
            break;
        }
        if(arr[mid]<ele){
            start = mid+1;
        }
        if(arr[mid]>ele){
            end = mid-1;
        }
    }
    if(start>end){
        cout<<"The element was not found";
    }

    return 0;
}