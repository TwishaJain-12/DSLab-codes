#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,2,2,4,1};

    unordered_map<int,int> mp;
    for(int x:arr) mp[x]++;

    int ans=-1, freq=-1;

    for(auto &p : mp){
        int val = p.first;
        int f = p.second;

        if(f>freq || (f==freq && val>ans)){
            ans = val;
            freq = f;
        }
    }
    cout << ans;
    return 0;
}