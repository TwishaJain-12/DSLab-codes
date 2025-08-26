//Bubble Sort: consecutive elements swap to sort the array
#include<iostream>
using namespace std;
int main(){
    int a[7]={64, 34, 25, 12, 22, 11, 90}, n=7, temp;
    for(int i=1; i<=n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
        
    }

    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<"  ";
    }

    return 0;
}