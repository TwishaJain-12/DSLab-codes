//insertion sort
#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i;
        while(j>0 && arr[j-1]>temp){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}

int main(){
    int n; 
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    insertionSort(arr, n);

    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"    ";
    }
    cout<<endl;
    return 0;
}