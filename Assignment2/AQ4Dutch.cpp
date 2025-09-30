#include<iostream>
using namespace std;
void sortDutch(int arr[], int n){
    int low=0; 
    int mid=0; 
    int high = n-1;
    int temp=0;
    while(mid<=high){
        if(arr[mid]==0){
            //swap a[low] and a[mid]
            temp = arr[mid];
            arr[mid]=arr[low];
            arr[low]=temp;
    
            low++;
            mid++;
        }
    
        else if(arr[mid]==2){
            //swap a[high] and a[mid]
            temp=arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            
            high--;
        }

        else{
            mid++;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array containing only 0s, 1s or 2s: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortDutch(arr, n);
    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"    ";
    }
    return 0;
}