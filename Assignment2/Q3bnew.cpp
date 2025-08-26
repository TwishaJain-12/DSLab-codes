#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int a[n-1];
    cout<<"Enter the sorted array: ";
    for(int i=0; i<n-1; i++){
        cin>>a[i];
    }

    int start=0, end=n-1, mid, ans; 
    while(start <= end){
        mid = (start+end)/2;
        if(a[mid] == mid+1){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    cout<<"The missing number is: "<< start+1 << endl;
    return 0;
}
