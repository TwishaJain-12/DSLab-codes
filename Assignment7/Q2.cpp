//Selection sort
#include<iostream>
using namespace std;
void selection_sort(int arr[], int n){
    for(int i=0; i<n/2; i++){
        int min=i;
        int max=i;
        for(int j=i; j<=n-1-i; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
            if(arr[j]>arr[max]){
                max = j;
            }
        }
        //swap arr[i] and arr[min]
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        if(max==i){
            //update max
            max = min; //kyunki swap to min wale ki jagah par ho gya tha 
        }

        //swap arr[n-1-i] and arr[max]
        temp = arr[n-1-i];
        arr[n-1-i] = arr[max];
        arr[max] = temp;
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