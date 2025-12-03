#include <bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;

    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> vis(V,0);
    pq.push({0,0}); // weight, node

    int mstWeight = 0;

    while(!pq.empty()){
        auto[wt,node]= pq.top(); pq.pop();

        if(vis[node]) continue;
        vis[node]=1;
        mstWeight += wt;

        for(auto &p:adj[node]){
            int nbr=p.first, w=p.second;
            if(!vis[nbr]) pq.push({w,nbr});
        }
    }

    cout<<"MST Weight = "<<mstWeight;
}
