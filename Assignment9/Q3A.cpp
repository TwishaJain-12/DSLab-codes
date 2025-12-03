//Kruskal's Algorithm - Minimum Spanning Tree
#include<bits/stdc++.h>
using namespace std;

bool cmpWeights(vector<int>&a, vector<int>&b){
    return a[0]<b[0]; //sorts weight on basis of weight in ascending order
}

void makeSet(vector<int>&parent, vector<int>&rank, int V){
    for(int i=0; i<V; i++){
        parent[i] = i; 
        rank[i] = 0;
    }
}

int findParent(vector<int>&parent, int node){
    if(parent[node]==node) return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int>&parent, vector<int>&rank){
    //find parents of u and v
    int uparent = findParent(parent, u);
    int vparent = findParent(parent, v);

    if(rank[uparent]<rank[vparent]){
        parent[u] = v;
    }
    else if(rank[uparent]>rank[vparent]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>&edges, int V){
    sort(edges.begin(), edges.end(), cmpWeights); //to sort on basis of weight of the edges

    vector<int> parent(V);
    vector<int> rank(V);
    makeSet(parent, rank, V); //initialized

    int minWeight = 0;
    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent, edges[i][1]);
        int v = findParent(parent, edges[i][2]);
        int wt = edges[i][0];
        
        if(u!=v){
            minWeight+=wt;
            unionSet(edges[i][1], edges[i][2], parent, rank);
        }
    }
    return minWeight;
}

int main(){
    int V, E;
    cout<<"Enter the no. of vertices and edges: ";
    cin>>V>>E;

    vector<vector<int>> edges;
    int u, v, w;
    cout<<"Enter the edges along with weight: ";
    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }

    cout<<"Minimum weight: "<<minimumSpanningTree(edges, V);
    return 0;
}