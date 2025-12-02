#include <bits/stdc++.h>
using namespace std;

bool pairSum(vector<int>& arr, int target){
    unordered_set<int> s;

    for(int x:arr){
        if(s.count(target - x)) return true;
        s.insert(x);
    }
    return false;
}

int main(){
    vector<int> arr={0,-1,2,-3,1};
    int target=-2;

    cout<<(pairSum(arr, target) ? "true":"false");
    return 0;
}