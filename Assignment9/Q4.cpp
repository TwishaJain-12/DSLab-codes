//Dijkstra's Algorithm
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int V, int E, int source){
    //create adjacency list
    vector<pair<int,int>> adj[V];
    for(int i=0; i<E; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(V);
    for(int i=0; i<V; i++){
        dist[i] = INT_MAX;
    }

    set<pair<int,int>> st;

    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //fetch top node
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;
        //remove topNode from set
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour:adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                //if record found, erase it
                if(record!=st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                //push this in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
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
        edges.push_back({u,v,w});
    }

    vector<int> result = dijkstra(edges, V, E, 0);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}