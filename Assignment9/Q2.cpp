//dfs of a graph
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<int> adj[]){
    int vis[n] = {0};
    vis[0] = 1;
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> dfsTraversal = dfsOfGraph(n, adj);
    for(int x : dfsTraversal){
        cout << x << " ";
    }
    return 0;
}