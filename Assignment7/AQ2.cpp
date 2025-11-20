// int n; 
//     cout<<"Enter the number of elements: ";
//     cin>>n;
//     vector<int> a;
//     cout<<"Enter the elements of the array: ";
//     for(int i=0; i<n; i++){
//         int inputVal;
//         cin>>inputVal;
//         a.push_back(inputVal);
//     }
#include<bits/stdc++.h>
using namespace std;

vector<int> freq; //global freq vector

bool compareFreq(int a, int b){
    if(freq[a]==freq[b]) 
        return a > b;
    return freq[a]>freq[b];
}

vector<int> topKfrequent( vector<int>& arr, int k){
    int maxEle = *max_element(arr.begin(), arr.end());

    freq.assign(maxEle+1, 0); //resets the freq array with size maxEle+1 and each ele=0

    for(int i=0; i<arr.size(); i++){
        freq[arr[i]]++;
    }

    vector<int> numbers;
    for(int i=0; i<=maxEle; i++){
        if(freq[i]>0){
            numbers.push_back(i);
        }
    }

    //now time to sort the numbers on basis of frequency
    sort(numbers.begin(), numbers.end(), compareFreq);

    //a vector for final answer
    vector<int> ans;
    for(int i=0; i<k; i++){
        ans.push_back(numbers[i]);
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];  
    }

    int k;
    cout<<"Enter k:";
    cin>>k;

    vector<int> result = topKfrequent(arr, k);
    for(int i=0; i<k; i++){
        cout<<result[i]<<" ";
    }
    return 0;
}