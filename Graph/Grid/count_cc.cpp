#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 10e5

int n , m ;
bool visited[1001][1001] ;
int grid[1001][1001];


bool isValid(int x,int y){
    if(x<1 || x>n || y<1 || y>m) return false;
    if(visited[x][y]==true || grid[x][y]==0) return false;
    return true;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void DFS(int x,int y){
    visited[x][y] = true;
    for(int i=0 ; i<4 ;i++){
        if(isValid(x + dx[i] , y+dy[i])) 
            DFS(x+dx[i],y+dy[i]);
    }
}

int32_t main(){
    // n--> rows , m-->columns
    cin>>n>>m;
    for(int i=1 ; i<=n;i++){
        for(int j=1; j<=m;j++){
            cin>>grid[i][j];
        }
    }

    int cc=0;
    for(int i=1;i<=n ; i++){
        for(int j=1 ; j<=m ;j++){
            if(visited[i][j]==false && grid[i][j]==1){
                DFS(i,j) ;
                cc++;
            }
        }
    }
    
    cout<<cc<<endl;
    return 0;
}