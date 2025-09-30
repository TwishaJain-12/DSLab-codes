//Selection sort
#include<iostream>
using namespace std;
void selection_sort(int arr[], int n){
    for(int i=0; i<=n-2; i++){
        int min=i;
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        //swap arr[i] and arr[min]
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    selection_sort(arr, n);

    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"    ";
    }
    cout<<endl;
    return 0;
}