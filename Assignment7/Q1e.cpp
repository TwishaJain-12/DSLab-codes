//quick sort
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;
    for(int k=start+1; k<=end; k++){
        if(arr[k]<=pivot){
            count++;
        }
    }

    int p_index = count + start;
    swap(arr[start], arr[p_index]); //pivot placed at right position

    int i = start;
    int j = end;
    while(i<p_index && j>p_index){

        while(arr[i]<=pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i<p_index && j>p_index){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        
    }
    return p_index;
}

void quickSort(int arr[], int start, int end){
    //base case
    if(start>=end) return;

    //partition the array
    int p_index = partition(arr, start, end); //partition the array from start to end & return the point of partition

    //recursion for the 2 halves
    quickSort(arr, start, p_index-1);
    quickSort(arr, p_index+1, end);
}

int main(){
    int arr[5] = {2,4,1,6,9};
    int n = 5;

    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

/*int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;
    for(int k=start+1; k<=end; k++){
        if(arr[k]<=pivot){
            count++;
        }
    }

    int p_index = count + start;
    swap(arr[start], arr[p_index]); //pivot placed at right position
    
    int i=start;
    int j=end;
    while(i!=p_index && j!=p_index){
        if(arr[i]>pivot && arr[j]<pivot){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if(arr[i]>pivot && arr[j]>pivot){
            j--;
        }
        else if(arr[i]<pivot && arr[j]<pivot){
            i++;
        }
        else{
            i++;
            j--;
        }
    }
    return p_index;
}*/