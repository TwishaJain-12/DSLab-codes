#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr = {4,5,1,2,0,4};
    unordered_map<int,int> mp;

    for(int x : arr) mp[x]++;

    for(int x : arr){
        if(mp[x]==1){
            cout<<x;
            return 0;
        }
    }
    return 0;
}