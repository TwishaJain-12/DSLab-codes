#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[]){
    vis[node] = 1;
    for(int nbr : adj[node]){
        if(!vis[nbr]) dfs(nbr, vis, adj);
    }
}

int main(){
    int V,E;
    cin>>V>>E;

    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V,0);
    int count = 0;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            count++;
            dfs(i, vis, adj);
        }
    }

    cout<<count;
}
