//Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements. 
#include<iostream>
using namespace std;
int main(){
    //input array
    int n, k=1;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int b[n]; //new array
    b[0]=a[0];
    for(int i=1; i<n; i++){
        int flag=0;
        for(int j=0; j<k; j++){
            if(a[i]==b[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            b[k]=a[i];
            k++;
        }
    }

    //display array
    cout<<endl<<"The updated array is: ";
    for(int i=0; i<k; i++){
        cout<<b[i]<<" ";
    }
    return 0;
    
}