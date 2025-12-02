#include <bits/stdc++.h>
using namespace std;

bool equalArrays(vector<int>& a, vector<int>& b){
    if(a.size()!=b.size()) return false;

    unordered_map<int,int> mp;
    for(int x:a) mp[x]++;
    for(int x:b){
        if(--mp[x]<0) return false;
    }
    return true;
}

int main(){
    vector<int> a={1,2,5,4,0};
    vector<int> b={2,4,5,0,1};

    cout<<(equalArrays(a,b) ? "true":"false");
    return 0;
}