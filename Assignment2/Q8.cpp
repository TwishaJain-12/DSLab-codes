//Write a program to count the total number of distinct elements in an array of length n
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int a[n], d[n];
    cout<<"Enter the array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    d[0]=a[0];
    int k=1, count=1;
    for(int i=1; i<n; i++){
        int flag=0;
        for(int j=0; j<k; j++){
            if(a[i]==d[j]){
                flag=1;
            }
        }
        if(flag==0){
            d[k]=a[i];
            k++;
            count++;
        }
    }
    cout<<"The number of distinct elements in the array are: "<<count<<endl;
    return 0;
}