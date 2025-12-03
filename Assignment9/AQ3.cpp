#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K,E;
    cin>>N>>K>>E;

    vector<vector<pair<int,int>>> adj(N+1);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,K});

    while(!pq.empty()){
        auto [d,node] = pq.top(); pq.pop();
        if(d > dist[node]) continue;

        for(auto &p : adj[node]){
            int nbr=p.first, wt=p.second;
            if(dist[node] + wt < dist[nbr]){
                dist[nbr] = dist[node] + wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    int ans = *max_element(dist.begin()+1, dist.end());
    cout<<(ans == INT_MAX ? -1 : ans);
}
