//sort even-placed in increasing order and odd-placed in decreasing order
#include <bits/stdc++.h>
using namespace std;
void sortEvenOdd(vector<int> &arr){
    vector<int> even;
    vector<int> odd;

    for(int i=0; i<arr.size(); i++){
        if(i%2==0){
            even.push_back(arr[i]);
        }
        else{
            odd.push_back(arr[i]);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());

    int k=0;
    for(int i=0; i<even.size(); i++){
        arr[k++] = even[i];
    }
    for(int i=0; i<odd.size(); i++){
        arr[k++] = odd[i];
    }
}

void sortApp2(vector<int> &arr){
    //no need of extra space
    int n = arr.size();
    int i=1, j;
    if(n%2==0){ //last element is odd placed
        j = n-2;
    }
    else{ //even-plced
        j = n-1;
    }
    while(i<j){
        swap(arr[i], arr[j]);
        i+=2;
        j-=2;
    }

    // Sort first half in increasing
    sort(arr.begin(), arr.begin() + (n + 1) / 2);

    // Sort second half in decreasing
    sort(arr.begin() + (n + 1) / 2, arr.end(), greater<int>());

}

int main(){
    int n; 
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> a;
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        int inputVal;
        cin>>inputVal;
        a.push_back(inputVal);
    }
    sortApp2(a);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}