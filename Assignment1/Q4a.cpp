//Reverse the elements of an array 
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    //swapping till middle
    
    for(int i=0; i<n/2; i++){
        int temp=0;
        temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }

    //display reversed array
    cout<<endl<<"The reversed arrray is: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<"  ";
    }
}