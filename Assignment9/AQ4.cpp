#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j){
    int m = grid.size();
    int n = grid[0].size();

    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0')
        return;

    grid[i][j]='0';

    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<char>> grid(m, vector<char>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                count++;
                dfs(grid, i, j);
            }
        }
    }
    cout<<count;
}
