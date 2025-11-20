//merge sort
#include<bits/stdc++.h>
using namespace std;

void mergeArr(vector<int> &arr, int low, int mid, int high){
    vector<int> temp = {};
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low>=high) return;

    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    mergeArr(arr, low, mid, high);
}

void mergesortfun(vector<int> &arr, int n){
    mergeSort(arr, 0, n-1);
}

int main(){
    vector<int> arr = {3, 2, 4, 1, 3};
    mergesortfun(arr, 5);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

