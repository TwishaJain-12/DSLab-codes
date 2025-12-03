#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = grid[0][0];

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<>> pq;

    pq.push({grid[0][0], {0,0}});

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int cost = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;

        if(cost > dist[x][y]) continue;

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx>=0 && ny>=0 && nx<m && ny<n){
                if(dist[x][y] + grid[nx][ny] < dist[nx][ny]){
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    pq.push({dist[nx][ny], {nx,ny}});
                }
            }
        }
    }

    cout<<dist[m-1][n-1];
}
