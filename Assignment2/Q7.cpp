//(A[i], A[j]) : inversion if i < j but A[i]>A[j ]. WAP: count the number of inversions 
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int i=0, count=0;
    while(i<n-1){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                count++;
            }
        }
            i++;
    }

    cout<<"The number of inversions in the array are: "<<count<<endl;
    return 0;
}