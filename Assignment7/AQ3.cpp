//maximum sum combinations
#include <bits/stdc++.h>
using namespace std;
vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
    vector<int> sumArr;
    int an = a.size();
    int bn = b.size();
    for(int i=0; i<an; i++){
        for(int j=0; j<bn; j++){
            sumArr.push_back(a[i]+b[j]);
        }
    }
    sort(sumArr.begin(), sumArr.end(), greater<int>());
    if(sumArr.size() > k) {
        sumArr.resize(k);   // keep only first k elements
    }
    
    return sumArr;   // always return
}

int main(){
    int n; 
    cout<<"Enter the number of elements in both arrays: ";
    cin>>n;
    vector<int> a, b;
    cout<<"Enter the elements of the array 1: ";
    for(int i=0; i<n; i++){
        int inputVal;
        cin>>inputVal;
        a.push_back(inputVal);
    }
    cout<<"Enter the elements of the array 2: ";
    for(int i=0; i<n; i++){
        int inputVal;
        cin>>inputVal;
        b.push_back(inputVal);
    }
    cout<<"Enter k: ";
    int k;
    cin>>k;

    vector<int> MaxSum = topKSumPairs(a, b, k);
    for(int i=0; i<k; i++){
        cout<<MaxSum[i]<<" ";
    }
    return 0;
}