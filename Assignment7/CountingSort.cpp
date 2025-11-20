#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n){
    int k = arr[0];
    for(int i=0; i<n; i++){
        k=max(k,arr[i]);
    }
    int cntArr[k+1];
    for(int i=0; i<=k; i++){
        cntArr[i]=0; //initialized to zero
    }

    for(int i=0; i<n; i++){
        cntArr[arr[i]]++; //cntArr created
    }

    //sum of previous elements -- cntArr updated
    for(int i=1; i<=k; i++){
        cntArr[i] = cntArr[i] + cntArr[i-1];
    }

    int ans[n];
    for(int i=n-1; i>=0; i--){
        ans[--cntArr[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = ans[i];
    }
}

int main(){
    int arr[] = {1,3,2,3,4,1,6,4,3};
    int n = 9;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    countingSort(arr, n);
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}