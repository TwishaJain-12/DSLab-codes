//Sort an array of 0s, 1s and 2s
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array containing only 0s, 1s or 2s: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cnt0=0, cnt1=0, cnt2=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }

    int j=0, k=0;
    while(j<cnt0){
        arr[k++]=0;
        j++;
    }
    j=0;
    while(j<cnt1){
        arr[k++]=1;
        j++;
    }
    j=0;
    while(j<cnt2){
        arr[k++]=2;
        j++;
    }
    
    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"    ";
    }
    cout<<endl;
    return 0;
}